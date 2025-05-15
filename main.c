#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void* handle;
    void (*hello_vector)();
    int (*add)(int, int);

    
    handle = dlopen("./libvector.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error loading library: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    
    *(void **)(&hello_vector) = dlsym(handle, "hello_vector");
    if (!hello_vector) {
        fprintf(stderr, "Error finding function: %s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

    
    *(void **)(&add) = dlsym(handle, "add");
    if (!add) {
        fprintf(stderr, "Error finding function: %s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

    
    hello_vector();
    int result = add(5, 7);
    printf("Result of add(5, 7): %d\n", result);

    
    dlclose(handle);

    return 0;
}
