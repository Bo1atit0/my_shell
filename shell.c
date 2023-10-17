#include "shell.h"

/**
 * main - Entry point for the Simple Shell program.
 *
 * Description: This function serves as the entry point for a simple
 * shell program, which allows users to execute commands in a shell
 * environment. It initializes the shell, reads and processes user
 * commands, and provides feedback to the user.
 *
 * Return: 0 on success, or an error code if there was a problem.
 */


int main(void) /* Passed void to the main: good practice*/
{
char *token;
pid_t pid;
char *string = NULL;
size_t len = 0;
char *delimiter = " \n";
ssize_t read_line, write_return;
int status;
char *path;
char *arg[1024];
int i;

signal(SIGINT, handle_signal);
/*  signal(SIGTERM, handle_signal); */

while (1)
{
if (isatty(STDIN_FILENO) == 1)
{
write_return = write(STDOUT_FILENO, "my$hell$ ", 9);
if (write_return == -1)
{
perror("write");
}
fflush(stdout);
}

read_line = get_line(&string, &len, stdin);

if (read_line == -1)
{
if (read_line == EOF)
{
free(string);
my_exit();
}
else
{
perror("get_line");
free(string);
return (-1);
}
}
else if (read_line < 1)/* when the user presses just enter*/
{
continue;
}
else
{
/* Tokenize commands */
i = 0;
token = str_tok(string, delimiter);
while (token != NULL)
{
arg[i] = token;
token = str_tok(NULL, delimiter);
i++;

}
/* Ensure the last element in the arg array is NULL*/
arg[i] = NULL;

if (strcmp(arg[0], "exit") == 0)
{
free(string);
my_exit();
}
else if (strcmp(arg[0], "cd") == 0)
{
my_cd(arg[1]);
}
else if (strcmp(arg[0], "env") == 0)
{
my_env();
}
else
{
pid = fork();

if (pid == -1)
{
perror("fork");
free(string);
return (-1);
}
else if (pid == 0)
{
/* Find the command's path and use it as a parameter for execve */
path = path_get(arg[0]);

if (path != NULL)
{
execve(path, arg, environ);
perror("command not found");

}
}
else
{
waitpid(pid, &status, 0);
/* Parent process code (should wait for child) */
}
}
}
}
free(string);
return (0);
}


