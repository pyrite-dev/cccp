#include "ccc.h"

static int version(const char* argv0, const char* flag, const char* option) {
	printf("unCommon Compiler Collection Project %s - Copyright (C) 2026 Pyrite\n", VERSION);

	return 0;
}

static int help(const char* argv0, const char* flag, const char* option) {
	char pad[32];

	version(argv0, flag, option);

	printf("Usaqge: %s [options...] input(s)...\n", argv0);
	printf("General options:\n");

	str_padright(pad, "-v", 16);
	printf("  %s show version\n", pad);

	str_padright(pad, "-h", 16);
	printf("  %s show this help\n", pad);

	str_padright(pad, "-c", 16);
	printf("  %s compile and assemble, but do not link\n", pad);

	str_padright(pad, "-o <output>", 16);
	printf("  %s specify output\n", pad);

	str_padright(pad, "-x <language>", 16);
	printf("  %s specify language\n", pad);

	return 0;
}

static int compile(const char* argv0, const char* flag, const char* option) {
	return -1;
}

static int output(const char* argv0, const char* flag, const char* option) {
	return -1;
}

static int language(const char* argv0, const char* flag, const char* option) {
	return -1;
}

static cmd_command_t commands[] = {
    {"v", 0, version},
    {"h", 0, help},
    {"c", 0, compile},
    {"o", 1, output},
    {"x", 1, language},
    {NULL, 0, NULL}};

static int input(const char* argv0, const char* flag, const char* option) {
	return -1;
}

int main(int argc, char** argv) {
	int i;
	int st;

	if(argc == 1) {
		help(argv[0], "h", NULL);
		return 0;
	}

	if((st = cmd_option(argc, argv, commands, input)) != -1) return st;
}
