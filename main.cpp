#include <iostream>
#include <cstring>

extern int func();
extern int yyy();

int main()
{
    void *  x= malloc(100000000);
    memset(x,1,100000000);
    long sum = 0;
    int* p = static_cast<int*>(x);
    for(int i=0;i<100000000/sizeof(int);i++)
    {
        sum+=p[i];
    }
    std::cout << sum << std::endl;


    func();

    free(x);


//    path p{"/tmp/cachelib"};
//    std::cout << p.generic_string() << '\n';
//
////    google::InitGoogleLogging("INFO");
////    LOG(INFO) << "hello log" ;
//
//
//    auto x = std::locale::classic();
}
