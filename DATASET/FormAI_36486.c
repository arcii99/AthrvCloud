//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

#define TIMEOUT 15 // Set timeout limit in seconds
#define SLEEP_TIME 60 // Sleep time between requests in seconds

// Define function to perform HTTP GET request
void perform_request(CURL* curl, const char* url) {
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_URL, url); // Set URL
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT); // Set timeout
    res = curl_easy_perform(curl); // Perform request
    if(res != CURLE_OK) { // Check for errors
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
}

// Define function to check website availability
void check_uptime(const char* url) {
    CURL* curl;
    curl = curl_easy_init(); // Initialize curl
    if(curl) {
        perform_request(curl, url); // Perform initial request
        while(1) { // Loop indefinitely
            sleep(SLEEP_TIME); // Wait before making next request
            perform_request(curl, url); // Perform next request
        }
        curl_easy_cleanup(curl); // Cleanup curl object
    }
}

int main() {
    const char* website = "https://www.example.com";
    check_uptime(website);
    return 0;
}