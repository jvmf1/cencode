#include "b64.h"
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

	unsigned char data[] = {0xde, 0xad, 0xbe, 0xef, 0x00, 0x11, 0x22};

	int padded_len = ((4 * sizeof(data) / 3) + 3) & ~3;

	char encoded[padded_len+1];
	unsigned char decoded[sizeof(data)] = {0};

	memset(encoded,0,sizeof(encoded));

	b64_encode(data, sizeof(data), encoded);

	assert(strcmp("3q2+7wARIg==", encoded) == 0);

	b64_decode(encoded, strlen(encoded), decoded);

	printf("%s\n", encoded);

	assert(arrcmp(decoded, data, sizeof(data)) == 0);

}
