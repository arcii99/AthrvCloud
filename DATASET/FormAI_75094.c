//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Callback function for writing data received from curl request
static size_t WriteCallback(void *buffer, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int main(int argc, char* argv[]) {
    CURL *curl;
    CURLcode response;

    curl_global_init(CURL_GLOBAL_ALL);

    // Set url to be checked for uptime
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

        // Set callback function for writing received data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Set timeout for request to 10 seconds
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

        // Perform request
        response = curl_easy_perform(curl);

        // Check if response code is valid and print status
        if(response != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(response));
            printf("Website is down\n");
        } else {
            printf("Website is up\n");
        }

        // Cleanup resources
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}