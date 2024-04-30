/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/struct.h"
#include "../include/my.h"

static int pos_o_stock(char **str, struct pos_player *p, struct pos_o *o)
{
    if (str[p->p][p->j] == 'O') {
        o[p->count].x = p->j;
        o[p->count].y = p->p;
        p->count += 1;
    }
    return 0;
}

int stock_pos_o(char **str, struct pos_o *stock_o, struct pos_player *player)
{
    player->count = 0;
    for (int p = 0; p < player->max_y; p++) {
        for (int j = 0; j < player->max_x + 1; j++) {
            player->p = p;
            player->j = j;
            pos_o_stock(str, player, stock_o);
        }
    }
}

static int loose_process(char **str, int i, int k)
{
    if (str[i][k] == 'X') {
        if (str[i][k + 1] == '#' && str[i - 1][k] == '#')
            return 1;
        if (str[i][k - 1] == '#' && str[i - 1][k] == '#')
            return 1;
        if (str[i][k - 1] == '#' && str[i + 1][k] == '#')
            return 1;
        if (str[i][k + 1] == '#' && str[i + 1][k] == '#')
            return 1;
    }
    return 0;
}

int check_loose(char **str, struct pos_player *player_pos)
{
    int check = 0;

    for (int i = 0; i < player_pos->max_y; i++) {
        for (int k = 0; k < player_pos->max_x; k++) {
            check += loose_process(str, i, k);
        }
    }
    if (check >= player_pos->count_x) {
        return 1;
    }
    return 0;
}

static int count_x_process(char **str, int i, int k)
{
    if (str[i][k] == 'X') {
        return 1;
    }
    return 0;
}

int count_x(char **str, struct pos_player *player_pos)
{
    int count = 0;

    for (int i = 0; i < player_pos->max_y; i++) {
        for (int k = 0; k < player_pos->max_x; k++) {
            count += count_x_process(str, i, k);
        }
    }
    player_pos->count_x = count;
    return 0;
}

static int verif_max_x(int temp, int max_x, struct pos_player *player_pos)
{
    if (temp > player_pos->max_x){
        player_pos->max_x = temp;
    }
}

void max_size_x(char *buffer, struct pos_player *player_pos)
{
    int k = 0;
    int temp = 0;
    int max_x = 0;

    player_pos->max_y = 0;
    while (buffer[k] != '\0') {
        if (buffer[k] != '\n') {
            k++;
            temp++;
        } else {
            player_pos->max_y += 1;
            verif_max_x(temp, max_x, player_pos);
            k++;
            temp = 0;
        }
    }
    player_pos->len_buff = k;
}
