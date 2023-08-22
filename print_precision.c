#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* attain_precision - It Calculates the printing precision
* @a: The list of printed arguments
* @list: The list of arguments
* @format: The formatted string to print the arguments
* Return: Precision.
*/

int attain_precision(const char *format, int *a, va_list list)
{
int curr_a = *a + 1;
int precision = -1;

if (format[curr_a] != '.')
return (precision);
precision = 0;
for (curr_a += 1; format[curr_a] != '\0'; curr_a++)
{
if (is_digit(format[curr_a]))
{
precision *= 10;
precision += format[curr_a] - '0';
}
else if (format[curr_a] == '*')
{
curr_a++;
precision = va_arg(list, int);
break;
}
else
break;
}
*a = curr_a - 1;
return (precision);
}
