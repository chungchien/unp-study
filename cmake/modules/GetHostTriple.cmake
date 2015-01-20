#--------------------------------------------------------------------
# Copyright (c) 2003-2014 University of Illinois at Urbana-Champaign.
# Copyright (c) 2015 Chien Chung <chungchien@163.com>
#
#--------------------------------------------------------------------
# 本文件拷貝自LLVM項目下的cmake/modules目錄下，只是對config.guess
# 的路徑做了些修改。授權說明請看當前文件所在目錄下的 LICENSE.TXT
#--------------------------------------------------------------------

# Returns the host triple.
# Invokes config.guess

function( get_host_triple var )
  if( MSVC )
    if( CMAKE_CL_64 )
      set( value "x86_64-pc-win32" )
    else()
      set( value "i686-pc-win32" )
    endif()
  elseif( MINGW AND NOT MSYS )
    if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
      set( value "x86_64-w64-mingw32" )
    else()
      set( value "i686-pc-mingw32" )
    endif()
  else( MSVC )
    set(config_guess ${PROJECT_SOURCE_DIR}/cmake/modules/config.guess)
    execute_process(COMMAND sh ${config_guess}
      RESULT_VARIABLE TT_RV
      OUTPUT_VARIABLE TT_OUT
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    if( NOT TT_RV EQUAL 0 )
      message(FATAL_ERROR "Failed to execute ${config_guess}")
    endif( NOT TT_RV EQUAL 0 )
    set( value ${TT_OUT} )
  endif( MSVC )
  set( ${var} ${value} PARENT_SCOPE )
  message(STATUS "Target triple: ${value}")
endfunction( get_host_triple var )
