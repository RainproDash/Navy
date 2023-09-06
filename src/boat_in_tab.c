/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-vivien.boitard
** File description:
** boat_in_tab
*/

#include "../include/header.h"

static void get_pos_boat(char *buffer, boat_pos_t *boat)
{
    boat->start_2 = buffer[2] - 65 + (buffer[3] - 49) * 8;
    boat->end_2 = buffer[5] - 65 + (buffer[6] - 49) * 8;
    boat->start_3 = buffer[10] - 65 + (buffer[11] - 49) * 8;
    boat->end_3 = buffer[13] - 65 + (buffer[14] - 49) * 8;
    boat->start_4 = buffer[18] - 65 + (buffer[19] - 49) * 8;
    boat->end_4 = buffer[21] - 65 + (buffer[22] - 49) * 8;
    boat->start_5 = buffer[26] - 65 + (buffer[27] - 49) * 8;
    boat->end_5 = buffer[29] - 65 + (buffer[30] - 49) * 8;
}

static void boat_three_to_tab(char *tab, char *buffer, boat_pos_t *boat)
{
    if (buffer[11] == buffer[14])
        for (int i = boat->start_3; i <= boat->end_3; i++)
            tab[i] = '3';
    else
        for (int i = boat->start_3; i <= boat->end_3; i += 8)
            tab[i] = '3';
}

static void boat_four_to_tab(char *tab, char *buffer, boat_pos_t *boat)
{
    if (buffer[19] == buffer[22])
        for (int i = boat->start_4; i <= boat->end_4; i++)
            tab[i] = '4';
    else
        for (int i = boat->start_4; i <= boat->end_4; i += 8)
            tab[i] = '4';
}

static void boat_five_to_tab(char *tab, char *buffer, boat_pos_t *boat)
{
    if (buffer[27] == buffer[30])
        for (int i = boat->start_5; i <= boat->end_5; i++)
            tab[i] = '5';
    else
        for (int i = boat->start_5; i <= boat->end_5; i += 8)
            tab[i] = '5';
}

void file_in_tab(char *tab, int fd)
{
    boat_pos_t *boat = malloc(sizeof(boat_pos_t));
    char buffer[32];

    read(fd, buffer, 32);
    get_pos_boat(buffer, boat);
    tab[boat->start_2] = '2';
    tab[boat->end_2] = '2';
    boat_three_to_tab(tab, buffer, boat);
    boat_four_to_tab(tab, buffer, boat);
    boat_five_to_tab(tab, buffer, boat);
    free(boat);
}
