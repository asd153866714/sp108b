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
PS D:\110713305\sp\code\c\04-toolchain\gcc\01-toolchain> gcc -S sum.c -o sum.s -std=c99
PS D:\110713305\sp\code\c\04-toolchain\gcc\01-toolchain> gcc -c sum.s -o sum.o
PS D:\110713305\sp\code\c\04-toolchain\gcc\01-toolchain> gcc sum.o -o sum
PS D:\110713305\sp\code\c\04-toolchain\gcc\01-toolchain> ./sum
sum(10)=55

PS D:\110713305\sp\code\c\04-toolchain\gcc\01-toolchain> objdump -d sum.o

sum.o:     file format pe-i386


Disassembly of section .text:

00000000 <_printf>:
   0:   55                      push   %ebp
   1:   89 e5                   mov    %esp,%ebp
   3:   53                      push   %ebx
   4:   83 ec 24                sub    $0x24,%esp
   7:   8d 45 0c                lea    0xc(%ebp),%eax
   a:   89 45 f4                mov    %eax,-0xc(%ebp)
   d:   8b 45 f4                mov    -0xc(%ebp),%eax
  10:   89 44 24 04             mov    %eax,0x4(%esp)
  14:   8b 45 08                mov    0x8(%ebp),%eax
  17:   89 04 24                mov    %eax,(%esp)
  1a:   e8 00 00 00 00          call   1f <_printf+0x1f>
  1f:   89 c3                   mov    %eax,%ebx
  21:   89 d8                   mov    %ebx,%eax
  23:   83 c4 24                add    $0x24,%esp
  26:   5b                      pop    %ebx
  27:   c9                      leave
  28:   c3                      ret

00000029 <_sum>:
  29:   55                      push   %ebp
  2a:   89 e5                   mov    %esp,%ebp
  2c:   83 ec 10                sub    $0x10,%esp
  2f:   c7 45 f8 00 00 00 00    movl   $0x0,-0x8(%ebp)
  36:   c7 45 fc 00 00 00 00    movl   $0x0,-0x4(%ebp)
  3d:   eb 09                   jmp    48 <_sum+0x1f>
  3f:   8b 45 fc                mov    -0x4(%ebp),%eax
  42:   01 45 f8                add    %eax,-0x8(%ebp)
  45:   ff 45 fc                incl   -0x4(%ebp)
  48:   8b 45 fc                mov    -0x4(%ebp),%eax
  4b:   3b 45 08                cmp    0x8(%ebp),%eax
  4e:   7e ef                   jle    3f <_sum+0x16>
  50:   8b 45 f8                mov    -0x8(%ebp),%eax
  53:   c9                      leave
  54:   c3                      ret    

00000055 <_main>:
  55:   55                      push   %ebp
  56:   89 e5                   mov    %esp,%ebp
  58:   83 e4 f0                and    $0xfffffff0,%esp
  5b:   83 ec 20                sub    $0x20,%esp
  5e:   e8 00 00 00 00          call   63 <_main+0xe>
  63:   c7 04 24 0a 00 00 00    movl   $0xa,(%esp)
  6a:   e8 ba ff ff ff          call   29 <_sum>
  6f:   89 44 24 1c             mov    %eax,0x1c(%esp)
  73:   8b 44 24 1c             mov    0x1c(%esp),%eax
  77:   89 44 24 04             mov    %eax,0x4(%esp)
  7b:   c7 04 24 00 00 00 00    movl   $0x0,(%esp)
  82:   e8 79 ff ff ff          call   0 <_printf>
  87:   b8 00 00 00 00          mov    $0x0,%eax
  8c:   c9                      leave
  8d:   c3                      ret
  8e:   90                      nop
  8f:   90                      nop
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

