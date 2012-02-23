#include <stdio.h>
#include "ldx-box.h"

int send(int sockfd, const void *buf, size_t len, int flags){
    static int (*sys_send)(const char *) = NULL;
    if (!sys_send) {
        if (!(*(void **)(&sys_send) = dlsym(RTLD_NEXT,"send"))){
            perror("cannot fetch system send\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "send:allow", NULL)){
//        printf("send(%i,%i,%i,%i)\n", sockfd, buf, len, flags);
        return sys_send(sockfd, buf, len, flags);
    }
    printf("Forbidden use of send.");
    return -1;
}
