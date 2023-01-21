#include "main.h"
void print_buffer(char buffer[], int *index);
/**
 *_printf- Function like printf
 *@format:character string
 *Return: characters printed
 */
int _printf(const char *format, ...)
{
	int i, index,flags, width, precision,size,printed = 0, chars = 0;

	va_list ap;
	char buffer[buff_size];

	if (format == NULL)
		return (-1);
	va_start(ap, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index == buff_size)
				print_buffer(buffer, &index);
			chars++;
		}
		else
		{
			print_buffer(buffer, &index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ap);
			precision = get_precision(format, &i, ap);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, ap, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars += printed;
		}
	}

	print_buffer(buffer, &index);

	va_end(ap);

	return (chars);
}

/**
 *print_buffer - print buffer
 *@buffer: buffer
 *@index: index of to add characters
 */
void print_buffer(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);

	*index = 0;
}
