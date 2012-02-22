#include <dlfcn.h>
#include "iniparser.h"

dictionary * ini;

int check(const char * path, char ** list, char * delimiter);
