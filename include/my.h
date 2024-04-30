/*
** EPITECH PROJECT, 2023
** Day09
** File description:
** task03
*/

#include <stdarg.h>
#include <stdio.h>
#include "struct.h"
#pragma once

int my_find_x(char **str);

int setup_map(int ac, char **av);

int my_find_y(char **str);

int count_x(char **str, struct pos_player *player_pos);

int check_pos(char **str, int sens, int cas);

int stock_pos_o(char **str, struct pos_o *stock_o, struct pos_player *player);

int check_loose(char **str, struct pos_player *player_pos);

void max_size_x(char *buffer, struct pos_player *player_pos);

char **move_down(char **str, int move, struct pos_player *plyr, int cas);

int validity_map(char *b, int size);

char **move_player(char **str, int move, struct pos_player *plyr, int cas);

int my_verification_down(int ch, struct pos_player *plyr, char **str);

double my_put_scientg(double nb);

void free_close(char **str, struct pos_player *player_pos, char *buffer);

int print_str(char **, struct pos_player *, struct pos_o *stock_o);

void my_nbr_detect(int i, char *str);

int my_put_point(double nb, int num);

double my_put_doubleg(double nb);

int my_printf(const char *format, ...);

long int my_put_long(long int nb);

double my_put_scient(double nb);

double my_put_scientmaj(double nb);

double my_put_gmaj(double nb);

double my_put_g(double nb);

int my_put_unsinged(int nb);

void verification(const char *format, int i, va_list ap);

double my_put_g(double nb);

void my_putnbr_base(unsigned long long nb, char *base);

double my_put_float(double nb);

double my_put_double(double nb);

int my_convert_octal(int nb);

int my_hexa_maj(int nb);

int my_hexa_min(int nb);

void my_putchar(char);

int my_isneg(int);

int my_put_nbr(int);

void my_swap(int *, int *);

int my_putstr(char const *);

int my_strlen(char const *);

int my_getnbr(char const *);

void my_sort_int_array(int *, int);

int my_compute_power_rec(int, int);

int my_compute_square_root(int);

int my_is_prime(int);

int my_find_prime_sup(int);

char *my_strcpy(char *, char const *);

char *my_strncpy(char *, char const *, int);

char *my_revstr(char *);

char *my_strstr(char *, char const *);

int my_strcmp(char const *, char const *);

int my_strncmp(char const *, char const *, int);

char *my_strupcase(char *);

char *my_strlowcase(char *);

char *my_strcapitalize(char *);

int my_str_isalpha(char const *);

int my_str_isnum(char const *);

int my_str_islower(char const *);

int my_str_isupper(char const *);

int my_str_isprintable(char const *);

int my_showstr(char const *);

int my_showmen(char const *, int);

char *my_strcat(char *, char const *);

char *my_strncat(char *, char const *, int);
