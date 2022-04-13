#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **_tokenizer(char *string, char *delim);
char *_getpath(char *envp[], char *name);
char *_dirmatch(char *path, char *input);
int _printenv(char *envp[]);
int _free_double(char **token);
int _exec(char *string, char **command, char **envp);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _check_program(char *program);
int check_program(char *program);
int _verifier(char *string, char **envp);
#endif
