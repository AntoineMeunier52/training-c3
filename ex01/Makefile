GCCFLAGS = -Wall -Werror -Wextra
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = &{SRCS:.c=.o}
NAME = libft.a
CC = gcc

.c.o:
	&{CC} &{GCCFLAGS} -I  ./includes/ -c $< -o &{<:.c=.0}

all:	&{NAME}

&{NAME}:	&{OBJS}
				ar rc &{NAME} &{OBJS}
				ranlib &{NAME}

clean:
	rm &{OBJS}

fclean:
	rm &{NAME}

re:
	fclean all

.PHONY	clean fclean re all


