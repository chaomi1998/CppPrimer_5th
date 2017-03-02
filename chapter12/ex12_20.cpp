#include <iostream>
#include <fstream>
#include <string>

#include "ex12_19.h"

using std::ifstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    ifstream input(argv[1]);
    StrBlob str;
    string line;
    while (getline(cin, line)) {
        str.push_back(line);
    }

    for (auto i = str.begin(); i != str.end(); i.incr()) {  //can't run with "!="
        cout << i.deref();
    }
    cout << endl;
    return 0;
}
