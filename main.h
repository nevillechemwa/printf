#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *index);
int parse_R13(char *buff_dest, va_list arg, int buff_count);
int handle_print(const char *fmt, int *i,
va_list ap, char buffer[], int flags, int width, int precision, int size);


#define buff_size 1024

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list ap);
int get_precision(const char *format, int *i, va_list ap);
int get_size(const char *format, int *i);



#endif
