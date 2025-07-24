//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

// Function to get the current date and time
char* getCurrentDateTime() {
    time_t now = time(NULL);
    return ctime(&now);
}

// Function to check if the website is up or not
int checkWebsiteStatus(char* url) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            if(response_code == 200) {
                curl_easy_cleanup(curl);
                return 1;
            }
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}

int main() {
    char* websiteUrl = "http://www.examplewebsite.com";
    int interval = 300;  // 5 minutes

    while(1) {
        int status = checkWebsiteStatus(websiteUrl);

        if(status) {
            printf("%s - Website is up!\n", getCurrentDateTime());
        } else {
            printf("%s - Website is down!\n", getCurrentDateTime());
        }

        printf("Waiting for %d seconds before checking again...\n", interval);
        sleep(interval);
    }

    return 0;
}