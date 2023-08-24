
<div align="center">
  <img src="https://github.com/rania3103/holbertonschool-simple_shell/blob/main/output.gif" width="50%">
</div>

# [Simple Shell](https://via.placeholder.com/10/00b48a?text=+)🐚

The shell is like a program that receives command inputs from the user’s keyboard and sends them to a machine to be executed by the kernel.

It also checks to see if the user’s command inputs are correct.

- Initialize: In this stage, a typical shell will read as well as execute its set of configuration files. These alter the shell’s behavior.

- Interpret: The shell then reads commands from “stdin” and executes them.

- Terminate: After the execution of its commands, the shell performs any of the shutdown commands, frees any memory, and terminates.

These stages are general and they may be applicable to a wide range of programs, but we will use them as the foundation for our shell.

Our shell will be so basic that there will be no configuration files and no shutdown command.

## [Prototype](https://via.placeholder.com/10/00b48a?text=+) 🤖

```c
int main(void);
```

## [Compilation](https://via.placeholder.com/10/00b48a?text=+)💻

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## [Testing](https://via.placeholder.com/10/00b48a?text=+) 🔎

Our shell work like this in interactive mode:

```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
also in non-interactive mode:

```bash
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

## [Usage/Examples](https://via.placeholder.com/10/00b48a?text=+) 🖊

```bash
SimpleShell$ ls
AUTHORS            execute.c          main.h             path.c             tokenize.c
README.md          main.c             man_1_simple_shell readline.c
SimpleShell$






```

## [Flowchart](https://via.placeholder.com/10/00b48a?text=+) 📉

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)

## [Our files](https://via.placeholder.com/10/00b48a?text=+) 📁

```
- main.h: header file
- tokenize.c: tokenize input
- execute.c: execute a command
- path.c: functions related to path
- AUTHORS: contributors to the project

```

## [Functions we used](https://via.placeholder.com/10/00b48a?text=+) 📲

```
- strcmp
- execve
- perror
- free
- wait
- exit
- fork
- stat
- printf
- strtok
- strdup
- malloc
- sprintf
- getenv
- getline
- isatty

```

## [Conclusion](https://via.placeholder.com/10/00b48a?text=+) 💎

Building a simple shell in C involves understanding how to parse and execute commands, handle user input and output, and manage processes using system calls like fork and execve.

The process of creating a shell requires a deep understanding of C programming language and the Unix operating system.
