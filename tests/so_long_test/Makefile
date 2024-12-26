NAME = so_long
LIBFT = ./libft/libft.a
SRC = main.c maps.c flood_fill.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
#prerequisite
all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lmlx -lXext -lX11 -o $(NAME)
clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: fclean clean all re
