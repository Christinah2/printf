#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* attain_width - It Calculates the printing width
* @aaa: The list of printed arguments
* @list: The list of arguments
* @format: The string that is Formatted hence so to print the arguments
* Return: The width
*/

int get_width(const char *format, int *aaa, va_list list)
{
int curr_aaa;
int width = 0;

for (curr_aaa = *aaa + 1; format[curr_aaa] != '\0'; curr_aaa++)
{
if (is_digit(format[curr_aaa]))
{
width *= 10;
width += format[curr_aaa] - '0';
}
else if (format[curr_aaa] == '*')
{
curr_aaa++;
width = va_arg(list, int);
break;
}
else
break;
}
*aaa = curr_aaa - 1;
return (width);
}
