CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol
RM = rm -f

SRCS = fract_ol.c errors.c initialize.c rendering.c some_math.c events.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS =  -lmlx -lX11 -lXext -lm -O3

all: $(NAME)

$(NAME): $(OBJS) fract_ol.h
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) 


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

bonus: $(NAME)
	@echo "The bonus part is implemented with the mandatory part"

clean:
	$(RM) $(OBJS) 

fclean: clean 
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re all
