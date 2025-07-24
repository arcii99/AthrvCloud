//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>
#include <unistd.h>

#define URL "http://www.example.com"
#define INTERVAL 10

bool is_up(char* url) {
    CURL *curl;
    CURLcode res;
 
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
 
        /* Perform the request */
        res = curl_easy_perform(curl);
 
        /* Check the response code */
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code == 200) {
                curl_easy_cleanup(curl);
                return true;
            }
        }
 
        /* cleanup curl stuff */
        curl_easy_cleanup(curl);
    }
    return false;
}

int main() {
    while (true) {
        bool up = is_up(URL);
        printf("%s is %s\n", URL, up ? "UP" : "DOWN");
        sleep(INTERVAL);
    }
    return 0;
}