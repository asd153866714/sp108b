## 系統程式第七周

```
$ gcc -fverbose-asm -S fib.c -o fib.s
$ gcc -c fib.c -o fib.o
$ gcc main.c fib.c -o fib               // 編譯 main.c 和 fib.c 並連結兩個檔案
```

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
