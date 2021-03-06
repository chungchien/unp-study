# config-ix.cmake --- 檢查系統配置

# 檢查頭文件是否存在
include(CheckIncludeFiles)
check_include_files(strings.h HAVE_STRINGS_H)
check_include_files(string.h HAVE_STRING_H)
check_include_files(netinet/in.h HAVE_NETINET_IN_H)
check_include_files(arpa/inet.h HAVE_ARPA_INET_H)
check_include_files(netinet/sctp.h HAVE_NETINET_SCTP_H)
check_include_files(netinet/tcp.h HAVE_NETINET_TCP_H)
check_include_files(netinet/udp.h HAVE_NETINET_UDP_H)

# 檢查函數是否存在
include(CheckFunctionExists)
check_function_exists(bzero HAVE_BZERO)
check_function_exists(inet_pton HAVE_INET_PTON)
check_function_exists(inet_ntop HAVE_INET_NTOP)
check_function_exists(snprintf HAVE_SNPRINTF)
check_function_exists(vsnprintf HAVE_VSNPRINTF)

# 檢查符號是否定義
include(CheckSymbolExists)
check_symbol_exists(INET_ADDRSTRLEN netinet/in.h HAVE_INET_ADDRSTRLEN)
check_symbol_exists(INET6_ADDRSTRLEN netinet/in.h HAVE_INET6_ADDRSTRLEN)

# include(CheckPrototypeExists)
# check_prototype_exists(signal signal.h HAVE_SIGNAL_PROTO)

# 設置CPU_VENDOR_OS的值
include(GetHostTriple)
get_host_triple(CPU_VENDOR_OS)

include(CheckCSourceCompiles)

macro(add_c_include includes files)
  set(${includes} "")

  foreach(file_name ${files})
    set(${includes} "${${includes}}#include <${file_name}>\n")
  endforeach()
endmacro(add_c_include)

function(check_type_exists type file_list variable)
  add_c_include(includes ${file_list})

  check_c_source_compiles("
    ${includes} ${type} var;
    int main(void) { return 0; }
    " ${variable})
endfunction(check_type_exists)

# 檢查類型尺寸
include(CheckTypeSize)
function(check_c_type_size type variable)
  check_type_size(${type} ${variable}  LANGUAGE C)
endfunction(check_c_type_size)

check_c_type_size(char CHAR_SIZE)
check_c_type_size(wchar_t WCHAR_T_SIZE)
check_c_type_size(short SHORT_SIZE)
check_c_type_size(int INT_SIZE)
check_c_type_size(long LONG_SIZE)
check_c_type_size("long long" LONG_LONG_SIZE)
check_c_type_size(float FLOAT_SIZE)
check_c_type_size(double DOUBLE_SIZE)
check_c_type_size("long double" LONG_DOUBLE_SIZE)
check_c_type_size("long long double" LONG_LONG_DOUBLE_SIZE)
check_c_type_size("void *" POINTER_SIZE)


# 檢查類型是否存在
set(HAVE_WCHAR_T ${HAVE_WCHAR_T_SIZE})
set(HAVE_LONG_LONG ${HAVE_LONG_LONG_SIZE})
set(HAVE_LONG_DOUBLE ${HAVE_LONG_DOUBLE_SIZE})
set(HAVE_LONG_LONG_DOUBLE ${HAVE_LONG_LONG_DOUBLE_SIZE})

include(CheckCSourceRuns)

function(check_ipv4 variable)
  check_c_source_runs("
    #include <sys/socket.h>
    #include <netinet/in.h>
    int main(void) {
      int fd;
      struct sockaddr_in foo;
      fd = socket(AF_INET, SOCK_STREAM, 0);
      return (fd < 0) ? 1 : 0;
    }
    " ${variable})
endfunction(check_ipv4)

check_ipv4(IPV4)

function(check_ipv6 variable)
  check_c_source_runs("
    #include <sys/socket.h>
    #include <netinet/in.h>
    int main(void) {
      int fd;
      struct sockaddr_in6 foo;
      fd = socket(AF_INET6, SOCK_STREAM, 0);
      return (fd < 0) ? 1 : 0;
    }
    " ${variable})
endfunction(check_ipv6)

check_ipv6(IPV6)
