# 說明
1. 編譯器擴充自老師的課堂範例， if, goto, for, do_while 語法則是新加入的。
2. if, for, do_while 是我原創的，goto 不是原創。
3. goto 是直接複製的[曾楷崴](https://github.com/w21917179/sp108b/blob/master/midterm/compiler.c) 同學的。
3. 參考老師的範例之後，我讀懂了，於是完全靠自己寫出 if, goto, for 擴充部分。
4.  if, for, do_while 我完全可以理解， goto 只有部分理解。

# 測試結果
`lex` 和 `dump` 的部分以 `...` 省略
### if
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/mid (master)
$ ./compiler test/if.c
a = 1;    
b = 2;    
c = 0;    

if(a > b){
    c = a;
}
else{     
    c = b;
}
========== lex ==============
token=a
token==
token=1
token=;
token=b
token==
token=2
token=;
token=c
token==
token=0
token=;
token=if
token=(
token=a
token=>
token=b
token=)
token={
token=c
token==
token=a
token=;
token=}
token=else
token={
token=c
token==
token=b
token=;
token=}
========== dump ==============
0:a
1:=
2:1
3:;
4:b
5:=
6:2
7:;
8:c
9:=
10:0
11:;
12:if
13:(
14:a
15:>
16:b
17:)
18:{
19:c
20:=
21:a
22:;
23:}
24:else
25:{
26:c
27:=
28:b
29:;
30:}
============ parse =============
t0 = 1
a = t0
t1 = 2
b = t1
t2 = 0
c = t2
t3 = a
t4 = b
t5 = t3 > t4
if T5 not True goto L0
t6 = a
c = t6
goto L1
(L0)
t7 = b
c = t7
(L1)
```
### for
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/mid (master)
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

### goto
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/mid (master)
$ ./compiler test/goto.c
a = 1;
b = 2;

goto goto1;

a = a + 1;

goto1:
a = a + b;
========== lex ==============
token=a
token==
token=1
token=;
token=b
token==
token=2
token=;
token=goto
token=goto1
token=;
token=a
token==
token=a
token=+
token=1
token=;
token=goto1
token=:
token=a
token==
token=a
token=+
token=b
token=;
========== dump ==============
0:a
1:=
2:1
3:;
4:b
5:=
6:2
7:;
8:goto
9:goto1
10:;
11:a
12:=
13:a
14:+
15:1
16:;
17:goto1
18::
19:a
20:=
21:a
22:+
23:b
24:;
============ parse =============
t0 = 1
a = t0
t1 = 2
b = t1
goto L0
t2 = a
t3 = 1
t4 = t2 + t3
a = t4
(L0)
t5 = a
t6 = b
t7 = t5 + t6
a = t7
```
### do_while
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/mid (master)
$ ./compiler test/do_while.c
i = 1;
do {i = i+1;
}while (i<10);

========== lex ==============
token=i
token==
token=1
token=;
token=do
token={
token=i
token==
token=i
token=+
token=1
token=;
token=}
token=while
token=(
token=i
token=<
token=10
token=)
token=;
========== dump ==============
0:i
1:=
2:1
3:;
4:do
5:{
6:i
7:=
8:i
9:+
10:1
11:;
12:}
13:while
14:(
15:i
16:<
17:10
18:)
19:;
============ parse =============
t0 = 1
i = t0
(L0)
t1 = i
t2 = 1
t3 = t1 + t2
i = t3
t4 = i
t5 = 10
t6 = t4 < t5
if not T6 goto L1
goto L0
(L1)
```
