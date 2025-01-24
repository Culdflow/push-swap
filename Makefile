CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilib/libft -fsanitize=address -g
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

# Function to simulate a loading bar with green color and text explanation
define loading_bar
	@echo -n "\e[1;32mBuilding... \e[0m$(1)\n"  # Print the description text with green color
	@echo -n "\e[1;32m[                    ]\e[0m"  # Print the initial loading bar in green
	@for i in `seq 1 20`; do \
		echo -n "\b\b#"; \
		sleep 0.02; \
	done
	@echo -n "\b\b\e[0;96m Done!                \e[0m\n"  # End the line with " Done!" in light cyan color
endef

# Rule for compiling object files
.c.o:
		@${CC} ${CFLAGS} -c $< -o $@ > /dev/null 2>&1

# Main targets
all: ${OBJS} lib/libft/lib_ft.a ${NAME}
		$(call loading_bar, "Compiling object files")

lib/libft/lib_ft.a:
		$(call loading_bar, "Building libft")
		@make -C lib/libft > /dev/null 2>&1

${NAME}: lib/libft/lib_ft.a ${OBJS}
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
