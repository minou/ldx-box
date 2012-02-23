#include <stdio.h>
#include "ldx-box.h"

FILE *fopen(const char *path, const char *mode) {
    static FILE *(*sys_fopen)(const char *, const char *) = NULL;
    if (!sys_fopen) {
        if (!(*(void **)(&sys_fopen) = dlsym(RTLD_NEXT,"fopen"))){
            perror("cannot fetch system fopen\n");
            exit(1);
        }
    }

    char *list_path;
    char name[20] = "fopen:mode_";
    strncat(name, mode, strlen(mode));
    list_path = iniparser_getstring(ini, name, NULL);

    if (check(path, &list_path, ":")){
        /*printf("fopen(%s, %s)\n", path, mode);*/
        return sys_fopen(path, mode);
    }
    /*printf("Access denied to file : %s\n", path);*/
    return NULL;
}
