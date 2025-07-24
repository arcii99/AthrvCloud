//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// define URLs to monitor
char* urls[] = {
    "https://www.google.com",
    "https://www.apple.com",
    "https://www.github.com",
    "https://www.linkedin.com",
    "https://www.youtube.com"
};

// define interval in seconds for checking URLs
const int INTERVAL = 30;

// function to check a URL
// returns 1 if URL is up, 0 if URL is down
int check_url(char* url) {
    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code == 200) {
                curl_easy_cleanup(curl);
                return 1;
            }
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}

int main(void) {
    // initialize variables
    int num_urls = sizeof(urls) / sizeof(urls[0]);
    int states[num_urls];
    int i;

    // initialize all states to 1 (URLs are up)
    for (i = 0; i < num_urls; i++) {
        states[i] = 1;
    }

    // check URLs at specified interval
    while (1) {
        for (i = 0; i < num_urls; i++) {
            int state = check_url(urls[i]);
            if (state != states[i]) {
                // State of the URL has changed
                if (state == 1) {
                    printf("[UP]: %s\n", urls[i]);
                } else {
                    printf("[DOWN]: %s\n", urls[i]);
                }
                states[i] = state;
            }
        }
        sleep(INTERVAL);
    }

    return 0;
}