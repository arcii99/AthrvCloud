//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define constants for the website url and the interval time to check 
#define WEBSITE_URL "https://www.example.com"
#define INTERVAL_TIME 60  // in seconds 

// Define a struct to hold the website response data
struct WebsiteResponse {
    char* data;
    size_t size;
};

// Define a function to write the received data to the struct
static size_t write_response(void *ptr, size_t size, size_t nmemb, void *stream) {
    struct WebsiteResponse *resp = (struct WebsiteResponse *)stream;
    resp->data = realloc(resp->data, resp->size + (size * nmemb));
    if (resp->data != NULL) {
        memcpy(resp->data + resp->size, ptr, size * nmemb);
        resp->size += size * nmemb;
    }
    return size * nmemb;
}

int main() {
    // Initialize CURL
    CURL *curl_handle;
    CURLcode res;
    struct WebsiteResponse resp = {0};

    curl_global_init(CURL_GLOBAL_ALL);
    
    while(1) {
        // Set up the curl request
        curl_handle = curl_easy_init();
        curl_easy_setopt(curl_handle, CURLOPT_URL, WEBSITE_URL);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_response);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &resp);

        // Perform the request and check for errors
        res = curl_easy_perform(curl_handle);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else {
            // Check the status code of the response and print appropriate messages
            long response_code;
            curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code == 200) { // website is up and running
                printf("Website is up and running!\n");
                printf("Response data: %s\n", resp.data);
            }
            else if (response_code == 0) { // could not connect to the website
                printf("Could not connect to the website!\n");
            }
            else { // website is returning an error
                printf("Website is returning an error!\n");
                printf("Response code: %ld\n", response_code);
                printf("Response data: %s\n", resp.data);
            }
        }

        // Clean up and reset the struct and curl handle for the next request
        curl_easy_cleanup(curl_handle);
        free(resp.data);
        resp.data = NULL;
        resp.size = 0;
        
        // Wait for the interval time to check again
        printf("Waiting for %d seconds before checking again..\n", INTERVAL_TIME);
        sleep(INTERVAL_TIME);
    }

    // Clean up CURL global resources
    curl_global_cleanup();

    return 0;
}