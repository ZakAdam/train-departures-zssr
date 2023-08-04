#include <iostream>
#include <getopt.h>
#include "headers/FirstClass.h"
#include "headers/Requestor.h"
#include "headers/Parser.h"

int main(int argc, char **argv) {
    std::string start = "Senica";
    std::string destination = "Bratislava";

    // Define the long options
    static struct option long_options[] = {
        {"start", required_argument, 0, 's'},
        {"destination", required_argument, 0, 'd'},
        {"reverse", no_argument, 0, 'r'},
        {0, 0, 0, 0} // Terminate the options array
    };

    // Parse the command-line arguments
    int option_index = 0;
    int opt;
    while ((opt = getopt_long(argc, argv, "sdr:", long_options, &option_index)) != -1) {
        switch (opt) {
            case 's':
                start = optarg; // Store the value of --start option
                break;
            case 'd':
                destination = optarg; // Store the value of --start option
                break;
            case 'r':
                start = "Bratislava";
                destination = "Senica";
                break;
            case '?':
                // Invalid option or missing argument
                std::cerr << "Invalid option or missing argument." << std::endl;
                return 1;
            default:
                break;
        }
    }

    FirstClass first_class(start, destination);

    Requestor requestor;
    requestor.set_curl();
    requestor.perform_request();

    Parser parser(requestor.get_response());
    parser.get_timestamps();

    return 0;
}