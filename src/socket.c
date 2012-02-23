#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ldx-box.h"

int socket(int domain, int type, int protocol) {
    static int (*sys_socket)(int, int, int) = NULL;
    if (!sys_socket) {
        if (!(*(void **)(&sys_socket) = dlsym(RTLD_NEXT,"socket"))){
            perror("cannot fetch system socket\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "socket:allow", NULL)){
        printf("socket(%d, %d, %d)\n", domain, type, protocol);
        return sys_socket(domain, type, protocol);
    }
    printf("Forbidden use of socket\n");
    return -1;
}
