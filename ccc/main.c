#include "ccc.h"

static int help(const char* flag, const char* option) {
	char pad[16];

	printf("unCommon Compiler Collection Project %s - Copyright (C) 2026 Pyrite\n", VERSION);
	printf("Usaqge: ccc [options...] input(s)...\n");
	printf("General options:\n");

	str_padright(pad, "-h", 8);
	printf("  %s show this help\n", pad);

	return 0;
}

static cmd_command_t commands[] = {
    {"h", 0, help},
    {NULL, 0, NULL}};

int main(int argc, char** argv) {
	int i;
	int st;

	if(argc == 1) {
		help("h", NULL);
		return 0;
	}

	if((st = cmd_option(argc, argv, commands)) != -1) return st;
}
