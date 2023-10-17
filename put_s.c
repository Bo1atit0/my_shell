#include "shell.h"

/**
* our_puts - prints a string, followed by a new line, to stdout
* @str: pointer to string
*Return: nothing
  */

void put_s(char *str)
{
int i = 0;
  while (str[i] != '\0')
    {
  if (write (1, &str[i], 1) == -1)
    perror ("write");
  i++;
}
}