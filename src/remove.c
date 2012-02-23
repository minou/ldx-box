#include <stdio.h>
#include "ldx-box.h"

int remove(const char *pathname){
    static int (*sys_remove)(const char *) = NULL;
    if (!sys_remove) {
        if (!(*(void **)(&sys_remove) = dlsym(RTLD_NEXT,"remove"))){
            perror("cannot fetch system remove\n");
            exit(1);
        }
    }

    char *list_path;
    list_path = iniparser_getstring(ini, "remove:path", NULL);

    if (check(pathname, &list_path, ":")){
        /*printf("remove(%s)\n", pathname);*/
        return sys_remove(pathname);
    }
    /*printf("Access denied to file : %s\n", pathname);*/
    return -1;
}
