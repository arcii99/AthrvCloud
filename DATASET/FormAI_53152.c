//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main()
{
    CURL *curl;
    CURLcode res;
    const char *url = "https://www.example.com";

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res != CURLE_OK) {
            printf("Website is currently down!\n");
        } else {
            printf("Website is up and running smoothly!\n");
        }
    }

    return 0;
}