#include <iostream>
#include <cstring>
#include <dlfcn.h>
#include <malloc.h>

extern int func();

extern int yyy();

int main() {
    void *x = malloc(100000000);
    memset(x, 1, 100000000);
    long sum = 0;
    int *p = static_cast<int *>(x);
    for (int i = 0; i < 100000000 / sizeof(int); i++) {
        sum += p[i];
    }
    std::cout << sum << std::endl;


    {
        //func();

        char *error;
        void *libHandle;
        int (*cosine)(void);

        // open the library
        libHandle = dlopen("/home/hongbin/CLionProjects/test1/cmake-build-debug/liblibb.so", RTLD_LAZY);
        if (!libHandle) {
            std::cerr << "Cannot open library: " << dlerror() << std::endl;
            return 1;
        }

// load the symbol
        cosine = (int (*)(void)) dlsym(libHandle, "_Z4funcv");
        if ((error = dlerror()) != NULL) {
            std::cerr << "Cannot load symbol 'cosine': " << error << std::endl;
            return 1;
        }

// use it to do the calculation
        std::cout << "func() = " << (*cosine)() << std::endl;

    }



    struct mallinfo minfo = mallinfo();
    printf("Total number of bytes allocated: %d\n", minfo.uordblks);
    printf("Number of chunks allocated: %d\n", minfo.ordblks);
    printf("Number of chunks in use: %d\n", minfo.hblks);
    printf("Number of bytes in use: %d\n", minfo.arena);


//    free(x);


//    path p{"/tmp/cachelib"};
//    std::cout << p.generic_string() << '\n';
//
////    google::InitGoogleLogging("INFO");
////    LOG(INFO) << "hello log" ;
//
//
//    auto x = std::locale::classic();
}
