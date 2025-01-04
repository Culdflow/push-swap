CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilib/ft_printf -Ilib/libft -fsanitize=address -g
NAME = pushswap

SRC = main.c

OBJS = ${SRC:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

lib/ft_printf/libft_printf.a:
	make -C lib/ft_printf

lib/libft/lib_ft.a:
	make -C lib/libft

${NAME}: lib/ft_printf/libft_printf.a lib/libft/lib_ft.a ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L./lib/ft_printf -lftprintf -L./lib/libft -lft

fclean: clean
		rm -rf ${NAME}
		make fclean -C lib/ft_printf
		make fclean -C lib/libft

clean:
		rm -rf ${OBJS}
		make clean -C lib/ft_printf
		make clean -C lib/libft

re:	fclean all

.PHONY: all clean fclean re