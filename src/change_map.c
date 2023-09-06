/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-vivien.boitard
** File description:
** change_map
*/

#include "../include/header.h"

extern my_siginfo_t *my_info;

static void my_handler(int signo, siginfo_t *info, void *context)
{
    if (signo == SIGUSR1)
        my_info->sig = 1;
    else
        my_info->sig = 2;
    info = info;
    context = context;
}

void change_map(navy_t *navy, int x, int y)
{
    struct sigaction sa;

    my_info->sig = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = my_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (my_info->sig == 0)
        pause();
    if (my_info->sig == 1) {
        my_printf("%c%c: missed\n", x + 64, y + 48);
        navy->enemy_map[x - 1 + (y - 1) * 8] = 'o';
    } else {
        my_printf("%c%c: hit\n", x + 64, y + 48);
        navy->enemy_map[x - 1 + (y - 1) * 8] = 'x';
        navy->my_points++;
    }
}
