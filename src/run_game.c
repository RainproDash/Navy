/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-vivien.boitard
** File description:
** run_game
*/

#include "../include/header.h"

static void display_attack(navy_t *navy)
{
    my_printf("\nmy positions:\n");
    display_tab(navy->my_map);
    my_printf("\nenemy's positions:\n");
    display_tab(navy->enemy_map);
}

void run_game(int fd, navy_t *navy)
{
    navy->win = false;
    navy->my_points = 0;
    navy->enemy_points = 0;
    navy->my_map = creat_tab(navy->my_map);
    navy->enemy_map = creat_tab(navy->enemy_map);
    file_in_tab(navy->my_map, fd);
    display_attack(navy);
    while (navy->my_points != 14 && navy->enemy_points != 14) {
        if (navy->is_player_one == true) {
            attack(navy);
            defence(navy);
        } else {
            defence(navy);
            attack(navy);
        }
        my_printf("%d-%d\n", navy->my_points, navy->enemy_points);
        display_attack(navy);
    }
    (navy->my_points == 14) ? navy->win = true : 0;
}
