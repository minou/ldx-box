#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ldx-box.h"

int listen(int sockfd, int backlog){
    static int (*sys_listen)(int, int) = NULL;
    if (!sys_listen) {
        if (!(*(void **)(&sys_listen) = dlsym(RTLD_NEXT,"listen"))){
            perror("cannot fetch system listen\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "listen:allow", NULL)){
        printf("listen(%d,%d)\n", sockfd, backlog);
        return sys_listen(sockfd, backlog);
    }
    printf("Forbidden use of listen\n");
    return -1;
}
