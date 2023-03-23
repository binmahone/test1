//#include <boost/filesystem.hpp>
#include <iostream>
#include "liba_foo.h"
#include <cstdlib>

//#include <glog/logging.h>
//using namespace boost::filesystem;

#include <cstring>
#include <malloc.h>

extern int xxx;


int yyy() {
    return 90;
}

int main()
{
    std::cout << "yyy is : " << yyy() << std::endl;
    void *  x= malloc(100000000);
    memset(x,1,100000000);
    long sum = 0;
    int* p = static_cast<int*>(x);
    for(int i=0;i<100000000/sizeof(int);i++)
    {
        sum+=p[i];
    }
    std::cout << sum << std::endl;
    free(x);

    struct mallinfo minfo = mallinfo();
    printf("Total number of bytes allocated: %d\n", minfo.uordblks);
    printf("Number of chunks allocated: %d\n", minfo.ordblks);
    printf("Number of chunks in use: %d\n", minfo.hblks);
    printf("Number of bytes in use: %d\n", minfo.arena);
    return 0;

//    path p{"/tmp/cachelib"};
//    std::cout << p.generic_string() << '\n';
//
////    google::InitGoogleLogging("INFO");
////    LOG(INFO) << "hello log" ;
//
//
//    auto x = std::locale::classic();
}
