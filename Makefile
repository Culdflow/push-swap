CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilib/libft #-fsanitize=address -g
NAME = pushswap

SRC = srcs/main.c \
	srcs/error.c \
	srcs/parse.c \
	srcs/pile.c \
	srcs/pile_push.c \
	srcs/pile_reverse_rotate.c \
	srcs/pile_rotate.c \
	srcs/pile_swap.c \
	srcs/sort.c

OBJS = ${SRC:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

lib/ft_printf/libft_printf.a:
	make -C lib/ft_printf

lib/libft/lib_ft.a:
	make -C lib/libft

${NAME}: lib/libft/lib_ft.a ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L./lib/libft -lft

fclean: clean
		rm -rf ${NAME}
		make fclean -C lib/libft

clean:
		rm -rf ${OBJS}
		make clean -C lib/libft

re:	fclean all

.PHONY: all clean fclean re