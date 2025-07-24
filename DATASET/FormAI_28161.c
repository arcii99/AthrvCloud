//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <stdbool.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define MAX_TIMEOUT 10

// Data structure to store the URL and the time when the last check was made
typedef struct {
    char url[MAX_URL_LENGTH];
    time_t last_check;
} url_info_t;

// Prototypes
void check_url(url_info_t* url_info);

int main(int argc, char *argv[]) {
    // Array of URLs to monitor
    char *urls[] = {"https://www.example1.com", "https://www.example2.com", "https://www.example3.com"};

    // Array to store the URL info
    url_info_t url_info_array[sizeof(urls)/sizeof(char*)];

    // Initialize the URLs and set the last check time to 0
    for (int i = 0; i < sizeof(urls)/sizeof(char*); i++) {
        strcpy(url_info_array[i].url, urls[i]);
        url_info_array[i].last_check = 0;
    }

    // Loop forever
    while (true) {
        for (int i = 0; i < sizeof(urls)/sizeof(char*); i++) {
            check_url(&url_info_array[i]);
        }
        // Wait for 10 seconds before checking again
        sleep(10);
    }

    return 0;
}

void check_url(url_info_t* url_info) {
    // Get the current time
    time_t current_time;
    time(&current_time);

    // Check if MAX_TIMEOUT seconds have passed since the last check
    if (current_time - url_info->last_check > MAX_TIMEOUT) {
        // Create a curl handle
        CURL *curl;
        CURLcode res;
        curl = curl_easy_init();

        if(curl) {
            // Set the URL to check
            curl_easy_setopt(curl, CURLOPT_URL, url_info->url);

            // Set a timeout for the request
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, MAX_TIMEOUT);

            // Send the request
            res = curl_easy_perform(curl);

            // Check the response code
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if (res == CURLE_OK && response_code == 200) {
                printf("%s is UP at %s\n", url_info->url, ctime(&current_time));
            } else {
                printf("%s is DOWN at %s\n", url_info->url, ctime(&current_time));
            }

            // Clean up
            curl_easy_cleanup(curl);

            // Update the last check time
            url_info->last_check = current_time;
        } else {
            printf("An error occurred while initializing curl\n");
        }
    }
}