/*
** EPITECH PROJECT, 2023
** navy
** File description:
** main
*/

#include "../include/header.h"
#include <stdio.h>

static int help(void)
{
    write(1, "USAGE\n\t./navy [first_player_pid] navy_positions\nDESCRIP", 56);
    write(1, "TION\n\tfirst_player_pid: only for the 2nd player. pid of ", 57);
    write(1, "the first player.\n\tnavy_positions: file representing the", 57);
    write(1, " positions of the ships.\n", 26);
    return 0;
}

static int call_navy(int ac, char **av, navy_t *navy)
{
    int fd;

    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return 84;
        navy_one(fd, navy);
        close(fd);
        return 0;
    }
    if (ac == 3) {
        fd = open(av[2], O_RDONLY);
        if (fd == -1)
            return 84;
        navy_two(my_getnbr(av[1]), fd, navy);
        close(fd);
        return 0;
    }
    return 0;
}

static void destroy_navy(navy_t *navy)
{
    free(navy->my_map);
    free(navy->enemy_map);
    free(navy);
}

int main(int ac, char **av)
{
    navy_t *navy;

    if (ac < 2 || ac > 3)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (help());
    if (manage_error(ac, av) == 84)
        return 84;
    navy = malloc(sizeof(navy_t));
    call_navy(ac, av, navy);
    if (navy->win == true) {
        my_printf("\nI won\n");
        destroy_navy(navy);
        return 0;
    } else {
        my_printf("\nEnemy won\n");
        destroy_navy(navy);
        return 1;
    }
    return 0;
}
