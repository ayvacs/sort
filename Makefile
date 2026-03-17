CC = gcc
CFLAGS = -Wall -Wextra -I.

OBJ = sort_bubble.o sort_insertion.o sort_merge.o sort_quick.o sort_selection.o

LIB = libsort.a

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIB)

.PHONY: all clean