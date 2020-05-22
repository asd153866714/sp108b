# Compiler

# Test

```
user@DESKTOP-9VVBDPS MINGW64 /d/110713305/sp108b/homework/mid (master)
$ ./compiler test/for.c
a=0;
for (i=1; i<5; i=i+1){
    a=a+1;
}
========== lex ==============
token=a
token==
token=0
token=;
token=for
token=(
token=i
token==
token=1
token=;
token=i
token=<
token=5
token=;
token=i
token==
token=i
token=+
token=1
token=)
token={
token=a
token==
token=a
token=+
token=1
token=;
token=}
========== dump ==============
0:a
1:=
2:0
3:;
4:for
5:(
6:i
7:=
8:1
9:;
10:i
11:<
12:5
13:;
14:i
15:=
16:i
17:+
18:1
19:)
20:{
21:a
22:=
23:a
24:+
25:1
26:;
27:}
============ parse =============
t0 = 0
a = t0
t1 = 1
i = t1
(L0)
t2 = i
t3 = 5
t4 = t2 < t3
if T4 goto L2
goto L3
(L1)
t5 = i
t6 = 1
t7 = t5 + t6
i = t7
goto L0
(L2)
t8 = a
t9 = 1
t10 = t8 + t9
a = t10
goto L1
(L3)
```
