#include <iostream>
#include <curl/curl.h>
#include <string>

//https://github.com/martinbenes1996/slovakrailways/blob/master/slovakrailways/common.py
//https://github.com/Zippersk/API-slovak-rail
class Requestor
{
private:
    /* data */
    CURL* curl;
    CURLcode res;
    // {"uicCode":"5614136","name":"Senica","image":null,"latitude":48.66592,"longitude":17.33427}
    std::string url = "https://app.zssk.sk/api/v1/route/?fromStation=5614136&toStation=BRATISLAVA&departure=true";
    //std::string url = "https://app.zssk.sk/api/v1/station/name/senica";
    std::string response;
    std::string api_key = "PDh^2-$-M]8(dG8E+Q,FR}zsfz\"Q~:N2pp\\ykmg9ZEgKVrh42PHS?^sQ6<3;X,?-";
    struct curl_slist* headers = nullptr;

    // Static callback function to handle the response data
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
        size_t totalSize = size * nmemb;
        output->append(static_cast<char*>(contents), totalSize);
        return totalSize;
    }

public:
    Requestor(/* args */);
    ~Requestor();
    int perform_request();
    int set_curl();
    std::string get_response();
};

Requestor::Requestor(/* args */)
{
    // Initialize libcurl
    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Error initializing libcurl" << std::endl;
        exit(1);
    }
}

int Requestor::set_curl(){
    // Set the URL to send the request to
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Set the write callback function to handle the response data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    /*curl_easy_setopt(curl, CURLOPT_SSL_VERIFYSTATUS, 1);            
    curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");
    curl_easy_setopt(curl, CURLOPT_CAPATH, "cacert.pem");*/

    //curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);

    // Setup the API key header
    std::string authHeader = "x-api-key: " + api_key;
    headers = curl_slist_append(headers, authHeader.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    return 0;
}

int Requestor::perform_request(){
    // Perform the HTTP GET request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Error performing HTTP GET request: " << curl_easy_strerror(res) << std::endl;
        //curl_easy_cleanup(curl);
        return 1;
    }

    // Print the response
    //std::cout << "Response: " << response << std::endl;

    return 0;
}

std::string Requestor::get_response(){
    return response;
}

Requestor::~Requestor()
{
    // Clean up the headers
    curl_slist_free_all(headers);

    // Clean up and close libcurl
    curl_easy_cleanup(curl);
}
