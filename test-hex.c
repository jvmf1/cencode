#include "hex.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

size_t arrcmp(const unsigned char *a, const unsigned char *b, size_t len) {
	for (size_t i = 0; i < len; i++) {
		if (a[i] - b[i] != 0)
			return a[i] - b[i];
	}
	return 0;
}

int main() {

	unsigned char data[] = {0x4e, 0xa1, 0x13, 0xff, 0x99};
	char encoded[(sizeof(data)*2)+1] = {0};
	unsigned char decoded[sizeof(data)] = {0};
	char a = 'b';

	hex_encode(data, sizeof(data), encoded);

	printf("%s\n", encoded);

	assert(strcmp("4ea113ff99", encoded) == 0);

	hex_decode(encoded, strlen(encoded), decoded);

	assert(arrcmp(data, decoded, sizeof(data)) == 0);
}
