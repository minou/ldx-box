#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ldx-box.h"

ssize_t send(int sockfd, const void *buf, size_t len, int flags){
    static ssize_t (*sys_send)(int, const void *, size_t, int) = NULL;
    if (!sys_send) {
        if (!(*(void **)(&sys_send) = dlsym(RTLD_NEXT,"send"))){
            perror("cannot fetch system send\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "send:allow", NULL))
        return sys_send(sockfd, buf, len, flags);
    printf("Forbidden use of send\n");
    return -1;
}
