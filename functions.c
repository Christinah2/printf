#include "main.h"

/** .........This will print Charaters .......... */
/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calcularions acrive flags
 * @width: Width
 * @Precision: Precision specification
 * @size: Size specifier
 * Return: Number of char printed
 */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/** ..........This will print a String ......... */
/**
 * print_string - print a String
 * @types: List of a argument
 * @buffer: Buffer array to handle print
 * @flags: Calculations active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size spexifier
 * Return:Number of chars peinted
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL);
	{
		str = "(null)";
		if (precision >= 0)
			str = "	";
	}

	for (str[strength] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0, i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));


/** ..............This will print Percentage(%)............... */

/**
 * print_percentage - print a Percentage
 * @types: List of a argument
 * @buffer: Buffer array to handle print
 * @flags: Calculations active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size spexifier
 * Return:Number of chars peinted
 */
int print_percentage(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "&&", 1));
}
