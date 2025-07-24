//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

#define URL "https://www.google.com" // URL to monitor
#define TIMEOUT 5 // timeout for the curl request in seconds
#define SLEEP_TIME 60 // time interval for checking the URL in seconds

// Function to check the website status
bool check_status() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if(res == CURLE_OK) {
            return true;
        }
    }
    return false;
}

int main() {
    time_t current_time;
    char* c_time_string;

    // Loop continuously to check the website status
    while(true) {
        if(check_status()) {
            time(&current_time);
            c_time_string = ctime(&current_time);
            printf("%s - %s is UP\n", c_time_string, URL);
        }
        else {
            time(&current_time);
            c_time_string = ctime(&current_time);
            printf("%s - %s is DOWN\n", c_time_string, URL);
        }

        // Wait for the defined interval before checking again
        sleep(SLEEP_TIME);
    }

    return 0;
}