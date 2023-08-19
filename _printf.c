#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				int c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if
				(*format == 's')
				{
					char *s = va_arg(args, char *);
					fputs(s, stdout);
					count += strlen(s);
				}
			else if
				(*format == '%')
				{
					putchar('%');
					count++;
				}
		}
		else if
		{
			putchar(*format);
			count++;
		}

		format++;
	}
	va_end(args);

	return count;
}

int main ()
{
	_printf("Hello, %s! The answer is %d%c\n", "world", 42, '.');

	return 0;
}
