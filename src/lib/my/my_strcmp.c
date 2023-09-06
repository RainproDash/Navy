/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-sokoban-vivien.boitard
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        if (s1[i] < s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
