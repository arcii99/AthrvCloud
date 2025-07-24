//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

#define URL "https://www.example.com"
#define TIMEOUT 10L //Timeout period in seconds

//Callback function for handling HTTP response
size_t handle_response(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
  
    while(1) { //loop forever
        curl = curl_easy_init();
  
        //Set URL and timeout period
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
 
        printf("Checking website uptime...\n");

        //Perform HTTP request
        res = curl_easy_perform(curl);
 
        if(res == CURLE_OK) {
            printf("Website is up!\n");
        } else {
            printf("Website is down! Error code: %d\n", res);
        }
 
        //Cleanup
        curl_easy_cleanup(curl);
  
        //Wait for 30 seconds before checking again
        sleep(30);
    }

    return 0;
}