/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-vivien.boitard
** File description:
** navy
*/

#include "../include/header.h"

my_siginfo_t *my_info;

static void my_handler(int signo, siginfo_t *info, void *context)
{
    my_info->pid = info->si_pid;
    signo = signo;
    context = context;
}

void navy_one(int fd, navy_t *navy)
{
    struct sigaction sa;

    my_info = malloc(sizeof(my_siginfo_t));
    navy->is_player_one = true;
    my_printf("my_pid: %d\nwaiting for enemy connection...\n", getpid());
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = my_handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    pause();
    my_printf("\nenemy connected\n");
    navy->pid = my_info->pid;
    run_game(fd, navy);
}

void navy_two(int pid, int fd, navy_t *navy)
{
    int my_pid = getpid();

    my_info = malloc(sizeof(my_siginfo_t));
    navy->is_player_one = false;
    navy->pid = pid;
    my_printf("my_pid: %d\n", my_pid);
    kill(pid, SIGUSR1);
    my_printf("successfully connected\n");
    run_game(fd, navy);
}
