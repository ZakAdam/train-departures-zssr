#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H

#include <iostream>
#include <string>

class FirstClass
{
private:
    std::string name;
    std::string address;

public:
    FirstClass(const std::string start, const std::string destination);
    ~FirstClass();
};

#endif
