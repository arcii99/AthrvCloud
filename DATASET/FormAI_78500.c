//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

/* Define the URL to be monitored */
#define URL "https://example.com"

/* Define the time interval (in seconds) for checking URL */
#define INTERVAL 60

/* Define the email address to notify in case of downtime */
#define EMAIL "example@example.com"

/* Global variables */
bool isOnline = true;

/* Function to send email notification */
void sendEmail() {
    /* Code to send email goes here */
    printf("Website is down! Email notification sent to %s\n", EMAIL);
}

/* Function to perform URL check */
bool checkURL() {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            /* URL is down */
            return false;
        } else {
            /* URL is up */
            return true;
        }
        curl_easy_cleanup(curl);
    }
}

/* The program starts here */
int main() {
    while (true) {
        if (!isOnline) {
            /* Website was down but now it is back online */
            if (checkURL()) {
                isOnline = true;
                printf("Website is back online!\n");
            }
        } else {
            /* Website is currently online */
            if (!checkURL()) {
                isOnline = false;
                printf("Website is down!\n");
                sendEmail();
            }
        }
        sleep(INTERVAL);
    }
    return 0;
}