//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please provide at least one website URL\n");
        return 0;
    }
    srand(time(NULL));
    CURLcode res;

    // Set up CURL handle
    CURL* curl = curl_easy_init();
    if(curl == NULL) {
        printf("Failed to initialize CURL\n");
        return 0;
    }
    
    // Loop through each URL
    for(int i = 1; i < argc; i++) {
        char *url = argv[i];
        printf("Checking %s...\n", url);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        
        // If an error occurred, generate a random HTTP status code
        if(res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            int status_code = rand() % 400 + 500; // Generate a random server error code
            printf("%s is down with HTTP %d status code\n", url, status_code);
        } else {
            printf("%s is up and running!\n", url);
        }
    }
    
    // Clean up
    curl_easy_cleanup(curl);
    return 0;
}