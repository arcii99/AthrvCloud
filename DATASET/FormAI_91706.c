//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

// Function to check website availability
bool isWebsiteAvailable(char* url) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        // Set URL and options for request
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        // Check if request was successful
        if(res == CURLE_OK) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    // Array of websites to monitor
    char* websites[]={"https://www.google.com", "https://www.facebook.com", "https://www.youtube.com"};
    // Number of websites in array
    int numWebsites = sizeof(websites)/sizeof(websites[0]);
    // Infinite loop to repeatedly check website availability
    while(true) {
        // Iterate through array of websites
        for(int i = 0; i < numWebsites; i++) {
            // Check website availability
            bool available = isWebsiteAvailable(websites[i]);
            // Print website status
            if(available) {
                printf("%s is up\n", websites[i]);
            } else {
                printf("%s is down\n", websites[i]);
            }
        }
        // Wait for 5 seconds before checking website availability again
        sleep(5);
    }
    return 0;
}