//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define URL "https://www.example.com"
#define TIMEOUT 10 // seconds

void check_website() {
    CURL *curl;
    CURLcode res;
    char error[CURL_ERROR_SIZE] = "";

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error);
        
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", error);
        } else {
            printf("Website is up!\n");
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main() {
    while(1) {
        check_website();
        sleep(60); // check every minute
    }
    return 0;
}