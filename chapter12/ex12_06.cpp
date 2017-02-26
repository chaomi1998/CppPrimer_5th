#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int>* make_vector()
{
    return new vector<int>();
}

void read(vector<int> *x)
{
    int num;
    while (cin >> num) {
        x->push_back(num);
    }
}

void print(vector<int> *x)
{
    for (auto num : *x) {
        cout << num << endl;
    }
}

int main()
{
    auto vec = make_vector();
    read(vec);
    print(vec);
    delete vec;
    vec = nullptr;
    return 0;
}
