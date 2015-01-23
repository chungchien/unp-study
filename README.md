#unp-study
用來學習《UNIX网絡編程》第三版。

##目錄說明

- **include/** -- 頭文件目錄
    - *unp.h* -- 包含常用的頭文件、一些定義以級庫的輸出函數的定義
    - *config.h.in:* -- 生成配置文件時的輸入文件
- **lib/** -- libunp的源文件
- **libfree/** -- libfree的源文件。主要是一些系統庫函數的可能或是簡化實現。
- **intro/** -- 書中的示例程序。
- **gtest-1.7.0/** -- gtest的源碼。用來做單元測試。
- **test/** -- 單元測試目錄。基本上是一個文件對應一個函數的測試。
- **CMakeLists.txt** -- 頂層cmake文件
- **cmake/** -- cmake模塊
    - *config-ix.cmake* -- 檢查系統環境以生成配置文件config.h的cmake模塊
    - *modules/* -- 自定義的一些cmake模塊文件
    - *kde-modules/* -- kde的一些cmake模塊

## 編譯說明

進入源碼根目錄

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

如果要編譯測試用例，可指爲cmake 指定 -DBUILD_TESTS=ON。如下：

    $ mkdir build && cd build
    $ cmake -DBUILD_TESTS=ON
    $ make
    $ make check # 也可使用 'make test'，但只會輸出測試結果而不會輸出測試的詳情

### 自定義的 cmake 選項

- **USE_READLINE_NOBUFF** 默是關閉。設爲 **ON** 則使用無緩沖的
  `readline` 函數。該函數在 *lib/readline1.c* 中定義。

- **BUILD_TESTS** 默認關閉。設爲 **ON** 則編譯單元測試。可使用 `make check`
  或 `make test` 來進行單元測試。其中 `make check` 會輸出測試詳情，而
  `make test` 則基本只會輸出測試結果。

### 其他

默認編譯生成的是 Debug 版，可使用 **CMKDE_BUILD_TYPE** 來指定生成 Release 版。