/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-vivien.boitard
** File description:
** manage_file
*/

#include "../include/header.h"

int check_size(char **tab, int pos, int size)
{
    if (tab[pos][2] == tab[pos][5]) {
        if ((tab[pos][3] + size - 1) != tab[pos][6])
            return 84;
    }
    if (tab[pos][3] == tab[pos][6]) {
        if ((tab[pos][2] + size - 1) != tab[pos][5])
            return 84;
    }
    return 0;
}

int check_pos(char **tab)
{
    int check = 0;

    if (tab[0][0] != '2' || tab[1][0] != '3' || tab[2][0] != '4'
    || tab[3][0] != '5')
        return 84;
    for (int i = 0; i < 4; i++) {
        if (tab[i][0] == '2')
            check = check_size(tab, i, 2);
        if (tab[i][0] == '3')
            check = check_size(tab, i, 3);
        if (tab[i][0] == '4')
            check = check_size(tab, i, 4);
        if (tab[i][0] == '5')
            check = check_size(tab, i, 5);
        if (check == 84)
            return 84;
    }
    return 0;
}

int check_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 32);
    char **tab;
    int check = 0;

    if (fd == -1)
        return 84;
    read(fd, buffer, 32);
    tab = my_str_to_word_array(buffer);
    for (int i = 0; tab[i]; i++) {
        if (my_strlen(tab[i]) != 7)
            return 84;
        check += 1;
    }
    if (check != 4)
        return 84;
    if (check_pos(tab) == 84)
        return 84;
    return 0;
}

int manage_error(int ac, char **av)
{
    if (ac == 2)
        return check_file(av[1]);
    if (ac == 3)
        return check_file(av[2]);
    return 0;
}
