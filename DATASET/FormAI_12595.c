//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<curl/curl.h>

// Declare the function that will be used to check the website's availability
int check_website(char* url);

int main() {

    // Declare variables
    char* url = "https://www.example.com";
    int interval = 60; // Interval in seconds
    
    // Print program header
    printf("************* Website Uptime Monitor ******************\n\n");
    printf("Checking website %s every %d seconds...\n\n", url, interval);
    
    // Enter infinite loop to continuously check website availability
    while(1) {
        // Call the function that checks availability and print results
        if(check_website(url)) {
            printf("[%d] Website is up and running!\n", (int)time(NULL));
        }
        else {
            printf("[%d] Website is DOWN!\n", (int)time(NULL));
        }
        sleep(interval); // Wait for interval seconds
    }

}

int check_website(char* url) {

    // Initiate CURL
    CURL* curl = curl_easy_init();
    
    if(curl) {
        // Set the URL to request
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        // Perform the request
        CURLcode res = curl_easy_perform(curl);
        
        // Cleanup
        curl_easy_cleanup(curl);
        
        if(res == CURLE_OK) {
            return 1; // Website is available
        }
        else {
            return 0; // Website is down
        }
    }
    else {
        return 0; // Error in initiating CURL
    }
}