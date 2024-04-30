##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## lll
##

all:
	$(MAKE) -C lib/my
	gcc -o my_sokoban src/*.c -lncurses -L./ -lmy -I./include

clean:
	$(MAKE) -C lib/my clean

fclean:
	$(MAKE) -C lib/my fclean

re:
	$(MAKE) -C lib/my re

coding:
	.././coding-style.sh . .

rmak:
	$(MAKE) -C lib/my
	gcc -o my_sokoban *.c -lncurses -L./ -lmy -I./include
	$(MAKE) -C lib/my clean
