CC=cc
CFLAGS=-Wall

test-hex: test-hex.c hex.o
	$(CC) $(CFLAGS) $^ -o $@

hex.o: hex.c hex.h
	$(CC) $< -c

