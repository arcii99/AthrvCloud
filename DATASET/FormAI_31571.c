//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>
#include <time.h>

#define SITE1 "http://www.example1.com"
#define SITE2 "http://www.example2.com"
#define WAIT_TIME 60

void checkSiteStatus(char *site) {
    CURL *curl;
    CURLcode result;

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site);

        result = curl_easy_perform(curl);

        if (result != CURLE_OK) {
            printf("\nError: %s is down!\n", site);
        } else {
            time_t current_time;
            time(&current_time);

            char *time_string = ctime(&current_time);
            time_string[strlen(time_string) - 1] = '\0';

            printf("%s - %s is up!\n", time_string, site);
        }

        curl_easy_cleanup(curl);
    }
}

int main() {
    while (true) {
        printf("\nChecking website status...\n");
        checkSiteStatus(SITE1);
        checkSiteStatus(SITE2);

        printf("\nWaiting for %d seconds...\n", WAIT_TIME);
        sleep(WAIT_TIME);
    }

    return 0;
}