#include <iostream>
#include <vector>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::make_shared;
using std::shared_ptr;

shared_ptr<vector<int>> make_vec()
{
    return make_shared<vector<int>>();
}

shared_ptr<vector<int>> read()
{
    auto vec = make_vec();
    int num;
    while (cin >> num) {
        vec->push_back(num);
    }
    return vec;
}

void print()
{
    auto nums = read();
    for (auto n : *nums) {
        cout << n << endl;
    }
}

int main()
{
    print();
    return 0;
}
