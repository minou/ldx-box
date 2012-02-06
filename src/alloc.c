#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void *malloc(size_t size){
    static void *(*sys_malloc)(size_t) = NULL;
    if (!sys_malloc) {
        if (!(sys_malloc = 
            (void *(*)(size_t))dlsym(RTLD_NEXT,"malloc"))) {
            perror("cannot fetch system malloc\n");
            exit(1);
        }
    }
    printf("malloc(%zu)\n", size);
    return sys_malloc(size);
}


void free(void *p){
    static void (*sys_free)(void *) = NULL;
    if (!sys_free) {
        if (!(sys_free = 
            (void (*)(void *)) dlsym(RTLD_NEXT, "free"))) {
            perror("cannot fetch system free\n");
            exit(2);
        }
    }
    printf("free(%p)\n", p); 
    sys_free(p);
}
