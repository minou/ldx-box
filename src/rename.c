#include <stdio.h>
#include "ldx-box.h"

int rename(const char *oldpath, const char *newpath) {
    static int (*sys_rename)(const char *, const char *) = NULL;
    if (!sys_rename) {
        if (!(*(void **)(&sys_rename) = dlsym(RTLD_NEXT,"rename"))){
            perror("cannot fetch system rename\n");
            exit(1);
        }
    }

    char *src_list, *dest_list;
    src_list = iniparser_getstring(ini, "rename:src", NULL);
    dest_list = iniparser_getstring(ini, "rename:dest", NULL);

    if (check(oldpath, &src_list, ":") && check(newpath, &dest_list, ":")){
        printf("rename(%s, %s)\n", oldpath, newpath);
        return sys_rename(oldpath, newpath);
    }
    printf("Access denied to file : %s or %s\n", oldpath, newpath);
    return -1;
}
