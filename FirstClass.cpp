#include <iostream>
#include <string>

class FirstClass
{
private:
    /* data */
    std::string start;
    std::string destination;
    
public:
    FirstClass(const std::string start, const std::string destination);
    ~FirstClass();
};

FirstClass::FirstClass(const std::string start, const std::string destination)
{
    this->start = start;
    this->destination = destination;
    std::cout << "Start is: " << this->start << std::endl;
    std::cout << "Target destination is: " << this->destination << std::endl;
}

FirstClass::~FirstClass()
{
    std::cout << "FirstClass instance is being destroyed!" << std::endl;
}
