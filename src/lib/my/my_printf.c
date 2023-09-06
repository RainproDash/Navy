/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-my_printf
** File description:
** mini_printf
*/

#include "my.h"
#include <stdarg.h>

static int count_len_nb(int nb)
{
    int len = 0;

    if (nb < 0) {
        len++;
        nb *= -1;
    }
    for (; nb > 0; len++)
        nb /= 10;
    return (len);
}

static void switch_case_two(char c, va_list ap, int *len)
{
    int nb;

    switch (c) {
        case 'd':
            nb = va_arg(ap, int);
            my_put_nbr(nb);
            *len += count_len_nb(nb);
            break;
        case 'i':
            nb = va_arg(ap, int);
            my_put_nbr(nb);
            *len += count_len_nb(nb);
            break;
    }
}

static void switch_case_one(char c, va_list ap, int *len)
{
    char *str;

    switch (c) {
        case 'c':
            my_putchar(va_arg(ap, int));
            *len += 1;
            break;
        case 's':
            str = va_arg(ap, char *);
            my_putstr(str);
            *len += my_strlen(str);
            break;
        case '%':
            my_putchar('%');
            *len += 1;
            break;
    }
    switch_case_two(c, ap, len);
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int len = 0;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            switch_case_one(format[i + 1], ap, &len);
            i++;
        } else {
            my_putchar(format[i]);
            len++;
        }
    }
    va_end(ap);
    return (len);
}
