/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i;
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (i = 0; i <= my_strlen(src); i++) {
        str[i] = src[i];
    }
    return (str);
}
