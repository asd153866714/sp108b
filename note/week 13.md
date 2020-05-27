# sp2/msys2/03-glib

## 安裝 glib2

失敗原因 : 只有安裝執行檔

`pacman -Ss glib2`

需安裝64位元的檔案，需要函示庫和和 .h 標頭檔

`pacman -S mingw-w64-x86_64-glib2`

# sp2/database/sqlite

## sqlite3

安裝:

`pacman -S mingw-w64-x86_64-sqlite3`

## postgresql

安裝:

`pacman -S mingw-w64-x86_64-postgresql`

先切到 pgsql/c/ 的資料夾

## 修改資料庫的使用者名稱
使用者名稱為 user

`user@DESKTOP-9VVBDPS MINGW64`

修改 setting.h

```
#define connectStr "user=user dbname=testdb"
```
## pghello
```
$ ./pghello
Version of libpq: 120002
```

### make 專案
```
$ make
gcc pghello.c -o pghello `pkg-config --cflags libpq` -g -Wall -std=gnu11 -O3 `pkg-config --libs libpq`
```
### pgcreate.c 創建 Cars 資料表
```
$ ./pgcreate
```
### 手動查詢 Cars 資料表
```
$ psql testdb
psql (12.2)
Type "help" for help.
testdb=# SELECT * from Cars;
id | name | price
----+------------+--------
1 | Audi | 52642
2 | Mercedes | 57127
3 | Skoda | 9000
4 | Volvo | 29000
5 | Bentley | 350000
6 | Citroen | 21000
7 | Hummer | 41400
8 | Volkswagen | 21600
(8 rows)
testdb=# \q
```
### 用 pqmultirows.c 程式列出資料表
```
$ ./pgmultirows
1 Audi 52642
2 Mercedes 57127
3 Skoda 9000
4 Volvo 29000
5 Bentley 350000
```
### 用 pqheader.c 列出 Cars 表格的欄位
```
$ ./pgheader
There are 3 columns
The column names are:
id
name
price
```
### 用 pglisttab.c 列出所有表格
```
$ ./pglisttab
cars
```
### 用 pgtransact.c 進行原子交付
```
$ ./pgtransact
pqtransact (UPDATE/INSERT/COMMIT) success!
```
