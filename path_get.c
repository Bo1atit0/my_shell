#include "shell.h"

/**
 *
 *
 */

char *path_get(char *command) 
{
  char *token;
  char command_path[1024];
  char *path = getenv("PATH");
  char *path_copy = strdup(path);
  
  if (path_copy == NULL)
  {
    return (NULL);
  }
 
token = strtok(path_copy, ":");
  
  while (token != NULL) 
  {
    strcpy(command_path, token);
    
    if (command_path[strlen(command_path) - 1] != '/')
    {
      strcat(command_path, "/");
    }
    strcat(command_path, command);
    if (access(command_path, X_OK) == 0)
    {
      free(path_copy);
      return (strdup(command_path));
    }
    token = strtok(NULL, ":");
  }
  free(path_copy);
  return (command);
}