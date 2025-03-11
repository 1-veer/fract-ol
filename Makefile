CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = fractol
RM = rm -f

SRCS = fract_ol.c errors.c initialize.c rendering.c some_math.c events.c

OBJS = $(SRCS:.c=.o)

C_MLX =  -lmlx -lX11 -lXext -lm -O3

all: $(NAME)
$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS)  $(C_MLX) -o $(NAME) 


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 

fclean: clean 
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re all