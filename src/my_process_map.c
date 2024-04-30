/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/struct.h"
#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

static char **map_process(char *buffer, struct pos_player *player_pos, int j)
{
    char **str;
    int k = 0;
    int i = 0;

    str = malloc(sizeof(char *) * (player_pos->max_y + 1));
    for (int mem = 0; mem < player_pos->max_y + 1; mem++)
        str[mem] = malloc(sizeof(char) * (player_pos->max_x + 1));
    while (k < player_pos->len_buff) {
        if (buffer[k] == '\n') {
            j++;
            i = 0;
        } else {
            str[j][i] = buffer[k];
            i++;
        }
        k++;
    }
    buffer[k] = '\0';
    return str;
}

static int verification3_ch(int ch, struct pos_player *player_pos)
{
    if (ch == ' ') {
        clear();
        setup_map(player_pos->ac, player_pos->av);
    }
    return 0;
}

static int terminal_size_check(struct pos_player *player_pos)
{
    int col;
    int row;
    char str[26] = "ERROR : Terminal to small";
    int strlen = my_strlen(str);

    getmaxyx(stdscr, row, col);
    while (row <= player_pos->max_y || col <= player_pos->max_x) {
        clear();
        mvprintw(row / 2, ((col / 2) - (strlen / 2)), "%s", str);
        getmaxyx(stdscr, row, col);
        refresh();
    }
    return 0;
}

int check_victory(struct pos_o *o, char **str, struct pos_player *p)
{
    int r = 0;
    int k = 0;
    int count = 0;

    while (r < p->count) {
        if (str[o[r].y][o[r].x] != 'P' && str[o[r].y][o[r].x] != 'X') {
            str[o[r].y][o[r].x] = 'O';
        }
        r++;
    }
    while (k < p->count) {
        if (str[o[k].y][o[k].x] == 'X') {
            count++;
        }
        k++;
    }
    if (count == p->count)
        return 1;
    return 0;
}

int map_loop(struct pos_player *p, char **str, struct pos_o *o)
{
    int ch;

    print_str(str, p, o);
    terminal_size_check(p);
    ch = getch();
    if (ch != ERR) {
        my_verification_down(ch, p, str);
        verification3_ch(ch, p);
    }
    return 0;
}

int gen_analyse_map(struct pos_player *p, char **str, struct pos_o *o)
{
    p->pos_y = my_find_y(str);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    while (1) {
        map_loop(p, str, o);
        if (check_victory(o, str, p) == 1 || check_loose(str, p) == 1) {
            clear();
            print_str(str, p, o);
            refresh();
        }
        if (check_victory(o, str, p) == 1) {
            printf("Victory !\n");
            return 0;
        }
        if (check_loose(str, p) == 1) {
            printf("Game Over :(\n");
            return 1;
        }
        clear();
        refresh();
    }
}

int setup_map_config(char *buffer, char **av, struct pos_player *player_pos)
{
    struct pos_o stock_o[1000];
    struct stat sb;
    char **str;
    int j = 0;
    int ret = 0;

    lstat(av[1], &sb);
    if (validity_map(buffer, sb.st_size) == 84)
        return 84;
    player_pos->av = av;
    buffer[sb.st_size] = '\0';
    max_size_x(buffer, player_pos);
    str = map_process(buffer, player_pos, j);
    count_x(str, player_pos);
    stock_pos_o(str, stock_o, player_pos);
    player_pos->pos_x = my_find_x(str);
    ret = gen_analyse_map(player_pos, str, stock_o);
    free_close(str, player_pos, buffer);
    return ret;
}

int setup_map(int ac, char **av)
{
    FILE *fp;
    char *buffer;
    int ret = 0;
    struct stat sb;
    struct pos_player *player_pos = malloc(sizeof(struct pos_player));

    if (stat(av[1], &sb) != -1) {
        lstat(av[1], &sb);
        buffer = malloc(sb.st_size + 1);
    } else
        return 84;
    fp = fopen(av[1], "rb");
    if (fp == NULL)
        return 84;
    fread(buffer, sb.st_size, 1, fp);
    player_pos->ac = ac;
    ret = setup_map_config(buffer, av, player_pos);
    fclose(fp);
    return ret;
}
