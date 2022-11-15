NAME = Teste

Q01 = 01
01_SRCS = 01.c
01_OBJS = 01.o

Q02 = 02
02_SRCS = 02.c
02_OBJS = 02.o

Q03 = 03
03_SRCS = 03.c
03_OBJS = 03.o

Q04 = 04
04_SRCS = 04.c
04_OBJS = 04.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I .

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(Q01) $(Q02) $(Q03)

$(LIBFT):
	@make -C ./libft

$(Q01): $(01_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(Q01) $(01_OBJS) $(LIBFT) -lm
$(01_OBJS): $(01_SRCS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(Q02): $(02_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(Q02) $(02_OBJS) $(LIBFT) -lm
$(02_OBJS): $(02_SRCS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(Q03): $(03_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(Q03) $(03_OBJS) $(LIBFT) -lm
$(03_OBJS): $(03_SRCS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -rf $(01_OBJS) $(02_OBJS) $(03_OBJS) $(04_OBJS)

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(Q01) $(Q02) $(Q03) $(Q04)

re: fclean all

vg:
	@clear
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./01 strings_01.txt

PHONY: all $(NAME) $(Q01) $(Q02) $(Q03) $(Q04) clean fclean re