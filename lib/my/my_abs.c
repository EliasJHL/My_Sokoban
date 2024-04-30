/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "my.h"

int my_abs(int nb)
{
    if (nb < 0) {
        nb = nb * -1;
    }
    return nb;
}
