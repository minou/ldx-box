#include <stdio.h>
#include "ldx-box.h"

int socket(int socket_family, int socket_type, int protocol){
    static int (*sys_socket)(const char *) = NULL;
    if (!sys_socket) {
        if (!(*(void **)(&sys_socket) = dlsym(RTLD_NEXT,"socket"))){
            perror("cannot fetch system socket\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "socket:allow", NULL)){
        printf("socket(%i,%i,%i)\n", socket_family, socket_type, protocol);
        return sys_socket(socket_family, socket_type, protocol);
    }
    printf("Forbidden use of socket.");
    return -1;
}
