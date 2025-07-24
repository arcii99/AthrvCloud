//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

#define URL "https://www.example.com"

int main() {
    CURL *curl;
    CURLcode res;
    bool isUp = true;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
            isUp = false;
        }
        
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
    
    if(isUp) {
        printf("The website %s is up and running smoothly!\n", URL);
    }
    else {
        printf("Oh no! The website %s seems to be down. Please check it out!\n", URL);
    }
    
    return 0;
}