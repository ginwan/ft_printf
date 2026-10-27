NAME = libftprintf.a
CC = cc
CFLAG = -Wall -Wextra -Werror


SRCS = srcs/ft_putchar.c srcs/ft_puthex_char.c srcs/ft_putnbr_unsigned.c \
	   srcs/ft_putnbr.c srcs/ft_putptr.c srcs/ft_putstr.c ft_printf.c
	
OBJS = $(SRCS:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -I ./include -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all