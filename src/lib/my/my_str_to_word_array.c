/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday08-marion.kauffmann
** File description:
** my_str_to_word_array
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

int is_alpha(char c)
{
    if (c == '\n')
        return 0;
    return 1;
}

int countword(char const *str)
{
    int k = 0;

    if (is_alpha(str[0]) != 0)
        k++;
    for (int i = 0; str[i] != '\0'; i++)
        (is_alpha(str[i]) == 0 && is_alpha(str[i + 1]) != 0) ? k++ : i;
    return k;
}

char *check_string(char *str, char c, int len)
{
    if (is_alpha(c) != 0)
        str = malloc(sizeof(char) * len + 1);
    return str;
}

char **my_str_to_word_array(char const *str)
{
    int word = countword(str);
    char **tab = malloc(sizeof(char *) * word + 1);
    int k = 0;
    int len = 0;

    if (word == 0)
        return NULL;
    word = my_strlen(str);
    for (int i = 0; i <= word; i++) {
        for (int n = i; str[n] && is_alpha(str[n]) != 0; len++, n++);
        tab[k] = check_string(tab[k], str[i], len);
        for (int j = 0; str[i] && is_alpha(str[i]) != 0; i++, j++) {
            tab[k][j] = str[i];
            tab[k][j + 1] = '\0';
        }
        (is_alpha(str[i - 1]) != 0 && i != 0) ? k++ : k;
    }
    tab[k] = NULL;
    return tab;
}
