//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

int main() {
    // Define website to monitor
    char* website_url = "https://www.google.com";
    
    // Set up CURL library
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    // Set up CURL handle
    CURL* curl_handle = curl_easy_init();
    
    // Specify URL to monitor
    curl_easy_setopt(curl_handle, CURLOPT_URL, website_url);
    
    // Specify the timeout (in seconds) for the request
    curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, 10L);
    
    // Perform the request
    CURLcode res = curl_easy_perform(curl_handle);
    
    // Check if request was successful
    if (res == CURLE_OK) {
        printf("Website is up and running!\n");
    } else {
        printf("Oops, website is down :(\n");
    }
    
    // Clean up CURL handle
    curl_easy_cleanup(curl_handle);
    
    // Clean up CURL library
    curl_global_cleanup();
    
    return 0;
}