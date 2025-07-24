//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define TIMEOUT 10 // Timeout value in seconds
#define MAX_URL_LEN 1024 // Maximum length of URL

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    double elapsed_time;
    char url[MAX_URL_LEN];
    time_t current_time;

    if (argc != 2) {
        printf("USAGE: %s <url>\n", argv[0]);
        return 1;
    }

    curl = curl_easy_init();
    if (curl) {
        strcpy(url, argv[1]);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            return 2;
        }
        else {
            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed_time);
            printf("Website is up. Response time: %.2f seconds\n", elapsed_time);
            current_time = time(NULL);
            printf("Last checked at: %s", ctime(&current_time));
        }
        curl_easy_cleanup(curl);
    }

    return 0;
}