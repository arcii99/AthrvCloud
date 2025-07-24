//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL "https://example.com"

// Function to get current time
void getCurrentTime(char* buffer) {
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%m/%d/%Y %I:%M:%S %p", timeinfo);
}

// Function to check the website uptime
int checkWebsiteStatus() {
    CURL *curl;
    curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if(res == CURLE_OK) {
            return 1; // Website is up
        } else {
            return 0; // Website is down
        }
    } else {
        return -1; // Failed to initialize CURL
    }
}

int main() {
    int websiteStatus = checkWebsiteStatus();
    char currentTime[80];
    getCurrentTime(currentTime);
    printf("%s - Website is %s\n", currentTime, websiteStatus == 1 ? "UP" : "DOWN");

    // Keep monitoring the website's status every 5 seconds
    while(1) {
        websiteStatus = checkWebsiteStatus();
        getCurrentTime(currentTime);
        printf("%s - Website is %s\n", currentTime, websiteStatus == 1 ? "UP" : "DOWN");
        sleep(5);
    }

    return 0;
}