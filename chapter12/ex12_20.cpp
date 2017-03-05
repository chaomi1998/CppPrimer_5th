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
    while (getline(input, line)) {
        str.push_back(line);
    }

    for (auto i = str.begin(); i.deref() != str.back(); i.incr()) {  
        cout << i.deref() << "\n";
    }
    cout << endl;
    return 0;
}
