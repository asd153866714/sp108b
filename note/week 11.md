## Hack CPU 的反組譯器

``` powershell
PS D:\ccc\course\sp\code\c\07-asmVm2\hack\hdasm> gcc hdasm.c -o hdasm

PS D:\ccc\course\sp\code\c\07-asmVm2\hack\hdasm> ./hdasm Add.bin
@2
D=A
@3
D=D+A
@0
M=D

PS D:\ccc\course\sp\code\c\07-asmVm2\hack\hdasm> ./hdasm sum.bin
@10
D=A
@0
M=D
@16
M=1
@17
M=0
@16
D=M
@0
D=D-M
@22
D;JGT
@16
D=M
@17
M=D+M
@16
M=M+1
@8
0;JMP
@17
D=M
@1
M=D

-------------

sprintf(op, "0"); # 把 0 印到 op

C 語言
'' -> 字元
"" -> 字串 

```

# C4 -- 500 行的 C 語言編譯器

``` powershell

PS D:\110713305\sp\code\c\08-compiler2\c4> gcc -m32 -w c4.c -o c4

PS D:\110713305\sp\code\c\08-compiler2\c4> ./c4 test/hello.c
hello, world
exit(0) cycle = 9

PS D:\110713305\sp\code\c\08-compiler2\c4> ./c4 -s test/hello.c
2:
3: int main()
4: {
5:   printf("hello, world\n");
    ENT  0
    IMM  10158168
    PSH
    PRTF
    ADJ  1
6:   return 0;
    IMM  0
    LEV
7: }
    LEV
    
PS D:\110713305\sp\code\c\08-compiler2\c4> ./c4 -d test/hello.c
1> ENT  0
2> IMM  11010136
3> PSH
4> PRTF
hello, world
5> ADJ  1
6> IMM  0
7> LEV
8> PSH
9> EXIT
exit(0) cycle = 9


```


