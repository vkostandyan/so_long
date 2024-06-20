NAME = so_long
CFLAGS = -Wall -Wextra -Werror 
CC = cc #-fsanitize=address
SRCS =	main.c

HEADER = 	so_long.h \
			libft.h \
			get_next_line.h

VALIDATION = validation.c \
			 utils.c \
			 is_map_playable.c \
			 validation_utils.c

GAME = 	window.c \
		images.c \
		draw_map.c \
		movement.c \
		movement_utils.c \
		enemy_animation.c

LIBFT = ft_putstr_fd.c \
		ft_strncmp.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strcpy.c \
		ft_split.c \
		ft_itoa.c 

GNL = 	get_next_line.c \
		get_next_line_utils.c 

MLX = -framework OpenGL -framework AppKit -lmlx

SRCS_DIR = ./sources/
HEADER_DIR = ./includes/
LIBFT_DIR = ./sources/libft/
GNL_DIR = ./sources/get_next_line/
VALIDATION_DIR = ./sources/validation/
GAME_DIR = ./sources/game/


SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
HEADER := $(addprefix $(HEADER_DIR), $(HEADER)) 
LIBFT := $(addprefix $(LIBFT_DIR), $(LIBFT))
GNL := $(addprefix $(GNL_DIR), $(GNL))
VALIDATION := $(addprefix $(VALIDATION_DIR), $(VALIDATION))
OPERATIONS := $(addprefix $(OPERATIONS_DIR), $(OPERATIONS))
GAME := $(addprefix $(GAME_DIR), $(GAME))

SRCS += $(LIBFT)
SRCS += $(GNL)
SRCS += $(VALIDATION)
SRCS += $(GAME)


OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} Makefile 
	@${CC} ${CFLAGS} -I$(HEADER_DIR) ${OBJS} ${MLX} -o ${NAME}

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -Imlx -c $< -o $(<:.c=.o)

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re

