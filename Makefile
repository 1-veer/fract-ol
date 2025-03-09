CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = fractol
RM = rm -f
LIBFT =	LIBFT/libft.a
LIB_SRCS = ./LIBFT/ft_atoi.c		./LIBFT/ft_isprint.c	./LIBFT/ft_strnstr.c 	./LIBFT/ft_strncmp.c	./LIBFT/ft_striteri.c	\
			./LIBFT/ft_bzero.c		./LIBFT/ft_strdup.c		./LIBFT/ft_strrchr.c 	./LIBFT/ft_tolower.c	./LIBFT/ft_split.c		\
			./LIBFT/ft_memchr.c		./LIBFT/ft_strlcat.c 	./LIBFT/ft_toupper.c	./LIBFT/ft_putchar_fd.c	./LIBFT/ft_calloc.c		\
			./LIBFT/ft_isalnum.c	./LIBFT/ft_memcmp.c		./LIBFT/ft_strlcpy.c 	./LIBFT/ft_substr.c		./LIBFT/ft_putstr_fd.c	\
			./LIBFT/ft_isalpha.c	./LIBFT/ft_memcpy.c		./LIBFT/ft_strlen.c		./LIBFT/ft_strjoin.c	./LIBFT/ft_putendl_fd.c	\
			./LIBFT/ft_isascii.c	./LIBFT/ft_memmove.c	./LIBFT/ft_strchr.c		./LIBFT/ft_itoa.c		./LIBFT/ft_putnbr_fd.c	\
			./LIBFT/ft_isdigit.c	./LIBFT/ft_memset.c		./LIBFT/ft_strtrim.c 	./LIBFT/ft_strmapi.c \

SRCS = fract_ol.c errors.c initialize.c rendering.c some_math.c events.c

LIB_OBJS = $(LIB_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

C_MLX =  -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(C_MLX) -o $(NAME) 

$(LIBFT): $(LIB_OBJS)
	ar rcs $(LIBFT) $(LIB_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(LIB_OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re all
