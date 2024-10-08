# Makefile

NAME = Codarena

SRCS = main.c \
	src/entity.c \
	src/battle.c \
	src/game.c

all :  $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all