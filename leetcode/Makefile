CC = gcc
CFLAGS = -g -Wall
filename ?= 0

test: ./solutions/$(filename)
	@$(CC) $(CFLAGS) ./solutions/$(filename) -o test

clean:
	@rm test
