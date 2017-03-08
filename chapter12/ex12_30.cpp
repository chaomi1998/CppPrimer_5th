#include <fstream>
#include <iostream>
#include <string>

#include "ex12_30.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char* argv[])
{
    if (argc == 1) {
        std::cerr << "Error: no data" << endl;
        return -1;
    }
    ifstream input(argv[1]);
    runQueries(input);
    return 0;
}
