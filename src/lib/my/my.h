/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-vivien.boitard
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(const char *format, ...);
char **my_str_to_word_array(char const *str);
int my_getnbr(char const *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);

#endif /* !MY_H_ */
