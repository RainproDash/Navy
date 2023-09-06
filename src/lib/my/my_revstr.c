/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday06-vivien.boitard
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    char temp;
    int len = my_strlen(str) - 1;

    for (int i = 0; i <= len / 2; i++) {
        temp = str[len - i];
        str[len - i] = str[i];
        str[i] = temp;
    }
    return (str);
}
