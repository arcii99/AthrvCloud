//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL "http://www.example.com" // The website you want to monitor
#define INTERVAL 10 // Interval in seconds between each check

int main() {
    printf("Starting website uptime monitor...\n");

    while (1) {
        CURL *curl;
        CURLcode res;

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, URL);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
            } else {
                int response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                if (response_code == 200) {
                    printf("Website is up!\n");
                } else {
                    printf("Website is down! (Response code: %d)\n", response_code);
                }
            }
            curl_easy_cleanup(curl);
        }

        sleep(INTERVAL);
    }

    return 0;
}