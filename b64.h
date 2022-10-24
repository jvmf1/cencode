#pragma once
#include <stddef.h>

void b64_encode(unsigned char *data, size_t len, char *dest);
void b64_decode(char *data, size_t len, unsigned char *dest);
