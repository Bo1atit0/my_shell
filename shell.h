#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ; /*for the environ function*/
void my_cd(char *dir);
void my_env(void);
void my_exit(void);

char *path_get(char *command);
ssize_t get_line(char **storage, size_t *size,
FILE *stream);
size_t str_len(const char *s);
void handle_signal(int sig);
void put_s(char *str);


#endif 

