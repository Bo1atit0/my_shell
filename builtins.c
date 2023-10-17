#include "shell.h"
/**
*
*
*/

void my_exit(void)
{
  /*sleep (2);Removed the sleep as it is not required*/
  if (write(STDOUT_FILENO, " exit\n\n\n[Disconnected...]\n", 27) == -1)
    perror ("write");
  
 
  exit(0);
}

/*
*
*
*
*/
void my_cd(char *path)
{
  char *go_home;
  
  if (path == NULL)
  {
   go_home = getenv("HOME");
    if (chdir(go_home) == -1)
    {
      perror("go_home");
    }
  }
  else
  {
    if (chdir(path) != 0)
    {
      perror("chdir");
    }
  }
}

/*
*
*
*
*/
void my_env(void)
{
    /* Access the environment variables using the `environ` variable. */
    extern char** environ;
  int i;

    /* Iterate through the environment variables and print them. */
  i = 0;
    while (environ[i] != NULL)
    {
      put_s(environ[i]);
     i++;
    }
if (write(STDOUT_FILENO, "\n", 1) == -1)
{
  perror ("write");
}
}