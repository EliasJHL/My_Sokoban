/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/struct.h"
#include "../include/my.h"
#include <ncurses.h>
#include <stdlib.h>

int validity_map(char *b, int size)
{
    int k = 0;
    int player_exist = 0;

    while (CHECK_VALIDITY(b[k]) || b[k] == '\n' || b[k] == 'X') {
        if (b[k] == 'P') {
            player_exist = 1;
        }
        k++;
    }
    if (k != size || player_exist != 1){
        return 84;
    } else {
        return 0;
    }
}

char print_process(char **str, struct pos_player *p, struct pos_o *o)
{
    int r = 0;

    while (r < p->count) {
        if (str[o[r].y][o[r].x] != 'P' && str[o[r].y][o[r].x] != 'X')
            str[o[r].y][o[r].x] = 'O';
        r++;
    }
    printw("%c", str[p->i][p->k]);
}

int print_str(char **str, struct pos_player *p, struct pos_o *stock_o)
{
    for (int i = 0; i < p->max_y + 1; i++) {
        for (int k = 0; k < p->max_x; k++) {
            p->i = i;
            p->k = k;
            print_process(str, p, stock_o);
        }
        printw("\n");
    }
    return 0;
}

static int my_verification_left(int ch, struct pos_player *plyr, char **str)
{
    int pos;
    int cas = 0;

    if (ch == KEY_LEFT) {
        cas += (str[plyr->pos_y][plyr->pos_x - 1] == 'X') ? 1 : 0;
        cas += (str[plyr->pos_y][plyr->pos_x - 2] == 'X' &&
            str[plyr->pos_y][plyr->pos_x - 1] != '#') ? 1 : 0;
        pos = check_pos(str, 4, cas);
        if (pos == 2) {
            str = move_down(str, 4, plyr, cas);
            plyr->pos_x = my_find_x(str);
            plyr->pos_y = my_find_y(str);
        }
    }
    return 0;
};

static int my_verification_right(int ch, struct pos_player *plyr, char **str)
{
    int pos;
    int cas = 0;

    if (ch == KEY_RIGHT) {
        cas += (str[plyr->pos_y][plyr->pos_x + 1] == 'X') ? 1 : 0;
        cas += (str[plyr->pos_y][plyr->pos_x + 2] == 'X' &&
            str[plyr->pos_y][plyr->pos_x + 1] != '#') ? 1 : 0;
        pos = check_pos(str, 2, cas);
        if (pos == 2) {
            str = move_down(str, 2, plyr, cas);
            plyr->pos_x = my_find_x(str);
            plyr->pos_y = my_find_y(str);
        }
    }
    my_verification_left(ch, plyr, str);
    return 0;
}

static int my_verification_up(int ch, struct pos_player *plyr, char **str)
{
    int pos;
    int cas = 0;

    if (ch == KEY_UP && plyr->pos_y != 1) {
        cas += (str[plyr->pos_y - 1][plyr->pos_x] == 'X') ? 1 : 0;
        if (plyr->pos_y > 1)
            cas += (str[plyr->pos_y - 2][plyr->pos_x] == 'X' &&
                str[plyr->pos_y - 1][plyr->pos_x] != '#') ? 1 : 0;
        pos = check_pos(str, 1, cas);
        if (pos == 2 && plyr->pos_y != 1) {
            str = move_down(str, 1, plyr, cas);
            plyr->pos_x = my_find_x(str);
            plyr->pos_y = my_find_y(str);
        }
    }
    my_verification_right(ch, plyr, str);
    return 0;
}

int my_verification_down(int ch, struct pos_player *plyr, char **str)
{
    int pos;
    int cas = 0;

    if (ch == KEY_DOWN && plyr->pos_y != plyr->max_y - 1) {
        cas += (str[plyr->pos_y + 1][plyr->pos_x] == 'X') ? 1 : 0;
        cas += (str[plyr->pos_y + 2][plyr->pos_x] == 'X' &&
            str[plyr->pos_y + 1][plyr->pos_x] != '#') ? 1 : 0;
        pos = check_pos(str, 3, cas);
        if (pos == 2) {
            str = move_down(str, 3, plyr, cas);
            plyr->pos_x = my_find_x(str);
            plyr->pos_y = my_find_y(str);
        }
    }
    my_verification_up(ch, plyr, str);
    return 0;
}
