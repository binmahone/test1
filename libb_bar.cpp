//
// Created by hongbin on 23-3-20.
//

#include <iostream>
#include <cstring>
#include <malloc.h>

int liba_v_foo;
extern int yyy();

int func() {
    int mm = yyy();
    void *  x= malloc(100000000);
    memset(x,1,100000000);
    long sum = 0;
    int* p = static_cast<int*>(x);
    for(int i=0;i<100000000/sizeof(int);i++)
    {
        sum+=p[i];
    }
    std::cout << "in libb_bar:"<<sum << std::endl;
    free(x);




    return sum;
}
