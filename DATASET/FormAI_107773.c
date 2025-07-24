//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

/* Website */
#define WEBSITE "www.example.com"

/* Check interval in seconds */
#define CHECK_INTERVAL 10

/* Max retries before considering a website offline */
#define MAX_RETRIES 3

/* Print colors */
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

/* Global variables */
int retries = 0;

/* Function prototypes */
void check_website();
int website_online();

/* Main function */
int main() {

    printf("Starting website uptime monitor for %s...\n", WEBSITE);

    while(1) {
        check_website();
        sleep(CHECK_INTERVAL);
    }

    return 0;
}

/* Checks if website is online */
void check_website() {

    if(website_online()) {
        printf(GREEN "\t[%s] is online!\n" RESET, WEBSITE);
        retries = 0;
    } else {
        retries++;
        printf(RED "\t[%s] is offline... (retry: %d/%d)\n" RESET, WEBSITE, retries, MAX_RETRIES);

        if(retries >= MAX_RETRIES) {
            printf("\tWebsite has been down for too long. Exiting program.\n");
            exit(1);
        }
    }

}

/* Sends a HTTP request to specified website and returns true if website is online */
int website_online() {

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if(curl) {

        char url[50];
        sprintf(url, "http://%s", WEBSITE);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);

        if(res == CURLE_OK) {
            return 1;
        }
    }

    return 0;
}