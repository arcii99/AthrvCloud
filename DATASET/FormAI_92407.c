//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

// Function to handle the incoming response
int write_response(void *ptr, size_t size, size_t nmemb, void *stream) {
    return size * nmemb;
}

int main(int argc, char** argv) {
    CURL *curl;
    while (1) {
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]); // Set URL
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10); // Set timeout
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response); // Set function to handle response
            curl_easy_perform(curl); // Perform request
            curl_easy_cleanup(curl); // Cleanup curl handle
        }
        printf("Website is up\n"); // Print message if website is up
        sleep(300); // Sleep for 5 minutes
    }
    return 0; // Return success
}