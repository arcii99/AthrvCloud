//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define the URL to monitor
#define URL "https://www.example.com"

// Define the time interval to check the URL in seconds
#define INTERVAL 60

int main(void) {
    CURL *curl_handle;
    CURLcode res;
    double connect_time;

    // Loop infinitely to continuously monitor the URL
    while (1) {
        // Initialize the curl handle
        curl_global_init(CURL_GLOBAL_ALL);
        curl_handle = curl_easy_init();
        if (!curl_handle) {
            fprintf(stderr, "Error: unable to initialize curl\n");
            exit(EXIT_FAILURE);
        }

        // Set the URL to monitor
        curl_easy_setopt(curl_handle, CURLOPT_URL, URL);

        // Disable progress meter, set timeout and follow redirects
        curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);

        // Perform the HTTP request
        res = curl_easy_perform(curl_handle);

        // Get the total time of the request
        curl_easy_getinfo(curl_handle, CURLINFO_CONNECT_TIME, &connect_time);

        // Check the HTTP response code
        if (res != CURLE_OK) {
            fprintf(stderr, "Error: unable to connect to %s\n", URL);
            fprintf(stderr, "Curl error: %s\n", curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code == 200) {
                printf("The website %s is UP and running.\n", URL);
            } else {
                fprintf(stderr, "Error: %s returned HTTP status %ld\n", URL, response_code);
            }
        }

        // Cleanup before waiting for next iteration
        curl_easy_cleanup(curl_handle);
        curl_global_cleanup();

        // Wait for INTERVAL seconds before checking again
        printf("Waiting for %d seconds before next check...\n", INTERVAL);
        sleep(INTERVAL);
    }

    return 0;
}