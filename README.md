<p align="center">
<img width="409" height="128" src="https://www.holbertonschool.com/holberton-logo.png">
</p>

# Simple Shell

The goal of this projet is to write **a simple UNIX command interpreter**. It is the last project of the first trimestre at Holberton School.

## Learning Objectives

At the end of this project, we are expected to be able to explain to anyone, whitout the help of Google :

### General

* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of ```bash main```
* How does the shell use the ```PATH``` to find the programs
* How to execute another program with the ```bash execve```system call
* How to suspend the execution of a process until one of its children terminates
* What is ```bash EOF``` / end-of-file?

## Requirements

### General

* The allowed editors for this project are: ```vi```, ```vim```, ```emacs```
* All the files will be compiled on Ubuntu 14.04 LTS
* The C programs and functions will be compiled with ```gcc 4.8.4 ``` using the flags ```-Wall```  ```-Werror``` ```-Wextra``` ```and -pedantic```
* A ```README.md```, at the root of the folder of the project is mandatory
* Our code is verified using the ```Betty style```. It is checked using betty-style.pl and betty-doc.pl
* The created shell should not have any memory leaks
* Is not allowed to use more than 5 functions per file
* All the header files are include guarded

## More Info

### List of allowed functions and system calls 
-   `access`  (man 2 access)
-   `chdir`  (man 2 chdir)
-   `close`  (man 2 close)
-   `closedir`  (man 3 closedir)
-   `execve`  (man 2 execve)
-   `exit`  (man 3 exit)
-   `_exit`  (man 2 _exit)
-   `fflush`  (man 3 fflush)
-   `fork`  (man 2 fork)
-   `free`  (man 3 free)
-   `getcwd`  (man 3 getcwd)
-   `getline`  (man 3 getline)
-   `isatty`  (man 3 isatty)
-   `kill`  (man 2 kill)
-   `malloc`  (man 3 malloc)
-   `open`  (man 2 open)
-   `opendir`  (man 3 opendir)
-   `perror`  (man 3 perror)
-   `read`  (man 2 read)
-   `readdir`  (man 3 readdir)
-   `signal`  (man 2 signal)
-   `stat`  (__xstat) (man 2 stat)
-   `lstat`  (__lxstat) (man 2 lstat)
-   `fstat`  (__fxstat) (man 2 fstat)
-   `strtok`  (man 3 strtok)
-   `wait`  (man 2 wait)
-   `waitpid`  (man 2 waitpid)
-   `wait3`  (man 2 wait3)
-   `wait4`  (man 2 wait4)
-   `write`  (man 2 write)

### Compilation

Our shell will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
### Testing

Interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

Non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Development, task by task

#### 0. README, man, AUTHORS

-   Write a  `README`
-   Write a  `man`  for your shell.
-   Write an  `AUTHORS`  file at the root of the repository, listing all individuals having contributed content to the repository.

#### 1. Betty would be proud

Write a beautiful code that passes the Betty checks

#### 2. Simple shell 0.1

Write a UNIX command line interpreter.

-   Usage:  `simple_shell`

In this first level, our shell should:

-   Display a prompt and wait for the user to type a command. A command line always ends with a new line.
-   The prompt is displayed again each time a command has been executed.
-   The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
-   The command lines are made only of one word. No arguments will be passed to programs.
-   If an executable cannot be found, print an error message and display the prompt again.
-   Handle errors.
-   You have to handle the end of file condition (`Ctrl+D`)

We dont have to:

-   use the  `PATH`
-   implement built-ins
-   handle special characters :  `"`,  `'`,  `` ` ``,  `\`,  `*`,  `&`,  `#`
-   be able to move the cursor
-   handle commands with arguments

#### 3. Simple shell 0.2  mandatory

Simple shell 0.1 +

-   Handle command lines with arguments

#### 4. Simple shell 0.3  mandatory

Simple shell 0.2 +

-   Handle the  `PATH`

#### 5. Simple shell 0.4  mandatory

