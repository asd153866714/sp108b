# Compiler-run 

### test/if.c
```
a = 5;
b = 10;
c = 0;
if (a > b){
  c = a;
}
else{
  c = b;
}
```

### 執行結果
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/homework/05-compiler-run (master)
$ mingw32-make
gcc -std=c99 -O0 ir.c irvm.c map.c util.c lexer.c compiler.c main.c -o compiler

user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/homework/05-compiler-run (master)
$ ./compiler test/if.c -ir -run
=======irDump()==========
00: t1 = 5
01: a = t1
02: t1 = 10
03: b = t1
04: t1 = 0
05: c = t1
06: t2 = a
07: t3 = b
08: t4 = t2 > t3
09: ifnot t4 goto L1
10: t1 = a
11: c = t1
12: goto L2
13: (L1)
14: (L2)
15: t1 = b
16: c = t1
===================irRun()=======================
00: t1 = 5 (5)
01: a = t1 (5)
02: t1 = 10 (10)
03: b = t1 (10)
04: t1 = 0 (0)
05: c = t1 (0)
06: t2 = a (5)
07: t3 = b (10)
08: t4 = t2 > t3 (0)
09: ifnot t4 (0) goto L1 (13)
13: (L1) (13)
14: (L2) (14)
15: t1 = b (10)
16: c = t1 (10)
```