#include <stdio.h>
#include "ldx-box.h"

FILE *tmpfile(void) {
    static FILE *(*sys_tmpfile)() = NULL;
    if (!sys_tmpfile) {
        if (!(*(void **)(&sys_tmpfile) = dlsym(RTLD_NEXT,"tmpfile"))){
            perror("cannot fetch system tmpfile\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "tmpfile:allow", NULL))
        return sys_tmpfile();
    printf("Forbidden use of tmpfile\n");
    return NULL;
}
