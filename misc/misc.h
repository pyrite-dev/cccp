#ifndef __MISC_H__
#define __MISC_H__

#include "../config.h"

#include "stb_ds.h"

typedef int (*cmd_routine_t)(const char* flag, const char* option); /* return -1 to continue, otherwise, exit with the returned value */
typedef struct cmd_command cmd_command_t;

struct cmd_command {
	const char*   command;
	int	      option;
	cmd_routine_t routine;
};

/* cmd.c */
int cmd_option(int argc, char** argv, cmd_command_t* commands);

#endif
