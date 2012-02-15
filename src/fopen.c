#include <stdio.h>
#include "ldx-box.h"

FILE *fopen(const char *path, const char *mode) {
    static FILE *(*sys_fopen)(const char *, const char *) = NULL;
    if (!sys_fopen) {
        if (!(sys_fopen =
            (FILE *(*)(const char *, const char *))dlsym(RTLD_NEXT,"fopen"))) {
            perror("cannot fetch system fopen\n");
            exit(1);
        }
    }

    char * mode_r;
    mode_r = iniparser_getstring(ini, "fopen:mode_r", NULL);
    printf("%s\n", mode_r);
    
    printf("fopen(%s, %s)\n", path, mode);
    return sys_fopen(path, mode);
}
