/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday03-vivien.boitard
** File description:
** my_putnbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    (nb < 0 && nb > -2147483648) ? nb *= -1, my_putchar('-') : nb;
    (nb >= 10 || nb == -2147483648) ? my_put_nbr(nb / 10) : nb;
    my_putchar(((nb < 0) ? nb *= -1 : nb) % 10 + 48);
    return 0;
}
