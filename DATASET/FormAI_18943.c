//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL "https://www.google.com"
#define REFRESH_RATE 10

int main(void) {
    CURL *curl_handle;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    while (1) {
        curl_handle = curl_easy_init();
        if (curl_handle) {
            curl_easy_setopt(curl_handle, CURLOPT_URL, URL);
            curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, 10L);
            res = curl_easy_perform(curl_handle);
            if (res == CURLE_OK) {
                printf("Website is up!\n");
            } else {
                printf("Website is down :(\n");
            }
            curl_easy_cleanup(curl_handle);
        }
        sleep(REFRESH_RATE);
    }

    curl_global_cleanup();

    return EXIT_SUCCESS;
}