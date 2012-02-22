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

    char *list_path, *token, *result[20];
    char name[20] = "fopen:mode_";
    strncat(name, mode, strlen(mode));
    list_path = iniparser_getstring(ini, name, NULL);

    /* print */
    int i = 0;
    printf("Mode, list path : %s, %s\n", name, list_path);
    while ((token = strsep(&list_path, ":"))){
        result[i] = token;
        printf("%d, %s\n", i, result[i]);
        i++;
    }
    
    printf("fopen(%s, %s)\n", path, mode);
    return sys_fopen(path, mode);
}
