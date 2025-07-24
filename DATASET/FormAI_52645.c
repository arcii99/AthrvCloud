//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

// Make sure CURL is installed before compiling

// Struct for storing website info
typedef struct {
    char* url;
    bool is_online;
    time_t last_checked;
} Website;

// Function to check if website is up
void check_website(Website* website) {
    CURL* curl = curl_easy_init();
    CURLcode res;
    if (curl) {
        // Set URL
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        // Set timeout
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
        // Perform HTTP request
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            website->is_online = true;
        } else {
            website->is_online = false;
        }
        curl_easy_cleanup(curl);
    }
}

int main() {
    Website websites[3];
    websites[0].url = "https://www.google.com";
    websites[1].url = "https://www.facebook.com";
    websites[2].url = "https://www.twitter.com";

    int num_websites = sizeof(websites) / sizeof(Website);

    // Check websites every 10 seconds
    while(true) {
        for(int i = 0; i < num_websites; i++) {
            time_t current_time = time(NULL);
            double diff_time = difftime(current_time, websites[i].last_checked);
            // Only check website if more than 10 seconds have elapsed since last check
            if (diff_time > 10) {
                check_website(&websites[i]);
                websites[i].last_checked = current_time;
                if (websites[i].is_online) {
                    printf("%s is online\n", websites[i].url);
                } else {
                    printf("%s is offline\n", websites[i].url);
                }
            }
        }
    }

    return 0;
}