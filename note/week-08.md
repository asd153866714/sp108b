# 系統程式第八周 

### sp\code\c\04-toolchain\gcc\06-cpp :

用 g++ 編譯 C++ 程式

```
PS D:\ccc\sp\code\c\04-toolchain\gcc\06-cpp> g++ hello.cpp -o hello
PS D:\ccc\sp\code\c\04-toolchain\gcc\06-cpp> ./hello
hello!
```

### sp\code\c\04-toolchain\gcc\07-gdb :

用 gdb 偵錯

```
PS D:\110713305\sp\code\c\04-toolchain\gcc\07-gdb> gcc main.c add.c -o add -g
PS D:\110713305\sp\code\c\04-toolchain\gcc\07-gdb> gdb -q add
(gdb) break 6
Breakpoint 1 at 0x401326: file main.c, line 6.
(gdb) r
Starting program: D:\110713305\sp\code\c\04-toolchain\gcc\07-gdb/add.exe 
[New thread 6252.0x36b8]
[New thread 6252.0x36d0]

Breakpoint 1, main () at main.c:6
6         int t = add(5, 8);
(gdb) n
7         printf("add(5, 8)=%d\n", t);
(gdb) n
add(5, 8)=13
8         return 0;
(gdb) n
9       }(gdb) n
0x004010b6 in __mingw_CRTStartup ()
(gdb) n
Single stepping until exit from function __mingw_CRTStartup,
which has no line number information.

Program exited normally.
(gdb) Quit (expect signal SIGINT when the program is resumed)
(gdb) quit
```
