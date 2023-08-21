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

/** ............ This will print int ........... */
/**
 * print_integer - print an integer value
 * @types: List of a argument
 * @buffer: Buffer array to handle print
 * @flags: Calculations active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size spexifier
 * Return:Number of chars peinted
 */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[1 --] = 0;

	buffer[BUFF_SIZE -1] = '\0';
	num = (unsigned long int) n;

	if (n < 0)
		num = (unsigned long int)((-1) * n);
	is_negative = 1;
}
while (num > 0)
{
	buffer[i--] = (num % 10) + '0';
	num /= 10;
}
i++;

return (write_number(is_negative, i, buffer, flags, width, precision, size));

/** ...........This will print binary ............. */
/**
 * print_integer - print an unsigned number
 * @types: List of a argument
 * @buffer: Buffer array to handle print
 * @flags: Calculations active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size spexifier
 * Return:Number of cha
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n/m;
	for (i = 1; 1 < 32; i++)
	{
		m /= 2;
		a[i] = (n/m) % 2;
	}
	for (i = 0, sum = 0, count = 0; 1 < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
