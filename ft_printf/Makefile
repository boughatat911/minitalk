NAME=libftprintf.a

CC=cc

CFLAGS=-Wall -Wextra -Werror

AR=ar cr

RM=rm -f

SRCS= ft_printf.c function.c ft_hexa.c

OBJS= $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all