/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** task02
*/

#include <stdio.h>
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int k;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (k = i; k < n; k++) {
        dest[k] = '\0';
    }
    return dest;
}
