#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* is_printable - It evaluates if a char is printable
* @b: The char is to be evaluated
* Return: 1 if c is printable, 0 if c is not printable
*/

int is_printable(char b)
{
if (b >= 32 && b < 127)
return (1);
return (0);
}

/**
* append_hexa_code - The append ascci in hexadecimal code to buffer
* @i: The index to start appending
* @buffer: The array of chars
* @ascii_code: ASSCI CODE.
* Return: 3
*/

int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";

/* The hexa format code is always 2 digits long */
if (ascii_code < 0)
ascii_code *= -1;
buffer[i++] = '\\';
buffer[i++] = 'x';
buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];
return (3);
}

/**
* is_digit - It verifies if a char is a digit
* @c: The char is to be evaluated
* Return: 1 if c is a digit, 0 otherwise
*/
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);
return (0);
}

/**
* convert_size_number - It casts the number to the specified size
* @size: The number indicating the casted type
* @number: The number to be casted
* Return: The casted value of num
*/

long int convert_size_number(long int number, int size)
{
if (size == S_LONG)
return (number);
else if (size == S_SHORT)
return ((short)number);
return ((int)number);
}

/**
* convert_size_unsgnd - It casts a number to the specified size
* @number: The number to be casted
* @size: The number indicating the type to be casted
* Return: The casted value of number
*/

long int convert_size_unsgnd(unsigned long int number, int size)
{
if (size == S_LONG)
return (number);
else if (size == S_SHORT)
return ((unsigned short)number);
return ((unsigned int)number);
}
