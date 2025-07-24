//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

#define INTERVAL 60 // Check interval in seconds

// Function to perform a website request and return the HTTP code
int check_website(char* url) {
    CURL *curl;
    CURLcode res;
    long http_code = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return http_code;
}

int main(int argc, char *argv[]) {
    int status;
    time_t last_check, now;
    char* url = argv[1]; // Get URL from command line argument

    time(&last_check);
    while (1) {
        time(&now);
        if(difftime(now, last_check) > INTERVAL) { // Wait specified interval
            status = check_website(url); // Check website status
            printf("Website status: HTTP %d\n", status);
            last_check = now; // Update last check time
        }
        // Do other desired tasks
    }

    return 0;
}