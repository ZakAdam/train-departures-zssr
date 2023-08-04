#include "headers/json.hpp"
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

Parser::Parser(std::string json)
{
    data = json;
}

int Parser::get_timestamps(){
    nlohmann::json parsed_json = nlohmann::json::parse(data);

    /*std::cout << "---------------------------------------------------------------------------------- \n";
    std::cout << "Departure: " << parsed_json[0]["departureTimestamp"] << "\n";
    std::cout << "Arrival: " << parsed_json[0]["arrivalTimestamp"] << "\n";
    std::cout << "---------------------------------------------------------------------------------- \n";*/
    
    time_t departure = parsed_json[0]["departureTimestamp"];
    time_t arrival = parsed_json[0]["arrivalTimestamp"];

    time_t departure_human = departure / 1000;
    time_t arrival_human = arrival / 1000;

    std::cout << "\n---------------------------------------------------------------------------------- \n";
    std::cout << "Departure: " << ctime(&departure_human) << "\n";
    std::cout << "  Arrival: " << ctime(&arrival_human);
    std::cout << "---------------------------------------------------------------------------------- \n";

    return 0;
}

Parser::~Parser()
{
}
