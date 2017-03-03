#include <memory>
#include <iostream>

using std::cout;
using std::endl;
using std::allocator;

int main()
{
    allocator<int> alloc;
    auto const p = alloc.allocate(10);
    auto q = p;
    alloc.construct(q++, 8);
    alloc.construct(q++, 8);
    alloc.construct(q++, 8);
    alloc.construct(q++, 8);
    alloc.construct(q++, 8);
    cout << *p << endl;
    while (q != p) {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, 10);
    return 0;
}
