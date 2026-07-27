#include "lang_bcpl_private.h"

CLanguageBCPL* CLanguageBCPL_New(void) {
	CLanguageBCPL* lang = malloc(sizeof(*lang));
	memset(lang, 0, sizeof(*lang));

	return lang;
}
