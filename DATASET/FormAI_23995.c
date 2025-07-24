//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL "https://www.example.com"

// Define sleep interval in seconds
#define SLEEP_INTERVAL 60

int main(void) {
    CURL *curl;
    CURLcode res;

    // Set the URL to be monitored
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Enter an infinite loop to monitor the website
        for (;;) {
            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                printf("Website is down. Error code: %d\n", res);
            } else {
                printf("Website is up.\n");
            }

            sleep(SLEEP_INTERVAL);
        }

        // Clean up the CURL object
        curl_easy_cleanup(curl);
    }

    return 0;
}