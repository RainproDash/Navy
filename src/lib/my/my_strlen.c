/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday04-vivien.boitard
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i]; i++);
    return (i);
}
