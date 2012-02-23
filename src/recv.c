#include <stdio.h>
#include "ldx-box.h"

int recv(int sockfd, void *buf, size_t len, int flags){
    static int (*sys_recv)(const char *) = NULL;
    if (!sys_recv) {
        if (!(*(void **)(&sys_recv) = dlsym(RTLD_NEXT,"recv"))){
            perror("cannot fetch system recv\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "recv:allow", NULL)){
//        printf("recv(%i,%i,%i,%i)\n", sockfd, buf, len, flags);
        return sys_recv(sockfd, buf, len, flags);
    }
    printf("Forbidden use of recv.");
    return -1;
}
