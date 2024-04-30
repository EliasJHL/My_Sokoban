/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#pragma once
#define CHECK_VALIDITY(c) (c == ' ' || c == 'O' || c == 'P' || c == '#')
#define CPY_MAP(c) (c == 'P' || c == 'X')

struct pos_player {
    int pos_x;
    int pos_y;
    int max_x;
    int max_y;
    int len_buff;
    int count_x;
    int ac;
    char **av;
    char **cpy_map;
    int count;
    int i;
    int k;
    int p;
    int j;
};

struct pos_o {
    int x;
    int y;
};
