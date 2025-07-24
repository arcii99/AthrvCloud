//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Define the URL to monitor
#define URL "http://example.com"

// Define the maximum number of retries if the website is down
#define MAX_RETRIES 3

int main() {
    CURL *curl;
    CURLcode res;
    int retries = 0;

    // Initialize curl
    curl = curl_easy_init();

    // Check if curl init was successful
    if (curl) {
        while (retries < MAX_RETRIES) {
            // Set the URL to monitor
            curl_easy_setopt(curl, CURLOPT_URL, URL);

            // Set a timeout of 5 seconds
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

            // Perform the request
            res = curl_easy_perform(curl);

            // Check if the request was successful
            if (res == CURLE_OK) {
                printf("%s is UP\n", URL);
                break;
            } else {
                printf("%s is DOWN\n", URL);
                retries++;
            }
        }

        // Cleanup curl
        curl_easy_cleanup(curl);
    }

    return 0;
}