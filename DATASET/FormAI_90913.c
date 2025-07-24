//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>

// Define the URL to monitor
#define URL "https://www.example.com"

// Define the interval between checks in seconds
#define INTERVAL 60

int main(void) {
    CURL *curl;
    CURLcode res;
    bool is_up = false;
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    while(true) {
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, URL);
            res = curl_easy_perform(curl);
            if(res == CURLE_OK) {
                int http_code = 0;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
                if(http_code == 200) {
                    if(!is_up) {
                        printf("%s is back up!\n", URL);
                        is_up = true;
                    }
                } else {
                    printf("%s returned an HTTP code of %d!\n", URL, http_code);
                    is_up = false;
                }
            } else {
                printf("%s is down!\n", URL);
                is_up = false;
            }
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
        sleep(INTERVAL);
    }
    return 0;
}