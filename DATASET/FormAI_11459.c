//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URLS 50
#define MAX_NAME_LENGTH 50
#define MAX_LOG_MESSAGE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char url[MAX_NAME_LENGTH];
} website;

typedef struct {
    website sites[MAX_URLS];
    int num_sites;
} website_collection;

int main() {
    CURL *curl;
    CURLcode res;
    website_collection sites;
    int i;
    
    // add websites to website_collection
    strcpy(sites.sites[0].name, "Google");
    strcpy(sites.sites[0].url, "https://www.google.com");
    strcpy(sites.sites[1].name, "Facebook");
    strcpy(sites.sites[1].url, "https://www.facebook.com");
    sites.num_sites = 2;

    // loop through websites
    for (i = 0; i < sites.num_sites; i++) {
        // initialize and set curl options
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, sites.sites[i].url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, 1000);

        // perform the request and log the result
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            printf("%s is UP\n", sites.sites[i].name);
        } else {
            printf("%s is DOWN\n", sites.sites[i].name);

            // log the error message
            char log_msg[MAX_LOG_MESSAGE_LENGTH];
            snprintf(log_msg, MAX_LOG_MESSAGE_LENGTH, "Error connecting to %s: %s", sites.sites[i].url, curl_easy_strerror(res));
            system(log_msg);
        }

        // clean up curl
        curl_easy_cleanup(curl);
    }

    return 0;
}