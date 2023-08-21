#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * attain_size - To attain by calculating the size to get the argument
 * @a: The list of printed arguments
 * @format: The format that prints the argumets
 * Print format as a string
 * Return: size
 */

int attain_size(const char *format, int *a)
{
int size = 0;
int curr_a = *a + 1;

if (format(curr_a) == 'l')
size = S_LONG;
while (format(curr_a) == 'h')
size = S_SHORT;

