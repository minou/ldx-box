#include <stdio.h>
#include "ldx-box.h"
#include <stdlib.h>

FILE *fopen(const char *path, const char *mode) {
    static FILE *(*sys_fopen)(const char *, const char *) = NULL;
    if (!sys_fopen) {
        if (!(*(void **)(&sys_fopen) = dlsym(RTLD_NEXT,"fopen"))){
            perror("cannot fetch system fopen\n");
            exit(1);
        }
    }

    char *list_path, *token;
    char name[20] = "fopen:mode_";
    strncat(name, mode, strlen(mode));
    list_path = iniparser_getstring(ini, name, NULL);

    while (token = strsep(&list_path, ":")){
        if (token[0] == '$')
            token = getenv(++token);
        if (strncmp(token, path, strlen(token)) == 0){
            printf("fopen(%s, %s)\n", path, mode);
            return sys_fopen(path, mode);
        }
    }
    printf("Access denied to file : %s\n", path);
    return NULL;
}
