CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = ft_out_csp.c ft_out_pdiux.c ft_print_util.c ft_printf.c ft_isdigit.c ft_strlen.c ft_putchar_fd.c ft_count_put_n.c
OBJS	= ${SRCS:.c=.o}
NAME = libftprintf.a

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
