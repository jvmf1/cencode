#include "hex.h"

void hex_encode(unsigned char *data, size_t len, char *dest) {
	unsigned char a;
	unsigned char b;
	for (size_t i = 0 ; i < len; i++) {
		a = data[i] >> 4;
		b = data[i] & 0x0F;
		if (b < 10)
			b+='0';
		else
			b+='a'-10;
		if (a < 10)
			a+='0';
		else
			a+='a'-10;
		*dest=a;
		*(dest+1)=b;
		dest+=2;
	}
}

void hex_decode(char *data, size_t len, unsigned char *dest) {
	unsigned char a;
	unsigned char b;
	for (size_t i = 0 ; i < len/2; i ++) {
		a = *data;
		b = *(data+1);
		data+=2;
		if (b >= 'a')
			b-='a'-10;
		else
			b-='0';
		if (a >= 'a')
			a-='a'-10;
		else
			a-='0';
		dest[i] = b + (a << 4);
	}
}
