#include "shell.h"

void handle_signal(int sig)
{
  /*ctrl+C */
  if (sig == SIGINT)
  {
    (void)sig;
    if (write(STDOUT_FILENO, "\n", 1) == -1)
    {
      perror ("write");
    }
    if (write(STDOUT_FILENO, "my$hell$", 9) == -1)
    {
      perror ("write");
    }
  }
    /*ctrl+D*/
  /*else if (sig == SIGTERM)
  {
    if (write(STDOUT_FILENO, "exit\n", 5) == -1)
    {
      perror ("write");
    }
    my_exit();

  }*/
}