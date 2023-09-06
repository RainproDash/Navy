/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-vivien.boitard
** File description:
** manage_map
*/

#include "../include/header.h"

char *creat_tab(char *tab)
{
    tab = malloc(sizeof(char) * 65);
    for (int i = 0; i < 64; i++)
        tab[i] = '.';
    return tab;
}

void display_tab(char *tab)
{
    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 64; i++) {
        if (i % 8 == 0)
            my_printf("%d|", i / 8 + 1);
        my_printf("%c", tab[i]);
        if (i % 8 == 7)
            my_printf("\n");
        else
            my_printf(" ");
    }
}
