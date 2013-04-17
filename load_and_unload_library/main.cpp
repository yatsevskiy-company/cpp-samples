#include <stdio.h>
#include <dlfcn.h>
#include <ctest.h>
#include <stdlib.h>

#include <interface.h>



int main(int argc, char *argv[]) {
    void *handle;
    interface * (*newInstance)();
    void (*release)(interface*oldInstance);

    int x;
    char *error;

    handle = dlopen("./libctest.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    newInstance = (interface * ( *)()) dlsym(handle, "_ZN9interface11newInstanceEv");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    release = (void ( *)(interface *)) dlsym(handle, "_ZN9interface7releaseEPS_");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    interface *i = (*newInstance)();

    i->a(&x);
    printf("%x\n", x);
    i->b(&x);
    printf("%x\n", x);
    i->c(&x);
    printf("%x\n", x);
    i->d(&x);
    printf("%x\n", x);
    delete i;
    //    (*release)(i);


    dlclose(handle);
    return 0;
}
