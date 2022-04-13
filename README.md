# Simple_Shell

Creation of a simple UNIX command interpreter, written as part of a low-level programming project for Holberton School. 

# What is Simple_Shell
Simple_Shell is a Unix command interpreter interface, albeit much simpler than other shell interpreters. Shell is a program that interprets and executes user commands.


# Invocation

To invoke our simple shell we compile all .c files and run the executable

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Simple shell can be invoked in interactve and non-interactive mode. In which it reads 
and executes commands in the order given.


# prototype

int main(unused int argc, unused char *argv[], char *envp[])

As seen in the prototype, argc, argv are unused variables, while envp is the inherited enviroment variable



# output 
Below is an example of our simple shell executing the "ls -l" command.

[![Screenshot-from-2022-04-12-23-40-36.png](https://i.postimg.cc/WzTtGBC9/Screenshot-from-2022-04-12-23-40-36.png)](https://postimg.cc/62b9wm9R)


# bugs
Program.

# about

Simple_shell is a simple emulation of the functionality of a UNIX command interpreter. As poart of group project finalizing the first trimester of Holberton School.

# authors

This project was made by Fernando Aponte and Ian Bonano.
