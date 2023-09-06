/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-vivien.boitard
** File description:
** defence
*/

#include "../include/header.h"

extern my_siginfo_t *my_info;

static void my_handler(int signo, siginfo_t *info, void *context)
{
    if (signo == SIGUSR1)
        my_info->str[my_info->sig] = '0';
    else
        my_info->str[my_info->sig] = '1';
    my_info->sig++;
    info = info;
    context = context;
}

static void send_answer(int x, int y, navy_t *navy)
{
    if (navy->my_map[x - 1 + (y - 1) * 8] == '.') {
        my_printf("%c%c: missed\n", x + 64, y + 48);
        navy->my_map[x - 1 + (y - 1) * 8] = 'o';
        usleep(2000);
        kill(navy->pid, SIGUSR1);
    } else if (navy->my_map[x - 1 + (y - 1) * 8] == 'x') {
        my_printf("%c%c: missed\n", x + 64, y + 48);
        usleep(2000);
        kill(navy->pid, SIGUSR1);
    } else {
        my_printf("%c%c: hit\n", x + 64, y + 48);
        navy->my_map[x - 1 + (y - 1) * 8] = 'x';
        navy->enemy_points++;
        usleep(2000);
        kill(navy->pid, SIGUSR2);

    }
}

static void decode_attack(char *str, navy_t *navy)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < 4; i++)
        x = x * 2 + str[i] - 48;
    for (int i = 4; i < 8; i++)
        y = y * 2 + str[i] - 48;
    send_answer(x, y, navy);
}

void defence(navy_t *navy)
{
    struct sigaction sa;

    my_printf("\nwaiting for enemy's attack...\n");
    my_info->sig = 0;
    my_info->str = malloc(sizeof(char) * 9);
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = my_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (my_info->sig != 8)
        pause();
    decode_attack(my_info->str, navy);
    return;
}
