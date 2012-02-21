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

    if (ini==NULL)
        exit(1);

    char name[12] = "fopen:mode_";
    char *list_path;
    strncat(name, mode, 1);
    printf("Name : %s\n", name);
    list_path = iniparser_getstring(ini, name, NULL);
    printf("List path : %s\n", list_path);
    
    printf("fopen(%s, %s)\n", path, mode);
    return sys_fopen(path, mode);
}
