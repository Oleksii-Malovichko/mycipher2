# Компилятор и флаги
CC = cc
CFLAGS = 

SHUFFLE_SRC = shuffle_dir/shuffle.c shuffle_dir/itoa.c
UNSHUFFLE_SRC = unshuffle_dir/unshuffle.c unshuffle_dir/join.c
GET_NEXT_LINE_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SHUFFLE_OBJ = $(SHUFFLE_SRC:.c=.o)
UNSHUFFLE_OBJ = $(UNSHUFFLE_SRC:.c=.o)
GET_NEXT_LINE_OBJ = $(GET_NEXT_LINE_SRC:.c=.o)

SHUFFLE_EXEC = shuffle
UNSHUFFLE_EXEC = unshuffle

all: $(SHUFFLE_EXEC) $(UNSHUFFLE_EXEC)

$(SHUFFLE_EXEC): $(SHUFFLE_OBJ) $(GET_NEXT_LINE_OBJ)
	$(CC) $(SHUFFLE_OBJ) $(GET_NEXT_LINE_OBJ) -o $(SHUFFLE_EXEC)

$(UNSHUFFLE_EXEC): $(UNSHUFFLE_OBJ) $(GET_NEXT_LINE_OBJ)
	$(CC) $(UNSHUFFLE_OBJ) $(GET_NEXT_LINE_OBJ) -o $(UNSHUFFLE_EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SHUFFLE_OBJ) $(UNSHUFFLE_OBJ) $(GET_NEXT_LINE_OBJ) $(SHUFFLE_EXEC) $(UNSHUFFLE_EXEC)

fclean: clean
	rm -rf $(SHUFFLE_EXEC)
	rm -rf $(UNSHUFFLE_EXEC)
	rm -rf *.txt

re: clean all

.PHONY: all clean re fclean