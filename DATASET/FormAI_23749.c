//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

int main() {
    CURL *curl;
    CURLcode res;
    char *url = "http://example.com";
    int status = 0;

    printf("Website Uptime Monitor\n");
    printf("----------------------\n");

    while (1) {
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url);
            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                printf("Error: %s\n", curl_easy_strerror(res));
                status = 0;
            } else {
                printf("Website is up and running!\n");
                status = 1;
            }

            curl_easy_cleanup(curl);
        }

        if (status == 0) {
            printf("Website is down. Restarting...\n");
            sleep(10);
        } else {
            printf("Monitoring website...\n");
            sleep(300);
        }
    }

    return 0;
}