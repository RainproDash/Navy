##
## EPITECH PROJECT, 2023
## navy
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.c)

NAME	=	navy

CFLAGS	=	-Wall -Wextra -I./include -g3

LDLIBS	=	-L./src/lib/my -lmy

CC	=	gcc

all:	$(NAME)

$(NAME):	$(SRC)
	make -C src/lib/my
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LDLIBS)

clean:
	make clean -C src/lib/my
	find . -type f -name "vgcore.*" -delete

fclean:	clean
	make fclean -C src/lib/my
	rm -f $(NAME)

re:	fclean all
