/*
** EPITECH PROJECT, 2023
** navy
** File description:
** header
*/

#include "../src/lib/my/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>

#ifndef HEADER_H_
    #define HEADER_H_

typedef struct navy_s {
    int pid;
    int fd;
    bool win;
    bool is_player_one;
    int valide_pos;
    int my_points;
    int enemy_points;
    char *my_map;
    char *enemy_map;
} navy_t;

typedef struct boat_pos_s {
    int start_2;
    int end_2;
    int start_3;
    int end_3;
    int start_4;
    int end_4;
    int start_5;
    int end_5;
} boat_pos_t;

typedef struct my_siginfo_s {
    int sig;
    int pid;
    char *str;
} my_siginfo_t;

int manage_error(int ac, char **av);

void navy_one(int fd, navy_t *navy);
void navy_two(int pid, int fd, navy_t *navy);

char *creat_tab(char *tab);
void display_tab(char *tab);
void file_in_tab(char *tab, int fd);

void run_game(int fd, navy_t *navy);

void attack(navy_t *navy);
void defence(navy_t *navy);

void change_map(navy_t *navy, int x, int y);

#endif /* !HEADER_H_ */
