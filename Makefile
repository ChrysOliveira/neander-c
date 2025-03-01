CC = gcc
CFLAGS = -W -Wall -pedantic -std=c99
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = neander

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
