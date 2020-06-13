### 執行方式
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/homework/power (master)
$ gcc jitCall.c -o jitCall
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/homework/power (master)
$ ./jitCall
power(a, b)=8
```
### 原理
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/homework/power (master)        
$ gcc -c power.c

user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/homework/power (master)
$ objdump -d power.o

power.o:     file format pe-i386


Disassembly of section .text:

00000000 <_power>:
   0:   55                      push   %ebp
   1:   89 e5                   mov    %esp,%ebp
   3:   83 ec 10                sub    $0x10,%esp
   6:   c7 45 f8 01 00 00 00    movl   $0x1,-0x8(%ebp)
   d:   8b 45 0c                mov    0xc(%ebp),%eax
  10:   89 45 fc                mov    %eax,-0x4(%ebp)
  13:   eb 0d                   jmp    22 <_power+0x22>
  15:   8b 45 f8                mov    -0x8(%ebp),%eax
  18:   0f af 45 08             imul   0x8(%ebp),%eax
  1c:   89 45 f8                mov    %eax,-0x8(%ebp)
  1f:   ff 4d fc                decl   -0x4(%ebp)
  22:   83 7d fc 00             cmpl   $0x0,-0x4(%ebp)
  26:   7f ed                   jg     15 <_power+0x15>
  28:   c9                      leave
  29:   c3                      ret
  2a:   90                      nop
  2b:   90                      nop
  ```