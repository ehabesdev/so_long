.SILENT:

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJ = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME):$(OBJ)
		ar rcs $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME) 

re: fclean all

.PHONY:all clean fclean re