//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define the target website URL
#define URL "https://www.example.com"

// Define the threshold for website response time (in ms)
#define RESPONSE_THRESHOLD 500

// Function that handles the CURL response
size_t curl_callback(char *data, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

// Function that checks website uptime
void monitor_website() {
    CURL *curl;
    CURLcode res;
    double response_time;

    while (1) {
        curl = curl_easy_init();

        // Set the URL to monitor
        curl_easy_setopt(curl, CURLOPT_URL, URL);

        // Set the callback function to handle the CURL response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_callback);

        // Measure the website response time
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, 1);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, RESPONSE_THRESHOLD);
        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &response_time);

        // Print the status of the website based on the response time
        if (res == CURLE_OK) {
            if (response_time >= RESPONSE_THRESHOLD) {
                printf("The website is slow to respond.\n");
            } else {
                printf("The website is up and running smoothly.\n");
            }
        } else {
            printf("The website is down.\n");
        }

        curl_easy_cleanup(curl);
    }
}

// Main function
int main() {
    printf("Welcome to the Sherlock Holmes Website Uptime Monitor!\n");
    printf("Checking the status of %s every %d ms...\n", URL, RESPONSE_THRESHOLD);

    // Call the monitor_website function
    monitor_website();

    return 0;
}