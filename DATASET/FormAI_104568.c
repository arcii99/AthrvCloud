//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

int main(int argc, char* argv[]) {
    CURL *curl;
    CURLcode res;
    char url[256];

    if(argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    strcpy(url, argv[1]);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        long response_code;

        while(1) {
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                fprintf(stderr, "Failed to connect to %s: %s\n", url, curl_easy_strerror(res));
            }

            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            printf("%s [%ld] - %s\n", url, response_code, response_code == 200 ? "Online" : "Offline");

            sleep(60);
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}