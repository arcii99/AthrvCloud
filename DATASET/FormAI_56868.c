//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024

// Function to check if the website is live
bool is_online(char *url) {
    CURL *curl;
    CURLcode res;
    bool online = false;
    
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            long http_code = 0;
            curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
            if (http_code == 200) {
                online = true;
            }
        }
        curl_easy_cleanup(curl);
    }
    
    return online;
}

int main() {
    char *urls[] = {"https://www.example1.com", "https://www.example2.com", "https://www.example3.com", "https://www.example4.com"};
    int num_urls = sizeof(urls)/sizeof(urls[0]);
    
    while (true) {
        for (int i = 0; i < num_urls; i++) {
            if (is_online(urls[i])) {
                printf("%s is online!\n", urls[i]);
            }
            else {
                printf("%s is offline!\n", urls[i]);
            }
        }
        printf("\n");

        // Wait for 10 seconds before checking again
        sleep(10);
    }
    
    return 0;
}