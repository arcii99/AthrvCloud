//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

// define your website URLs below
char *urls[] = {"https://www.example.com", "https://www.google.com", "https://www.github.com"};

int main(void) {
    CURL *curl;
    CURLcode res;
    bool isSiteLive = true;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        for (int i = 0; i < sizeof(urls)/sizeof(urls[0]); i++) {
            curl_easy_setopt(curl, CURLOPT_URL, urls[i]);

            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                printf("%s is DOWN!\n", urls[i]);
                isSiteLive = false;
            } else {
                printf("%s is UP!\n", urls[i]);
            }
        }

        if (!isSiteLive) {
            // send email to notify site down
            printf("Sending email notification to admins...\n");
            // sendSMS to admins
            printf("Sending SMS notification to admins...\n");
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}