//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

// Website Uptime Monitor
// This program checks if a given website is up and running
// by sending a HTTP GET request and checking the response code

// Struct to hold website information
typedef struct website_info {
    char* name;
    char* url;
    int timeout;
} website_info;

// Function to send HTTP GET request
// Returns true if website is up and running, false otherwise
bool check_website(const char* url, int timeout) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        // Set curl options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
        // Send HTTP request
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        // Check response code
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code == 200) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Initialize website info
    website_info sites[] = {
        {"Google", "https://www.google.com", 5},
        {"Facebook", "https://www.facebook.com", 10},
        {"Twitter", "https://www.twitter.com", 15}
    };
    // Get number of websites to monitor
    int num_sites = sizeof(sites)/sizeof(sites[0]);
    while(true) {
        for(int i = 0; i < num_sites; i++) {
            // Send HTTP GET request to website and check if it's up
            bool is_up = check_website(sites[i].url, sites[i].timeout);
            if(is_up) {
                printf("%s is up and running!\n", sites[i].name);
            }
            else {
                printf("%s is down!\n", sites[i].name);
            }
        }
        // Wait 1 minute before checking again
        sleep(60);
    }
    return 0;
}