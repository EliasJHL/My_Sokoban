/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include <stdio.h>
#include <ncurses.h>

int my_find_x(char **str)
{
    int i = 0;
    int j = 0;

    if (str == NULL || *str == NULL) {
        return -1;
    }
    while (str[i] != NULL && str[i][j] != 'P') {
        if (str[i][j] == '\0') {
            i++;
            j = 0;
        } else {
            j++;
        }
    }
    return j;
}

int my_find_y(char **str)
{
    int i = 0;
    int j = 0;

    if (str == NULL || *str == NULL) {
        return -1;
    }
    while (str[i] != NULL && str[i][j] != 'P') {
        if (str[i][j] == '\0') {
            i++;
            j = 0;
        } else {
            j++;
        }
    }
    return i;
}

static int check_pos_4(char **str, int sens, int cas)
{
    int x = my_find_x(str);
    int y = my_find_y(str);
    int ret = 0;

    if (sens == 4) {
        if (cas == 0)
            ret = (str[y][x - 1] == '#') ? 1 : 2;
        if (cas == 1)
            ret = (str[y][x - 2] == '#') ? 1 : 2;
        if (cas == 2)
            ret = 1;
    }
    return ret;
}

static int check_pos_3(char **str, int sens, int cas)
{
    int x = my_find_x(str);
    int y = my_find_y(str);
    int ret = 0;

    if (sens == 3) {
        if (cas == 0)
            ret = (str[y + 1][x] == '#') ? 1 : 2;
        if (cas == 1)
            ret = (str[y + 2][x] == '#') ? 1 : 2;
        if (cas == 2)
            ret = 1;
        return ret;
    } else {
        ret = check_pos_4(str, sens, cas);
    }
    return ret;
}

int check_pos_2(char **str, int sens, int cas)
{
    int x = my_find_x(str);
    int y = my_find_y(str);
    int ret = 0;

    if (sens == 2) {
        if (cas == 0)
            ret = (str[y][x + 1] == '#') ? 1 : 2;
        if (cas == 1)
            ret = (str[y][x + 2] == '#') ? 1 : 2;
        if (cas == 2)
            ret = 1;
        return ret;
    } else {
        ret = check_pos_3(str, sens, cas);
    }
    return ret;
}

int check_pos(char **str, int sens, int cas)
{
    int x = my_find_x(str);
    int y = my_find_y(str);
    int ret;

    if (sens == 1) {
        if (cas == 0)
            ret = (str[y - 1][x] == '#') ? 1 : 2;
        if (cas == 1)
            ret = (str[y - 2][x] == '#') ? 1 : 2;
        if (cas == 2)
            ret = 1;
        return ret;
    } else {
        ret = check_pos_2(str, sens, cas);
    }
    return ret;
}
