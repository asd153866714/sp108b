# msys2/01-curl

安裝:
`pacman` -S curl

# msys2/02-wget

安裝:
`pacman -S wget`

# ssh 遠端連上 Linux

ssh guest@misavo.com

passwd : csienqu

# 指令

```bash
guest@localhost:~/sp/code/c/06-os1windows/03-msys2/04-pacman/03-glib$ make
make: Nothing to be done for 'all'.

guest@localhost:~/sp/code/c/06-os1windows/03-msys2/04-pacman/03-glib$ ls
glist.c  gslist.c  htable.c  Makefile  README.md

guest@localhost:~/sp/code/c/06-os1windows/03-msys2/04-pacman/03-glib$ ./glist 
a
b
c
The list is now 0 items long

guest@localhost:~/sp/code/c/06-os1windows/03-msys2/04-pacman/03-glib$ ls      
glist  glist.c  gslist  gslist.c  htable  htable.c  Makefile  README.md

guest@localhost:~/sp/code/c/06-os1windows/03-msys2/04-pacman/03-glib$ ./gslist
The list is now 0 items long
The list is now 2 items long

guest@localhost:~/sp/code/c/06-os1windows/03-msys2/04-pacman/03-glib$ ./htable
There are 2 keys in the hash table
Jazzy likes Cheese
```
