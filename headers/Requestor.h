#ifndef REQUESTOR_H
#define REQUESTOR_H

#include <iostream>
#include <curl/curl.h>
#include <string>

class Requestor
{
private:
    CURL* curl;
    CURLcode res;
    std::string url = "https://jsonplaceholder.typicode.com/posts/1";
    std::string response;
    std::string api_key;
    struct curl_slist* headers;
public:
    Requestor();
    ~Requestor();

    size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
    int perform_request();
    int set_curl();
    std::string get_response();
};

#endif