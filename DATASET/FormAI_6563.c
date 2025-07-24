//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
 
#define MAX_URLS 10
#define TIMEOUT 10L
 
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <url1> <url2> ... <url%d>\n", argv[0], MAX_URLS);
        exit(EXIT_FAILURE);
    }
 
    CURL* curl;
    CURLcode res;
    int i;
 
    for (i = 1; i < argc; i++) {
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, argv[i]);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                printf("Error in connecting to %s: %s\n", argv[i], curl_easy_strerror(res));
            }
            curl_easy_cleanup(curl);
        } else {
            printf("Error initializing libcurl\n");
        }
    }
 
    return 0;
}