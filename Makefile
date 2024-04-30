##
## EPITECH PROJECT, 2023
## Makefile - Elias JHL
## File description:
## My_Sokoban
##

NAME	=	my_sokoban

NCURSES	=	-lncurses

CPPFLAGS = -L./ -lmy -I./include

SRCDIR	=	src

SRC	=	$(wildcard $(SRCDIR)/*.c)

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(NCURSES) $(CPPFLAGS)

clean:
	$(MAKE) -C lib/my clean
	$(RM) src/*.o

fclean: clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME)

re:
	$(MAKE) -C lib/my re
