CC=cc
CFLAGS=-Wall

all: test-hex test-b64

test-b64: test-b64.c b64.o
	$(CC) $(CFLAGS) $^ -o $@

test-hex: test-hex.c hex.o
	$(CC) $(CFLAGS) $^ -o $@

hex.o: hex.c hex.h
	$(CC) $< -c

b64.o: b64.c b64.h
	$(CC) $< -c
