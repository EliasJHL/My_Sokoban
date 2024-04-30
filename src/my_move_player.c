/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/struct.h"
#include "../include/my.h"
#include <stdlib.h>

void free_close(char **str, struct pos_player *player_pos, char *buffer)
{
    for (int mem = 0; mem < player_pos->max_y + 1; mem++) {
        free(str[mem]);
    }
    free(str);
    free(player_pos);
    free(buffer);
}

char **move_left(char **str, int move,
    struct pos_player *plyr, int cas)
{
    int pos_x = plyr->pos_x;
    int pos_y = plyr->pos_y;

    if (move == 4){
        if (cas == 1)
            str[pos_y][pos_x - 2] = 'X';
        if (cas == 2){
            str[pos_y][pos_x - 2] = 'X';
            str[pos_y][pos_x - 3] = 'X';
        }
        str[pos_y][pos_x - 1] = 'P';
        str[pos_y][pos_x] = ' ';
        return str;
    }
    return str;
}

char **move_right(char **str, int move,
    struct pos_player *plyr, int cas)
{
    int pos_x = plyr->pos_x;
    int pos_y = plyr->pos_y;

    if (move == 2){
        if (cas == 1)
            str[pos_y][pos_x + 2] = 'X';
        if (cas == 2){
            str[pos_y][pos_x + 2] = 'X';
            str[pos_y][pos_x + 3] = 'X';
        }
        str[pos_y][pos_x + 1] = 'P';
        str[pos_y][pos_x] = ' ';
        return str;
    } else {
        str = move_left(str, move, plyr, cas);
    }
    return str;
}

char **move_up(char **str, int move, struct pos_player *plyr, int cas)
{
    int pos_x = plyr->pos_x;
    int pos_y = plyr->pos_y;

    if (move == 1){
        if (cas == 1)
            str[pos_y - 2][pos_x] = 'X';
        if (cas == 2){
            str[pos_y - 2][pos_x] = 'X';
            str[pos_y - 3][pos_x] = 'X';
        }
        str[pos_y - 1][pos_x] = 'P';
        str[pos_y][pos_x] = ' ';
        return str;
    } else {
        str = move_right(str, move, plyr, cas);
    }
    return str;
}

char **move_down(char **str, int move, struct pos_player *plyr, int cas)
{
    int pos_x = plyr->pos_x;
    int pos_y = plyr->pos_y;

    if (move == 3){
        if (cas == 1)
            str[pos_y + 2][pos_x] = 'X';
        if (cas == 2) {
            str[pos_y + 2][pos_x] = 'X';
            str[pos_y + 3][pos_x] = 'X';
        }
        str[pos_y + 1][pos_x] = 'P';
        str[pos_y][pos_x] = ' ';
        return str;
    } else {
        str = move_up(str, move, plyr, cas);
    }
    return str;
}
