//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

// This function checks if a website is up and returns true or false accordingly
bool isWebsiteUp(const char* url) {
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        CURLcode res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            curl_easy_cleanup(curl);
            return false;
        }
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        curl_easy_cleanup(curl);
        if(http_code < 200 || http_code >= 300) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

// Entry point of the program
int main() {
    const char* websiteUrl = "https://www.example.com";
    const int pollingIntervalInSeconds = 60;
    printf("Website Uptime Monitor Started - Monitoring %s\n", websiteUrl);
    
    // Infinite loop
    while (true) {
        if (isWebsiteUp(websiteUrl)) {
            printf("%s: UP\n", websiteUrl);
        } else {
            printf("%s: DOWN\n", websiteUrl);
        }
        
        // Sleep for polling interval
        printf("Sleeping for %d seconds...\n", pollingIntervalInSeconds);
        sleep(pollingIntervalInSeconds);
    }
    
    return 0;
}