#include <iostream>
#include <memory>
#include <cstring>
#include <string>

using std::cout;
using std::endl;
using std::size_t;
using std::string;

int main()
{
    char c1[] = "Hello";
    char c2[] = "World";
    size_t len = strlen(c1) + strlen(c2);
    char *ch = new char[len]();
    strcpy(ch, strcat(c1, c2));
    cout << "C style :" << ch << "\n";

    string s1 = "ni";
    string s2 = "hao";
    len = s1.size() + s2.size();
    char *str = new char[len]();
    strcpy(str, s1.append(s2).c_str());
    cout << "String :" << str << endl;
    delete [] ch;
    delete [] str;
    return 0;
}
