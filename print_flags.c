#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* get_flags -It Calculates the flags that are active
* @i: It takes a parameter
* @format: The formatted string in which the argument is printed
* Return: The flags
*/

int get_flags(const char *format, int *i)
{
/* - + 0 # ' ' */
/* 1 2 4 8 16 */

int c, curr_i;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE,
0};
for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
for (c = 0; FLAGS_CH[c] != '\0'; c++)
if (format[curr_i] == FLAGS_CH[c])
{
flags |= FLAGS_ARR[c];
break;
}
if (FLAGS_CH[c] == 0)
break;
}
*i = curr_i - 1;
return (flags);
}
