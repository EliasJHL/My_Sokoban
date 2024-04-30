/*
** EPITECH PROJECT, 2023
** DayX
** File description:
** getnbr
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>

int verification_fake(char const *str, int i)
{
    if (str[i] == 45) {
        write(1, &str[i], 1);
    }
    while (str[i + 1] >= 48 && str[i + 1] <= 57) {
        write(1, &str[i + 1], 1);
        i++;
    }
    return 0;
}

int my_getnbr_disp(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            verification_fake(str, i - 1);
            return 0;
        }
    }
    return 0;
}
