#include <stdio.h>
#include <dlfcn.h>

#include "iniparser.h"

FILE *fopen(const char *path, const char *mode) {
    static FILE *(*sys_fopen)(const char *, const char *) = NULL;
    if (!sys_fopen) {
        if (!(sys_fopen =
            (FILE *(*)(const char *, const char *))dlsym(RTLD_NEXT,"fopen"))) {
            perror("cannot fetch system fopen\n");
            exit(1);
        }
    }

    dictionary * ini;
    char       * ini_name;
    char * paths;
    ini_name = "config.ini";
    ini = iniparser_load(ini_name);
    printf("%s\n", mode);
    paths = iniparser_getstring(ini, "fopen:mode_r", NULL);
    printf("%s\n", paths);
    
    printf("fopen(%s)\n", path);
    return sys_fopen(path, mode);
}
