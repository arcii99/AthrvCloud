//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>
#include <stdbool.h>

void checkStatus(const char *url, bool *status) {
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        CURLcode res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            long responseCode;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
            if(responseCode == 200) {
                *status = true;
            } else {
                *status = false;
            }
        }

        curl_easy_cleanup(curl);
    }
}

int main() {
    const char *url = "https://www.example.com";
    bool status = false;
    struct timespec ts;
    ts.tv_sec = 60;
    ts.tv_nsec = 0;

    while(1) {
        checkStatus(url, &status);

        if(status) {
            printf("%s is up at %s\n", url, ctime(&(time_t){time(NULL)}));
        } else {
            printf("%s is down at %s\n", url, ctime(&(time_t){time(NULL)}));
        }

        nanosleep(&ts, NULL);
    }

    return 0;
}