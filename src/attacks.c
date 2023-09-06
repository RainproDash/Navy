/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-vivien.boitard
** File description:
** attacks
*/

#include "../include/header.h"

static int verif_input(char *str)
{
    if (my_strlen(str) != 3)
        return 1;
    if (str[0] < 65 || str[0] > 72)
        return 1;
    if (str[1] < 49 || str[1] > 56)
        return 1;
    return 0;
}

static char *convert_in_binary(char *str, int n)
{
    str = malloc(sizeof(char) * 5);

    for (int i = 0; i < 4; i++)
        str[i] = '0';
    str[4] = '\0';
    for (int i = 0; n > 0; i++) {
        str[i] = n % 2 + 48;
        n = n / 2;
    }
    my_revstr(str);
    return str;
}

static void send_signal(char *str, navy_t *navy)
{
    for (int i = 0; i < 8; i++) {
        if (str[i] == '0') {
            kill(navy->pid, SIGUSR1);
            usleep(1000);
        } else {
            kill(navy->pid, SIGUSR2);
            usleep(1000);
        }
    }
}

static void send_attack(char *str, navy_t *navy)
{
    int x = str[0] - 64;
    int y = str[1] - 48;
    char *str2 = malloc(sizeof(char) * 9);
    char *str3 = convert_in_binary(str3, x);
    char *str4 = convert_in_binary(str4, y);

    for (int i = 0; i < 4; i++)
        str2[i] = str3[i];
    for (int i = 0; i < 4; i++)
        str2[i + 4] = str4[i];
    str2[8] = '\0';
    free(str3);
    free(str4);
    send_signal(str2, navy);
    free(str2);
    change_map(navy, x, y);
}

void attack(navy_t *navy)
{
    size_t size = 32;
    char *str = malloc(sizeof(char) * 32);

    navy->valide_pos = -1;
    while (navy->valide_pos != 0) {
        my_putstr("\nattack: ");
        getline(&str, &size, stdin);
        if (verif_input(str) == 1) {
            my_putstr("wrong position");
            navy->valide_pos = 1;
        } else
            navy->valide_pos = 0;
    }
    send_attack(str, navy);
}
