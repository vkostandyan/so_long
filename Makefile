NAME = so_long

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRCS = \
		validation.c \
		utils.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_strlen.c \
		./libft/ft_strncmp.c \
		./libft/ft_strjoin.c \
		./libft/ft_strchr.c \
		map.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		# ./get_next_line/libft/ft_strjoin.c


OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} Makefile so_long.h
	@${CC} ${CFLAGS} main.c ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re
