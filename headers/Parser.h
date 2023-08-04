#ifndef PARSER_H
#define PARSER_H

#include "json.hpp"
#include <string>
#include <time.h>
#include <iostream>

class Parser
{
private:
    /* data */
    std::string data;
public:
    Parser(std::string json);
    ~Parser();
    int get_timestamps();
};

#endif
