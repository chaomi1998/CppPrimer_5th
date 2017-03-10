#include "ex13_13.h"

int main()
{
    X x1;
    X x2(x1);
    X x3 = x2;
    x1 = x3;
    return 0;
}
