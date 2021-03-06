#ifndef EX13_08_H
#define EX13_08_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &orig):
        ps(new std::string(*orig.ps)), i(orig.i) { }
    
    ~HasPtr() {
        delete ps;
    }

    HasPtr& operator=(const HasPtr &rhs)
    {
        i = rhs.i;
        *ps = *rhs.ps;
    }
private:
    std::string *ps;
    int i;
};

#endif
