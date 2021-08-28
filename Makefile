NAME = push_swap

HEAD = push_swap.h

C_FILE = main.c utils.c cmd.c

C_FILE_MAIN = $(C_FILE)

O_FILE = $(C_FILE_MAIN:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	$(MAKE) -C ./libft bonus
	gcc -Wall -Wextra -Werror $(O_FILE)  ./libft/libft.a -o $(NAME)

%.o: %.c $(HEAD)
	gcc $(СFLAGS) -c $< -o $@

clean:
	@rm -f $(O_FILE)
	$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
