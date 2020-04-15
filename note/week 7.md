# 系統程式第七周

```
$ gcc -fverbose-asm -S fib.c -o fib.s     // 產生組合語言
$ gcc -c fib.c -o fib.o                   // 產生目的檔，只編譯不連結
$ gcc main.c fib.c -o fib                 // 編譯 main.c 和 fib.c 並連結兩個檔案
$ ./fib
fib(10)=89
```
## 03-asmVm

### fib.c
```
D:\ccc\sp\code\c\03-asmVm\gcc\03-fib> gcc main.c fib.c -o fib
D:\ccc\sp\code\c\03-asmVm\gcc\03-fib> ./fib
fib(10)=89
```

### inline.c
```
PS D:\110713305\sp\code\c\03-asmVm\gcc\04-inline> gcc inline.c -o inline
PS D:\110713305\sp\code\c\03-asmVm\gcc\04-inline> ./inline
sum = 30
```

### globalCall.c
```
PS D:\110713305\sp\code\c\03-asmVm\gcc\05-globalcall> gcc -S globalCall.c -o globalCall.s
PS D:\110713305\sp\code\c\03-asmVm\gcc\05-globalcall> gcc globalCall.c -o globalCall
PS D:\110713305\sp\code\c\03-asmVm\gcc\05-globalcall> ./globalCall
add(5, 8)=13
```

## 04-toolchain

### 01-toolchain
```

```

### 02-link
```
PS D:\ccc\sp\code\c\04-toolchain\gcc\02-link> gcc main.c sum.c -o run
PS D:\ccc\sp\code\c\04-toolchain\gcc\02-link> ./run
sum(10)=55

$ gcc -S main.c -o main.s
$ gcc -S sum.c -o sum.s

$ gcc main.c sum.s -o run
$ ./run
sum(10)=55

$ gcc -c sum.c -o sum.o
$ gcc -c main.c -o main.o

$ gcc main.o sum.o -o run
$ ./run
sum(10)=55
```

### 03-macroExpand
```
PS D:\110713305\sp\code\c\04-toolchain\gcc\03-macroExpand> gcc -E max.c -o max.i
PS D:\110713305\sp\code\c\04-toolchain\gcc\03-macroExpand> gcc max.c -o max      
PS D:\110713305\sp\code\c\04-toolchain\gcc\03-macroExpand> ./max
c=5
```

