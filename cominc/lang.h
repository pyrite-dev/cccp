#ifndef __LANG_H__
#define __LANG_H__

#include "../config.h"

typedef struct _ILanguageVtbl ILanguageVtbl;
typedef struct _ILanguage     ILanguage;

struct _ILanguageVtbl {
	void (*Compile)(ILanguage* self, const char* input);
};

struct _ILanguage {
	struct _ILanguageVtbl* lpVtbl;
};

#define ILanguage_Compile(self, input) ((ILanguageFrontEnd*)(self))->Compile((self), (input))

#endif
