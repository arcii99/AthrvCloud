//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
/*
 * C Website Uptime Monitor
 * This program will check the status of a website at regular intervals and notify the user if the website is down.
 * By: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <stdbool.h>
#include <unistd.h>

//Function to check the status of the website
bool checkWebsite(char *url) {
    CURL *curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, true);
        CURLcode res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            if(response_code == 200) {
                printf("%s is up and running!\n", url);
                curl_easy_cleanup(curl);
                return true;
            }
        }
        printf("%s is down!\n", url);
        curl_easy_cleanup(curl);
    }
    return false;
}

int main() {
    char *website = "https://www.example.com";
    int interval = 60; //Time interval in seconds
    
    while(true) {
        if(!checkWebsite(website)) {
            printf("Sending email notification...\n");
            //Code to send email notification to the user goes here
        }
        sleep(interval);
    }

    return 0;
}