Simple shell 0.3 +

-   Implement the  `exit`  built-in, that exits the shell
-   Usage:  `exit`
-   You dont have to handle any argument to the built-in  `exit`

#### 6. Simple shell 1.0  mandatory

Simple shell 0.4 +

-   Implement the  `env`  **built-in**, that prints the current environment

#### 7. What happens when you type ls -l in the shell  mandatory

Write a blog post describing step by step what happens when you type  `ls -l`  and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).

-   Have at least one picture, at the top of the blog post
-   Publish your blog post on Medium or LinkedIn
-   Share your blog post at least on LinkedIn
-   Only one blog post by team
-   The blog post must be done and published before the first deadline (it will be part of the manual review)
-   Please, remember that these blogs must be written in English to further your technical ability in a variety of settings

When done, please add all urls below (blog post, LinkedIn post, etc.)

## Examples

```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh
$ ls
a.out    built_in.c          free_grid.c  handle_sigint.c  hsh     man_1_simple_shell  README.md           Test
AUTHORS  create_child_pid.c  _getenv.c    holberton.h      main.c  print_env.c         string_functions.c  verification_path.c
$ /bin/ls
a.out    built_in.c          free_grid.c  handle_sigint.c  hsh     man_1_simple_shell  README.md           Test
AUTHORS  create_child_pid.c  _getenv.c    holberton.h      main.c  print_env.c         string_functions.c  verification_path.c
$ /bin/ls -l
total 92
-rwxrwxr-x 1 vagrant vagrant  8973 Nov 19 13:47 a.out
-rw-rw-r-- 1 vagrant vagrant   220 Nov 20 16:38 AUTHORS
-rw-rw-r-- 1 vagrant vagrant   403 Nov 25 13:30 built_in.c
-rw-rw-r-- 1 vagrant vagrant   513 Nov 24 13:24 create_child_pid.c
-rw-rw-r-- 1 vagrant vagrant   227 Nov 21 13:35 free_grid.c
-rw-rw-r-- 1 vagrant vagrant   648 Nov 25 13:19 _getenv.c
-rw-rw-r-- 1 vagrant vagrant   184 Nov 24 09:59 handle_sigint.c
-rw-rw-r-- 1 vagrant vagrant   733 Nov 25 13:30 holberton.h
-rwxrwxr-x 1 vagrant vagrant 14197 Nov 25 16:08 hsh
-rw-rw-r-- 1 vagrant vagrant   995 Nov 25 15:15 main.c
-rw-rw-r-- 1 vagrant vagrant  2282 Nov 25 16:03 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant   562 Nov 21 16:15 print_env.c
-rw-rw-r-- 1 vagrant vagrant  9423 Nov 25 16:07 README.md
-rw-rw-r-- 1 vagrant vagrant  1629 Nov 25 11:31 string_functions.c
drwxrwxr-x 2 vagrant vagrant  4096 Nov 20 11:21 Test
-rw-rw-r-- 1 vagrant vagrant  1920 Nov 25 12:30 verification_path.c
$ ls -l /tmp
total 0
$
```
```
$ env
XDG_SESSION_ID=2
TERM=xterm-256color
SHELL=/bin/bash
SSH_CLIENT=10.0.2.2 56568 22
SSH_TTY=/dev/pts/0
USER=vagrant
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
MAIL=/var/mail/vagrant
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
PWD=/home/vagrant/simple_shell
LANG=en_US.UTF-8
SHLVL=1
HOME=/home/vagrant
LOGNAME=vagrant
SSH_CONNECTION=10.0.2.2 56568 10.0.2.15 22
LESSOPEN=| /usr/bin/lesspipe %s
XDG_RUNTIME_DIR=/run/user/1000
LESSCLOSE=/usr/bin/lesspipe %s %s
OLDPWD=/home/vagrant
_=./hsh
$
```

```
$ exit
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$
```

## Authors

Natalia Ponsard (https://github.com/natpons)

Aurelie Cedia (https://github.com/aureliewouy)
