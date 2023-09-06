/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday07-vivien.boitard
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
