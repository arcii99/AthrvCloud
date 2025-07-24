//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define URL "http://www.example.com"

// function to check website uptime
int check_website() {
    CURL *curl;
    CURLcode res;
    int result = 0; // set the default result to 0 (false)

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // check only the headers
        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code == 200) result = 1; // set the result to 1 (true)
        }

        curl_easy_cleanup(curl);
    }

    return result;
}

// main function
int main() {
    printf("Starting Website Uptime Monitor...\n");

    while(1) { // loop indefinitely
        int is_up = check_website();
        if(is_up) {
            printf("The website is up!\n");
        } else {
            printf("[ALERT] The website is down!\n");
        }

        sleep(60); // wait for 60 seconds before checking again
    }

    return 0;
}