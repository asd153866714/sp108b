## 03-asmVm
### part 1 :
```
git pull origin master
mingw32-make
./asm ../test/Add
./vm ../test/Add.bin
./asm ../test/sum
./vm ../test/sum.bin
```

#### sp\code\c\03-asmVm\hack\c :

```
PS D:\110713305\sp\code\c\03-asmVm\hack\c> mingw32-make
gcc -std=c99 -O0 asm.c c6.c -o asm
gcc -std=c99 -O0 vm.c -o vm
PS D:\110713305\sp\code\c\03-asmVm\hack\c> ./asm ../test/Add
======= SYMBOL TABLE ===========
0: R0, 0
1: R1, 1
2: R2, 2
3: R3, 3
4: R4, 4
5: R5, 5
6: R6, 6
7: R7, 7
8: R8, 8
9: R9, 9
10: R10, 10
11: R11, 11
12: R12, 12
13: R13, 13
14: R14, 14
15: R15, 15
16: SCREEN, 16384
17: KBD, 24576
18: SP, 0
19: LCL, 1
20: ARG, 2
21: THIS, 3
22: THAT, 4
============= PASS1 ================
00:@2
01:D=A
02:@3
03:D=D+A
04:@0
05:M=D
======= SYMBOL TABLE ===========
0: R0, 0
1: R1, 1
2: R2, 2
3: R3, 3
4: R4, 4
5: R5, 5
6: R6, 6
7: R7, 7
8: R8, 8
9: R9, 9
10: R10, 10
11: R11, 11
12: R12, 12
13: R13, 13
14: R14, 14
16: SCREEN, 16384
17: KBD, 24576
18: SP, 0
19: LCL, 1
20: ARG, 2
21: THIS, 3
22: THAT, 4
00: @2                   0000000000000010 0002
01: D=A                  1110110000010000 ec10
02: @3                   0000000000000011 0003
03: D=D+A                1110000010010000 e090
04: @0                   0000000000000000 0000
05: M=D                  1110001100001000 e308
```
```
// 對應上方PASS1組合語言， 由虛擬機產生的結果
PS D:\110713305\sp\code\c\03-asmVm\hack\c> ./vm ../test/Add.bin
PC=0000 I=0002 A=0002 D=0000 m[A]=0000
PC=0001 I=EC10 A=0002 D=0002 m[A]=0000 a=0 c=30 d=2 j=0
PC=0002 I=0003 A=0003 D=0002 m[A]=0000
PC=0003 I=E090 A=0003 D=0005 m[A]=0000 a=0 c=02 d=2 j=0
PC=0004 I=0000 A=0000 D=0005 m[A]=0000
PC=0005 I=E308 A=0000 D=0005 m[A]=0005 a=0 c=0C d=1 j=0
exit program !
```

![image](https://scontent.fkhh1-2.fna.fbcdn.net/v/t1.0-9/92523145_10157915162531893_6576188808188919808_n.jpg?_nc_cat=108&_nc_sid=1480c5&_nc_ohc=fqWf1on86g4AX8xqcrw&_nc_ht=scontent.fkhh1-2.fna&oh=84a14845a6ad6d98dc63adbf756217c8&oe=5EC3375C&dl=1)

### part 2 :

#### sp\code\c\03-asmVm\gcc\01-add :

```
// 用 gcc 編譯
PS D:\ccc\sp\code\c\03-asmVm\gcc\01-add> gcc main.c add.c -o add
PS D:\ccc\sp\code\c\03-asmVm\gcc\01-add> ./add
add(5, 8)=13

// 用 gcc 產生組合語言
PS D:\ccc\sp\code\c\03-asmVm\gcc\01-add> gcc -S add.c -o add.s
```

```
// 產生組合語言 (有註解)
PS D:\ccc\sp\code\c\03-asmVm\gcc\01-add> gcc -fverbose-asm -S add.c -o add.s
PS D:\ccc\sp\code\c\03-asmVm\gcc\01-add> gcc -fverbose-asm -S main.c -o main.s
```

* sp\code\c\03-asmVm\gcc\00-foobar :

來源 : https://eli.thegreenplace.net/2011/02/04/where-the-top-of-the-stack-is-on-x86

```
PS D:\ccc\sp\code\c\03-asmVm\gcc\00-foobar> gcc -fverbose-asm -S foobar.c -o foobar.s
```

#### sp\code\c\03-asmVm\gcc\02-sum :

```
PS D:\110713305\sp\code\c\03-asmVm\gcc\02-sum> gcc -std=c99 sum.c main.c -o sum 
PS D:\110713305\sp\code\c\03-asmVm\gcc\02-sum> ./sum
sum(10)=55
PS D:\110713305\sp\code\c\03-asmVm\gcc\02-sum> gcc -fverbose-asm -S main.c -o main.s
PS D:\110713305\sp\code\c\03-asmVm\gcc\02-sum> gcc -fverbose-asm -S main.c -o sum.s 
```
