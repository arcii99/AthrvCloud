//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL "https://www.example.com"

// function to perform the curl operation and print the status
int check_site_status() {
    CURL *curl;
    CURLcode res;
    long status = 0;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return -1;
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);

        curl_easy_cleanup(curl);
    }

    printf("Site status: %ld\n", status);

    if (status == 200) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int status = 0;

    while (1) {
        status = check_site_status();
        if (status == -1) {
            printf("Failed to check site status. Retrying in 5 seconds...\n");
            sleep(5);
            continue;
        }
        else if (status == 0) {
            printf("Site is down. Retrying in 5 seconds...\n");
            sleep(5);
            continue;
        }
        else {
            printf("Site is up!\n");
            break;
        }
    }

    return 0;
}