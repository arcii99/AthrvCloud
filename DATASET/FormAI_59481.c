//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

#define MAX_URLS 10   // Maximum number of URLs to monitor
#define MAX_RESPONSE_TIME 10    // Maximum response time in seconds 

// Global variables
char* urls[MAX_URLS] = {"https://www.google.com", "https://www.amazon.com", "https://www.facebook.com"};
int numUrls = 3;

// Function Declarations
void checkUrl(char* url);

// Main function
int main() {
    CURL *curl;
    CURLcode res;
    int i;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Infinite loop to keep monitoring the URLs   
    while(1) {
        for(i = 0; i < numUrls; i++) {
            checkUrl(urls[i]);
        }
        sleep(30);   // Wait for 30 seconds
    }

    curl_global_cleanup();
    return 0;
}

// Function Definitions
void checkUrl(char* url) {
    CURL *curl;
    CURLcode res;
    double response_time;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);     // Do not download the body of the response
        curl_easy_setopt(curl, CURLOPT_HEADER, 0);     // Do not include the header in the response
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, MAX_RESPONSE_TIME);   // Set the maximum allowed response time

        // Get the response time
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            printf("%s is down!\n", url);
        } else {
            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &response_time);
            printf("%s is up! Response Time: %.2f seconds\n", url, response_time);
        }

        curl_easy_cleanup(curl);
    }
}