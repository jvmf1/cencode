#pragma once
#include <stddef.h>

void hex_encode(unsigned char *data, size_t len, char *dest);
void hex_decode(char *data, size_t len, unsigned char *dest);
