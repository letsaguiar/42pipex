CC := gcc
CFLAGS := -Wall -Wextra -Werror
CLIBS := -Llibft -lft
CINCLUDES := -Ilibft

SRC_FILES := $(wildcard *.c)
OBJ_FILES := $(subst .c,.o,$(SRC_FILES))

NAME := pipex

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	$(CC) $(CFLAGS) -o $@ $^ $(CLIBS) $(CINCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(CINCLUDES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
