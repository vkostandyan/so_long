NAME = aa.out
CFLAGS = -Wall -Wextra -Werror 
CC = cc
#-fsanitize=address
SRCS =	main.c

HEADER = 	so_long.h \
			libft.h \
			get_next_line.h

VALIDATION = validation.c \
			 utils.c \
			 is_map_playable.c \
			 validation_utils.c

LIBFT = ft_putstr_fd.c \
		ft_strncmp.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_strtrim.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strlcpy.c \
		ft_split.c \
		ft_strcpy.c

GNL = 	get_next_line.c \
		get_next_line_utils.c 


SRCS_DIR = ./sources/
HEADER_DIR = ./includes/
LIBFT_DIR = ./sources/libft/
GNL_DIR = ./sources/get_next_line/
VALIDATION_DIR = ./sources/validation/


SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
HEADER := $(addprefix $(HEADER_DIR), $(HEADER)) 
LIBFT := $(addprefix $(LIBFT_DIR), $(LIBFT))
GNL := $(addprefix $(GNL_DIR), $(GNL))
VALIDATION := $(addprefix $(VALIDATION_DIR), $(VALIDATION))
OPERATIONS := $(addprefix $(OPERATIONS_DIR), $(OPERATIONS))

SRCS += $(LIBFT)
SRCS += $(GNL)
SRCS += $(VALIDATION)


OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} Makefile 
	@${CC} ${CFLAGS} -I$(HEADER_DIR) ${OBJS} -o ${NAME}

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c  $< -o $(<:.c=.o)

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re

