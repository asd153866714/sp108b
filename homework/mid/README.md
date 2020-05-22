# 參考資料

[break、 continue、goto]https://openhome.cc/Gossip/CGossip/BreakContinueGoto.html
[for 迴圈]https://openhome.cc/Gossip/CGossip/forStatement.html
# Test

### for
```
user@DESKTOP-9VVBDPS MINGW64 /d/110713305/sp108b/homework/mid (master)
$ ./compiler test/for.c
a=0;
for (i=1; i<5; i=i+1){
    a=a+1;
}
========== lex ==============
...
========== dump ==============
...
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
user@DESKTOP-9VVBDPS MINGW64 /d/110713305/sp108b/homework/mid (master)
$ ./compiler test/goto.c
a = 1;
b = 2;

goto goto1;

a = a + 1;

goto1:
a = a + b;
========== lex ==============
...
========== dump ==============
...
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
