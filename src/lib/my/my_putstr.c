/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday04-vivien.boitard
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return 0;
}
