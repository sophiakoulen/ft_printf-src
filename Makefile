NAME=libftprintf.a

SRCS= ft_printf.c \

UTILS= ft_printf_get_value.c \
ft_printf_print_value.c \
ft_printf_length_value.c 

OBJ_DIR = obj

OBJS= $(addprefix obj/,$(SRCS:%.c=%.o) $(UTILS:%.c=%.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS): libft.a $(SRCS) $(addprefix utils/,$(UTILS))
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -I. -I$(LIBFT_PATH) $(SRCS) $(addprefix utils/,$(UTILS))
	mv $(SRCS:.c=.o) $(UTILS:.c=.o) obj

$(NAME): libft.a $(OBJS)
	mv libft.a $(NAME)
	ar rs $(NAME) $(OBJS)

libft.a:
	make -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a . 

clean:
	rm -rf obj
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	make fclean -C $(LIBFT_PATH)

re: fclean all