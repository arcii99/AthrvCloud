//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

// Define the website URL to monitor
#define WEBSITE_URL "http://www.google.com"

int main() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    // If curl is not initialized
    if (!curl) {
        fprintf(stderr, "Error initializing curl.\n");
        exit(EXIT_FAILURE);
    }

    // Set the URL to monitor
    curl_easy_setopt(curl, CURLOPT_URL, WEBSITE_URL);

    // Set options for the request
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Set timeout in seconds
    
    // Perform the request
    res = curl_easy_perform(curl);

    // If there was an error while performing the request
    if(res != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl); // Clean up the easy handle
        exit(EXIT_FAILURE);
    }

    // Get the response code
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    printf("Website Status: %ld\n", response_code);

    // Clean up the easy handle
    curl_easy_cleanup(curl);

    return 0;
}