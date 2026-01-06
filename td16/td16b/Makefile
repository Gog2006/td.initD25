

CC = gcc
CFLAGS = -Wall -Werror -std=c23

SRC = ex2.c

OBJ = $(SRC:.c=.o)

EXEC = ex2

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)
