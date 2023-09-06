/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday04-vivien.boitard
** File description:
** my_getnbr
*/

#include "my.h"

static int verify_int(unsigned int value, int sign)
{
    if (value > 2147483648 && sign == -1)
        return 1;
    if (value > 2147483647 && sign == 1)
        return 1;
    return 0;
}

static int check_int(int i, int nb, int sign, char const *str)
{
    unsigned int nb_test = 0;

    if (str[i] >= '0') {
        nb_test = (nb * 10) + (str[i] - 48);
        if (verify_int(nb_test, sign) == 1)
            return 2;
        return 1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int sign = 1;
    int num = 0;
    int i = 0;

    if (str[0] == 0)
        return 0;
    for (; str[i] > '9' || str[i] < '0' && str[i] != '-'; i++);
    for (; str[i]; i++) {
        if (str[i] > '9' || str[i] < '0' && str[i] != '-')
            return (nb * sign);
        (str[i] == '-') ? sign *= -1 : str[i];
        num = check_int(i, nb, sign, str);
        if (num == 2)
            return 0;
        if (num == 1)
            nb = (nb * 10) + (str[i] - 48);
    }
    return (nb * sign);
}
