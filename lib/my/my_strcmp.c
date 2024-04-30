/*
** EPITECH PROJECT, 2023
** DayX
** File description:
** Strcmp
*/

#include "my.h"
#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    if (s1[i] < s2[i]) {
        return -1;
    }
    if (s1[i] > s2[i]) {
        return 1;
    }
    if (s1[i] == '\0' && s2[i] != '\0') {
        return -1;
    } else if (s1[i] != '\0' && s2[i] == '\0') {
        return 1;
    }
    return 0;
}
