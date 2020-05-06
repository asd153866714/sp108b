## 測試 forever

### sp\code\c\06-os1windows\01-stdc\01-forever : 

```
PS D:\ccc\course\sp\code\c\06-os1windows\02-forever> gcc forever.c -o forever
PS D:\ccc\course\sp\code\c\06-os1windows\02-forever> ./forever

PS D:\ccc\course\sp\code\c\06-os1windows\02-forever> Start-Process forever.exe
// 此時會開出一個新視窗去跑 forever.exe

PS D:\ccc\course\sp\code\c\06-os1windows\02-forever> Get-Process -name forever

Handles  NPM(K)    PM(K)      WS(K)     CPU(s)     Id  SI ProcessName
-------  ------    -----      -----     ------     --  -- -----------
     50       5      684       2716      17.03  10368   7 forever

// 接著按 Ctrl-Alt-Del 選工作管理員，看有沒有 forever.exe

// 執行但不產生新視窗
PS D:\ccc\course\sp\code\c\06-os1windows\02-forever> Start-Process -NoNewWindow forever.exe
PS D:\ccc\course\sp\code\c\06-os1windows\02-forever> Get-Process -name forever

Handles  NPM(K)    PM(K)      WS(K)     CPU(s)     Id  SI ProcessName
-------  ------    -----      -----     ------     --  -- -----------
     50       5      684       2716      17.03  10368   7 forever

PS D:\ccc\course\sp\code\c\06-os1windows\02-forever> Stop-Process -name forever
```

### sp\code\c\06-os1windows\01-stdc\02-cat

```
PS D:\ccc\course\sp\code\c\06-os1windows\01-stdc\02-cat> gcc cat.c -o cat

// 用標準C 讀檔的方式
PS D:\ccc\course\sp\code\c\06-os1windows\01-stdc\02-cat> ./cat cat.c     
#include <stdio.h>

#define TEXT_SIZE 1000000

char text[TEXT_SIZE];

int main(int argc, char *argv[]) {
  char *fileName = argv[1];
  FILE *file = fopen(fileName, "rt");
  int len = fread(text, 1, TEXT_SIZE-1, file);
  text[len] = 0;
  printf("%s\n", text);
}
```

### sp\code\c\06-os1windows\02-mingw\01-cat

```
// 比較上面
#include <stdio.h>
#include <fcntl.h>

#define TEXT_SIZE 1000000

char text[TEXT_SIZE];

int main(int argc, char *argv[]) {
  char *fileName = argv[1];
  int fd = open(fileName, O_RDONLY);      // FILE *file = fopen(fileName, "rt");
  int len = read(fd, text, TEXT_SIZE-1);  // int len = fread(text, 1, TEXT_SIZE-1, file);
  text[len] = 0;
  printf("%s\n", text);
}
```
