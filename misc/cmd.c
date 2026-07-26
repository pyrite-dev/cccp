#include "misc.h"

int cmd_option(int argc, char** argv, cmd_command_t* commands, cmd_routine_t nonflag) {
	int i;

	for(i = 1; i < argc; i++) {
		int	      j;
		cmd_routine_t r = NULL;

		if(argv[i][0] != '-' && argv[i][0] != '/') {
			if(nonflag == NULL) {
				fprintf(stderr, "%s: %s: invalid argument\n", argv[0], argv[i]);

				return 1;
			} else {
				int st;

				if((st = nonflag(argv[0], NULL, argv[i])) != -1) return st;

				continue;
			}
		}

		for(j = 0; commands[j].command != NULL; j++) {
			const char* arg	   = NULL;
			int	    cmdlen = strlen(commands[j].command);
			int	    arglen = strlen(argv[i] + 1);
			int	    old	   = i;

			if(strcmp(commands[j].command, argv[i] + 1) == 0) { /* -opt val OR -opt */
				if(commands[j].option) {
					if((i + 1) < argc) arg = argv[++i];
				}

				r = commands[j].routine;
			} else if(commands[j].option && arglen >= (cmdlen + 1) && argv[i][1 + cmdlen] == '=' && memcmp(argv[i] + 1, commands[j].command, cmdlen) == 0) { /* -opt=val */
				arg = argv[i] + 1 + cmdlen + 1;

				r = commands[j].routine;
			} else if(commands[j].option && cmdlen == 1 && arglen >= cmdlen && argv[i][1] == commands[j].command[0]) { /* -optval */
				arg = argv[i] + 2;

				r = commands[j].routine;
			}

			if(r != NULL) {
				int st;

				if(arg == NULL && commands[j].option) {
					fprintf(stderr, "%s: %s: missing argument\n", argv[0], argv[i]);

					return 1;
				}

				if((st = r(argv[0], commands[j].command, arg)) != -1) return st;

				break;
			}
		}

		if(r == NULL) {
			fprintf(stderr, "%s: %s: invalid argument\n", argv[0], argv[i]);

			return 1;
		}
	}

	return -1;
}
