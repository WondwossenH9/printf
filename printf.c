#include "main.h"
/**
 * _printf - produces output according to format
 * @format: input format
 * Return: characters to stdout
 */
int _printf(const char *format, ...)
{
	int char_to_print = 0;
	va_list list_of_arguments;

	if (format == NULL)
		return (-1);
	va_start(list_of_arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == '%')
			{
				write(1, format, 1);
				char_to_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_of_arguments, int);

				write(1, &c, 1);
				char_to_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_of_arguments, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				char_to_print += str_len;
			}
		}
		else if (*format != '%')
		{
			write(1, format, 1);
			char_to_print++;
		}
		format++;
	}
	va_end(list_of_arguments);
	return (char_to_print);
}
