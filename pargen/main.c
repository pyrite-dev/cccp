#include "pargen.h"

static int version(const char* argv0, const char* flag, const char* option) {
	printf("%s\n", COPYRIGHT("Parser Generator", PARGEN_VERSION));

	return 0;
}

static int help(const char* argv0, const char* flag, const char* option) {
	char pad[32];

	version(argv0, flag, option);

	return 0;
}

static cmd_command_t commands[] = {
    {"v", 0, version},
    {"h", 0, help},
    {NULL, 0, NULL}};

static FILE** files = NULL;

static int input(const char* argv0, const char* flag, const char* option) {
	FILE* f;

	if((f = fopen(option, "r")) == NULL) {
		fprintf(stderr, "%s: cannot open file `%s'\n", argv0, option);
		return 1;
	}

	arrput(files, f);

	return -1;
}

int main(int argc, char** argv) {
	int st;

	if(argc == 1) {
		help(argv[0], "h", NULL);
		return 0;
	}

	if((st = cmd_option(argc, argv, commands, input)) != -1) return st;
}
