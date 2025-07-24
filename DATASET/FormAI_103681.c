//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

#define URL "https://www.example.com"

bool isWebsiteUp() {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            curl_easy_cleanup(curl);
            return true;
        } else {
            curl_easy_cleanup(curl);
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    while(true) {
        if(isWebsiteUp()) {
            printf("The website is up and running, you can go ahead and enjoy your day!");
        } else {
            printf("Oh no, the website is down! Quick, call the developers!");
        }
        sleep(60); // wait one minute before checking again
    }
    return 0;
}