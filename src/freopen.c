#include <stdio.h>
#include "ldx-box.h"

FILE *freopen(const char *path, const char *mode, FILE *stream) {
    static FILE *(*sys_freopen)(const char *, const char *, FILE *) = NULL;
    if (!sys_freopen) {
        if (!(*(void **)(&sys_freopen) = dlsym(RTLD_NEXT,"freopen"))){
            perror("cannot fetch system freopen\n");
            exit(1);
        }
    }

    char *list_path;
    char name[20] = "freopen:mode_";
    strncat(name, mode, strlen(mode));
    list_path = iniparser_getstring(ini, name, NULL);

    if (check(path, &list_path, ":")){
        printf("freopen(%s, %s, ...)\n", path, mode);
        return sys_freopen(path, mode, stream);
    }
    printf("Access denied to file : %s\n", path);
    return NULL;
}
