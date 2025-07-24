//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define your website URL here
#define WEBSITE_URL "https://www.example.com"

// Define the timeout for curl operations
#define CURL_TIMEOUT 10

// Define the sleep time between checks
#define SLEEP_TIME 60

int check_website() {
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, WEBSITE_URL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, CURL_TIMEOUT);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        return (res == CURLE_OK);
    }
    return 0;
}

int main() {
    while(1) {
        int status = check_website();
        if(status) {
            printf("%s is online!\n", WEBSITE_URL);
        } else {
            printf("%s is offline!\n", WEBSITE_URL);
        }

        sleep(SLEEP_TIME);
    }

    return 0;
}