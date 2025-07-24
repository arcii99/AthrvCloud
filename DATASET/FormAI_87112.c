//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>
#include<unistd.h>
#include<stdbool.h>

#define URL "http://www.example.com" // URL to be monitored
#define DELAY 60 // Time delay between checks in seconds

bool isWebsiteUp(char* url){

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    if(curl) {

        curl_easy_setopt(curl, CURLOPT_URL, url);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK){
            /* Curl error. Website is down */
            curl_easy_cleanup(curl);
            return false;
        } else {
            /* Website is up */
            curl_easy_cleanup(curl);
            return true;
        }
    }

    /* Curl initialization failed */
    return false;
}

int main(){

    int checkCount = 0;
    printf("Website uptime monitor is running for: %s\n", URL);
    printf("Checking every %d seconds...\n", DELAY);
    while(true){

        if(isWebsiteUp(URL)){
            /* Website is up */
            printf("Website is up!\n");
            sleep(DELAY);
        } else {
            /* Website is down */
            printf("Website is down!\n");
            sleep(DELAY);
        }

        checkCount++;
        printf("Checks performed: %d\n", checkCount);
    }

    return EXIT_SUCCESS;
}