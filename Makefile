NAME=libftprintf.a

SRCS= ft_printf.c \

UTILS= ft_printf_get_value.c \
ft_printf_print_value.c \
ft_printf_length_value.c

OBJ_DIR = obj

OBJS= $(addprefix obj/,$(SRCS:%.c=%.o) $(UTILS:%.c=%.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = -I. -I$(LIBFT_PATH)/includes

# check if LIBFT_PATH is defined
define check-libft
	@if ["$(LIBFT_PATH)" -eq '']; then\
		echo "please specify where the libft is with LIBFT_PATH=";\
		exit 1;\
	fi
endef

all: $(NAME)

$(OBJS): libft.a $(SRCS) $(addprefix utils/,$(UTILS))
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(INCLUDES_PATH) $(SRCS) $(addprefix utils/,$(UTILS))
	mv $(SRCS:.c=.o) $(UTILS:.c=.o) obj

$(NAME): libft.a $(OBJS)
	mv libft.a $(NAME)
	ar rs $(NAME) $(OBJS)

libft.a:
	$(check-libft)
	make -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a .

clean:
	$(check-libft)
	rm -rf obj
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(check-libft)
	rm -f $(NAME)
	rm -f libft.a
	make fclean -C $(LIBFT_PATH)

re: fclean all
