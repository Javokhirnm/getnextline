CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = \
	./get_next_line.c \
	./get_next_line_utils.c \

OBJ = $(SRC:.c=.o) 

NAME = get_next_line.a

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all