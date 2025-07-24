//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <curl/curl.h>

#define URL "https://www.example.com"
#define TIMEOUT 10 // Timeout for the request in seconds
#define MAX_FAILURES 3 // Maximum failures to trigger an alert

int main()
{
    int failures = 0; // Counter for consecutive failures
    bool isDown = false; // Flag to indicate if site is down

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    while(true) // Endless loop to check site availability
    {
        curl = curl_easy_init();
        if(curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, URL);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

            res = curl_easy_perform(curl); // Make the request
            if(res != CURLE_OK) // Check for request failure
            {
                printf("Site is down!\n");
                failures += 1;
                if(failures >= MAX_FAILURES && !isDown) // Trigger alert if consecutive failures exceed limit
                {
                    printf("ALERT: Site has been down for too long!\n");
                    isDown = true;
                }
            }
            else // Request was successful
            {
                printf("Site is up and running!\n");
                failures = 0;
                if(isDown) // Alert is unnecessary if site was previously down
                {
                    printf("Site is back up!\n");
                    isDown = false;
                }
            }

            curl_easy_cleanup(curl);
        }
        sleep(10); // Wait 10 seconds before next check
    }

    curl_global_cleanup();

    return 0;
}