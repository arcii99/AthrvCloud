//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

#define URL "https://www.example.com"
#define TIMEOUT 5

/* Struct to hold the website's status */
typedef struct {
    char url[100];
    bool is_up;
    struct tm* last_checked_time;
} WebsiteStatus;

/* Function to check if the website is up */
bool is_website_up(char* url) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            curl_easy_cleanup(curl);
            return true;
        } else {
            curl_easy_cleanup(curl);
            return false;
        }
    }
    return false;
}

/* Function to get the current time */
struct tm* get_current_time() {
    time_t current_time;
    struct tm* time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    return time_info;
}

int main() {
    WebsiteStatus website = {URL, false, NULL};
    while(true) {
        bool uptime_status = is_website_up(website.url);
        if(uptime_status != website.is_up) {
            website.is_up = uptime_status;
            website.last_checked_time = get_current_time();
            if(website.is_up) {
                printf("%s is now up! Last checked at: %s", website.url, asctime(website.last_checked_time));
            } else {
                printf("%s is now down. Last checked at: %s", website.url, asctime(website.last_checked_time));
            }
        }
        sleep(10);
    }
    return 0;
}