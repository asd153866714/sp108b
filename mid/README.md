# 說明
1. 編譯器擴充自老師的課堂範例， if, goto, for, do_while 語法則是新加入的。
2. if, goto, for, do_while 是我原創的。
3. 參考老師的範例之後，我讀懂了，於是完全靠自己寫出 if, goto, for, do_while 擴充部分。
4. if, goto, for, do_while 我完全可以理解。

# 測試結果

## if
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/mid/05-compiler-run (master)
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

## for
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/mid/05-compiler-run (master)
$ ./compiler test/for.c -ir -run
=======irDump()==========
00: t1 = 0
01: a = t1
02: t1 = 1
03: i = t1
04: (L1)
05: t2 = i
06: t3 = 2
07: t4 = t2 < t3
08: if t4 goto L3
09: goto L4
10: (L2)
11: t1 = i
12: t2 = 1
13: t3 = t1 + t2
14: i = t3
15: goto L1
16: (L3)
17: t1 = a
18: t2 = 1
19: t3 = t1 + t2
20: a = t3
21: goto L2
22: (L4)
===================irRun()=======================
00: t1 = 0 (0)
01: a = t1 (0)
02: t1 = 1 (1)
03: i = t1 (1)
04: (L1) (4)
05: t2 = i (1)
06: t3 = 2 (2)
07: t4 = t2 < t3 (1)
08: if t4 (1) goto L3 (16)
16: (L3) (16)
17: t1 = a (0)
18: t2 = 1 (1)
19: t3 = t1 + t2 (1)
20: a = t3 (1)
21: goto L2 (10)
10: (L2) (10)
11: t1 = i (1)
12: t2 = 1 (1)
13: t3 = t1 + t2 (2)
14: i = t3 (2)
15: goto L1 (4)
04: (L1) (4)
05: t2 = i (2)
06: t3 = 2 (2)
07: t4 = t2 < t3 (0)
08: if t4 (0)  -- fail
09: goto L4 (22)
22: (L4) (22)
```

## goto
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/mid/05-compiler-run (master)
$ ./compiler test/goto.c -ir -run
=======irDump()==========
00: t1 = 1
01: a = t1
02: t1 = 2
03: b = t1
04: goto L1
05: (L1)
06: t1 = a
07: t2 = b
08: t3 = t1 + t2
09: a = t3
===================irRun()=======================
00: t1 = 1 (1)
01: a = t1 (1)
02: t1 = 2 (2)
03: b = t1 (2)
04: goto L1 (5)
05: (L1) (5)
06: t1 = a (1)
07: t2 = b (2)
08: t3 = t1 + t2 (3)
09: a = t3 (3)
```
## do_while
```
user@DESKTOP-9VVBDPS MINGW64 /d/Xing/sp108b/mid/05-compiler-run (master)
$ ./compiler test/do_while.c -ir -run
=======irDump()==========
00: t1 = 1
01: i = t1
02: (L1)
03: t1 = i
04: t2 = 1
05: t3 = t1 + t2
06: i = t3
07: t4 = i
08: t5 = 3
09: t6 = t4 < t5
10: ifnot t6 goto L2
11: goto L1
12: (L2)
===================irRun()=======================
00: t1 = 1 (1)
01: i = t1 (1)
02: (L1) (2)
03: t1 = i (1)
04: t2 = 1 (1)
05: t3 = t1 + t2 (2)
06: i = t3 (2)
07: t4 = i (2)
08: t5 = 3 (3)
09: t6 = t4 < t5 (1)
10: ifnot t6 (1)  -- fail
11: goto L1 (2)
02: (L1) (2)
03: t1 = i (2)
04: t2 = 1 (1)
05: t3 = t1 + t2 (3)
06: i = t3 (3)
07: t4 = i (3)
08: t5 = 3 (3)
09: t6 = t4 < t5 (0)
10: ifnot t6 (0) goto L2 (12)
12: (L2) (12)
```