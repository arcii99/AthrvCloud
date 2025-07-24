//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void) {
    // Change the URL to the website you want to monitor
    char *url = "https://www.google.com";
    // Set the maximum time in seconds that the request is allowed to take
    long timeout = 10L;

    CURL *curl = curl_easy_init();
    if(curl) {
        // Set the URL to fetch
        curl_easy_setopt(curl, CURLOPT_URL, url);
        // Set the timeout for the request
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
        // Follow any redirects
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        CURLcode res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            // Handle any error that occurs
            printf("Error: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 1;
        }

        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("Response code: %ld\n", response_code);

        curl_easy_cleanup(curl);
    }

    return 0;
}