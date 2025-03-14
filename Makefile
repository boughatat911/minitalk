NAME = server
CLIENT = client

B_NAME = server_bonus
B_CLIENT = client_bonus

SRCS = mandatory/server.c
CLIENT_SRCS = mandatory/client.c

B_SRCS = bonus/server_bonus.c
B_CLIENT_SRCS = bonus/client_bonus.c

OBJS = $(SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)
B_CLIENT_OBJS = $(B_CLIENT_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

# ft_printf library
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR)

all: $(PRINTF_LIB) $(NAME) $(CLIENT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(PRINTF_LIB)

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME) $(PRINTF_LIB)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT) $(PRINTF_LIB)

$(B_CLIENT): $(B_CLIENT_OBJS)
	$(CC) $(CFLAGS) $(B_CLIENT_OBJS) -o $(B_CLIENT) $(PRINTF_LIB)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(PRINTF_INC) -c $< -o $@

bonus: $(PRINTF_LIB) $(B_NAME) $(B_CLIENT)

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJS) $(CLIENT_OBJS) $(B_OBJS) $(B_CLIENT_OBJS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME) $(CLIENT) $(B_NAME) $(B_CLIENT)

re: fclean all