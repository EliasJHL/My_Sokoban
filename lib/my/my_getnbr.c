/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "my.h"

int my_getnbr(const char *str)
{
    int ret = 0;
    int i = 0;
    int len = my_strlen(str);

    while (i < len) {
        if (str[i] >= '0' && str[i] <= '9') {
            ret = ret * 10 + (str[i] - '0');
        }
        i++;
    }
    return ret;
}
