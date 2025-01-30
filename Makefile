CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilib/libft -fsanitize=address -g
NAME = push_swap

SRC = srcs/algorithme.c \
	srcs/error.c \
	srcs/main.c \
	srcs/parse.c \
	srcs/pile.c \
	srcs/pile_push.c \
	srcs/pile_reverse_rotate.c \
	srcs/pile_rotate.c \
	srcs/pile_swap.c \
	srcs/pile_utils.c \
	srcs/pile_utils_more.c \
	srcs/sort.c \
	srcs/sort_utils.c \

OBJS = ${SRC:.c=.o}

define loading_bar
	@echo -n "\e[1;32mBuilding... \e[0m$(1)\n"  # Print the description text with green color
	@echo -n "\e[1;32m[                    ]\e[0m"  # Print the initial loading bar in green
	@echo -n "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
	@for i in `seq 1 19`; do \
		echo -n "#"; \
		sleep 0.02; \
	done
	@echo -n "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\e[0;96m Done!                \e[0m\n"  # End the line with " Done!" in light cyan color
endef

.c.o:
		@${CC} ${CFLAGS} -c $< -o $@ #> /dev/null 2>&1

all: lib/libft/libft.a ${NAME}

lib/libft/libft.a:
		$(call loading_bar, "Building libft")
		@make -C lib/libft > /dev/null 2>&1

${NAME}: lib/libft/libft.a ${OBJS}
		$(call loading_bar, "Building pushswap")
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L./lib/libft -lft > /dev/null 2>&1

fclean: clean
		$(call loading_bar, "Cleaning up ${NAME}")
		@rm -rf ${NAME} > /dev/null 2>&1
		@make fclean -C lib/libft > /dev/null 2>&1

clean:
		$(call loading_bar, "Cleaning object files")
		@rm -rf ${OBJS} > /dev/null 2>&1
		@make clean -C lib/libft > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
