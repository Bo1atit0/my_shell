#include "shell.h"
/**
*our_getline - reads input from file stream
*
*@storage: buffer for storing string
*@size: size of buffer
*@stream: file descriptor
*
*Returns: number of bytes read
*/

ssize_t our_getline(char **storage, size_t *size, FILE *stream) 
{
    
    char *fget;
    size_t s_len;

  
    if (stream == NULL) {
        perror("stream");
        return (-1);
    }

    if (*storage == NULL || *size == 0) 
    {
        *size = 1024;
        *storage = (char *)malloc(*size);
        if (*storage == NULL) 
        {
            perror("storage");
            return (-1);
        }
    }

    fget = fgets(*storage, *size, stream);
  if (fget == NULL)
  {
    return (-1);
  }
    s_len = str_len(*storage);

    if (s_len >= (*size - 1)) 
    {
        *size = *size * 2;
        *storage = (char *)realloc(*storage, *size);
        if (*storage == NULL) {
            free(*storage); 
            return (-1);
        }
    }

    if ((*storage)[s_len - 1] == '\n') 
    {
        (*storage)[s_len - 1] = '\0';
        s_len--;
    }

    return (s_len);
}