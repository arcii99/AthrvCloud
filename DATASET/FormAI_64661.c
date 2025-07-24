//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(int argc, char **argv) {
    CURL *curl;
    CURLcode res;
    char *url = "http://example.com";
    int timeout = 5;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            printf("Website is down!\n");
        }
        else {
            printf("Website is up!\n");
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}