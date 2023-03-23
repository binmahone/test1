//
// Created by hongbin on 23-3-20.
//

#include "liba_foo.h"

extern int libb_bar_v;
int liba_v_foo;

int liba_foo::func() {
    return 10 + liba_v_foo + libb_bar_v;
}

int xxx = 10;