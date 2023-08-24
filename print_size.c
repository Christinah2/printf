#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_size - To attain by calculating the size to get the argument
 * @a: The list of printed arguments
 * @format: The format that prints the argumets
 * Print format as a string
 * Return: The precision
 */

int get_size(const char *format, int *a)
{
int size = 0;
int curr_a = *a + 1;

if (format[curr_a] == 'l')
size = S_LONG;
else if (format[curr_a] == 'h')
size = S_SHORT;
if (size == 0)
*a = curr_a - 1;
else
*a = curr_a;
return (size);
}
