#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

int main()
{
    list<string> str;
    string val;
    while (cin >> val) {
        if (val == "end") {
            break;
        }
        str.push_back(val);
    }
    string fs;
    while (cin >> fs) {
        int result = count(str.cbegin(), str.cend(), fs);
        cout << result << endl;
    }
    return 0;
}
