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

Q05 = 05
05_SRCS = 05.c
05_OBJS = 05.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I .

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(Q01) $(Q02) $(Q03) $(Q05)

$(LIBFT):
	@make -C ./libft

$(Q01): $(01_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(Q01) $(01_OBJS) $(LIBFT)
$(01_OBJS): $(01_SRCS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(Q02): $(02_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(Q02) $(02_OBJS) $(LIBFT)
$(02_OBJS): $(02_SRCS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(Q03): $(03_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(Q03) $(03_OBJS) $(LIBFT) -lm
$(03_OBJS): $(03_SRCS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(Q05): $(05_OBJS)
	$(CC) $(CFLAGS) -o $(Q05) $(05_OBJS)
$(05_OBJS): $(05_SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(01_OBJS) $(02_OBJS) $(03_OBJS) $(04_OBJS) $(05_OBJS)

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(Q01) $(Q02) $(Q03) $(Q04) $(Q05)

re: fclean all

vg:
	@clear
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./01 strings_01.txt

PHONY: all $(NAME) $(Q01) $(Q02) $(Q03) $(Q04) clean fclean re