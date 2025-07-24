//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LENGTH 100
#define MAX_TIME_DIFFERENCE 60 // Maximum time difference in seconds

// A struct to hold the information about the websites
struct website {
    char url[MAX_URL_LENGTH];
    time_t last_checked;
};

// A function to check the website status
int check_website_status(char *url) {
    CURL *curl;
    CURLcode response;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        response = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if(response == CURLE_OK) {
            return 1; // Website is up
        } else {
            return 0; // Website is down
        }
    } else {
        return -1; // Failed to start the curl session
    }
}

int main() {
    struct website websites[] = {
        {"https://www.google.com", 0},
        {"https://www.yahoo.com", 0},
        {"https://www.bing.com", 0},
        {"https://www.duckduckgo.com", 0}
    };
    int num_websites = sizeof(websites) / sizeof(struct website);
    while(1) {
        for(int i = 0; i < num_websites; i++) {
            time_t current_time = time(NULL);
            if(difftime(current_time, websites[i].last_checked) > MAX_TIME_DIFFERENCE) {
                int status = check_website_status(websites[i].url);
                if(status == 1) {
                    printf("%s is up!\n", websites[i].url);
                } else if(status == 0) {
                    printf("%s is down!\n", websites[i].url);
                } else {
                    printf("Failed to start the curl session for %s!\n", websites[i].url);
                }
                websites[i].last_checked = current_time;
            }
        }
        sleep(10);
    }
    return 0;
}