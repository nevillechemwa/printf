#include "main.h"

/**
 * print_rot13 - cipher used for obscuring text
 * @string_dest: string to be changed
 * @string_count: index of the destination
 * @arg: va_list to be changed
 * Return: new index
 */
int print_rot13(char *string_dest, va_list arg, int string_count)
{
	char *str;
	char *keys = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *keynew = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j = 0;

	str = va_arg(arg, char *);
	while (str[j])
	{
		for (i = 0; keys[i]; i++)
		{
			if (str[j] == keys[i])
			{
				string_dest[string_count] = keynew[i];
				break;
			}
			string_dest[string_count] = str[j];
		}
		j++, string_count++;
	}
	return (string_count);
}
