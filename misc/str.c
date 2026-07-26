#include "misc.h"

void str_padleft(char* out, const char* in, int len) {
	int i;

	out[0] = 0;

	for(i = 0; i < (len - strlen(in)); i++) {
		strcat(out, " ");
	}

	strcat(out, in);
}

void str_padright(char* out, const char* in, int len) {
	strcpy(out, in);
	while(strlen(out) < len) {
		strcat(out, " ");
	}
}
