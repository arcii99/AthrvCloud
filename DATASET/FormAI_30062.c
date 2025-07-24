//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define URL "https://www.example.com" // change to the website you want to monitor
#define SLEEP_TIME 60 // sleep time in seconds

// This function will check website for its status every minute
void check_website_status() {
    CURL *curl;
    CURLcode res;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            printf("%02d:%02d:%02d %s is up!\n", tm.tm_hour, tm.tm_min, tm.tm_sec, URL);
        } else {
            printf("%02d:%02d:%02d %s is down!\n", tm.tm_hour, tm.tm_min, tm.tm_sec, URL);
        }
        curl_easy_cleanup(curl);
    }
}

int main() {
    while(1) {
        check_website_status();
        sleep(SLEEP_TIME);
    }
    return 0;
}