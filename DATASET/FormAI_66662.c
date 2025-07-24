//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main()
{
    // Set the URL to monitor
    char url[256];
    printf("Enter URL to monitor: ");
    scanf("%s", url);
    
    // Set the time interval in seconds to check the website
    int interval;
    printf("Enter time interval (in seconds): ");
    scanf("%d", &interval);
    
    // Initialize libcurl
    CURL *curl = curl_easy_init();
    if(curl) {
        // Set the URL to monitor
        curl_easy_setopt(curl, CURLOPT_URL, url);
        // Set timeout for connection and request
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        // Set the amount of data to receive
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        while(1) {
            // Perform the HTTP HEAD request
            CURLcode res = curl_easy_perform(curl);
            if(res == CURLE_OK) {
                // Get the response code
                long response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

                printf("Testing %s - Response code: %ld\n", url, response_code);
            } else {
                printf("Error: %s\n", curl_easy_strerror(res));
            }
            // Wait for specified interval
            sleep(interval);
        }
        // Clean up libcurl
        curl_easy_cleanup(curl);
    }
    return 0;
}