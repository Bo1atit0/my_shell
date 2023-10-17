#include "shell.h"
/**
*our_strlen - returns the length of a string
*
*@s: the string.
*Return: length.
*/

size_t str_len(const char *s)
{
int length = 0; 


while (*s != '\0')
{
length++;
s++;
}
return (length);
}