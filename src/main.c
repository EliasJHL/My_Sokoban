/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

int my_print_message(void)
{
    my_printf("USAGE\n    ./my_sokoban map\n");
    my_printf("DESCRIPTION\n    ");
    my_printf("map  file representing the warehouse map,");
    my_printf(" containing '#' for walls,\n");
    my_printf("         'P' for the player,");
    my_printf(" 'X' for boxes and 'O' for storage locations.\n");
}

int main(int ac, char **av)
{
    int ret = 0;

    if (av[1] == NULL) {
        return 84;
    } else if (av[1][0] == '-' && av[1][1] == 'h') {
        my_print_message();
        return 0;
    } else {
        ret = setup_map(ac, av);
    }
    return ret;
}
