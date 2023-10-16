#include "shell.h"

int main() {
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

while (1) 
{
if (isatty(STDIN_FILENO) == 1)
{
write_return = write(STDOUT_FILENO, "my$hell ", 8);
if (write_return == -1) {
perror("write");
}
fflush(stdout);
}

read_line = getline(&string, &len, stdin);

if (read_line == -1)
{
if (read_line == EOF)
{
my_exit();
} 
else
{
perror("getline");
return (-1);
}
}
    
else 
{
/* Tokenize commands */
  i = 0;
token = strtok(string, delimiter);
while (token != NULL) 
{
arg[i] = token;
token = strtok(NULL, delimiter);
  i++;
  /*printf("arg[%d] = %s\ntoken = %s\n", i, arg[i], token);*/
}
/* Ensure the last element in the arg array is NULL*/
arg[i] = NULL;

  if (strcmp(arg[0], "exit") == 0)
  {
  my_exit();
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
 /* printf("path = %s\n", path);*/
if (path != NULL)
{
execve(path, arg, environ);
  if (execve(path, arg, environ) == -1)
  {
    return (-1);
    free(string);
  }

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
  return 0;
}

