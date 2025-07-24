//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

// Define the URL to be monitored
#define URL "https://example.com"

// Define the time interval between checks (in seconds)
#define INTERVAL 60

// Define the maximum number of attempts before sending an alert
#define MAX_ATTEMPTS 3

// Define the email address to send alert notifications to
#define EMAIL_ADDRESS "example@example.com"

// Define the email subject for alert notifications
#define EMAIL_SUBJECT "Website is down"

// Define the email message for alert notifications
#define EMAIL_MESSAGE "The website at " URL " is down"

int main() {

    // Initialize a CURL handle
    CURL *curl_handle = curl_easy_init();
 
    // Initialize a counter for the number of attempts
    int attempts = 0;
    
    while(1) {
    
        // Make a request to the URL
        CURLcode res = curl_easy_setopt(curl_handle, CURLOPT_URL, URL);
        if (res != CURLE_OK) {
            printf("Unable to set URL: %s\n", curl_easy_strerror(res));
            exit(EXIT_FAILURE);
        }
        
        // Set the request timeout to 10 seconds
        res = curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, 10L);
        if (res != CURLE_OK) {
            printf("Unable to set timeout: %s\n", curl_easy_strerror(res));
            exit(EXIT_FAILURE);
        }
        
        // Perform the request
        res = curl_easy_perform(curl_handle);
 
        // Check if the request was successful
        if(res != CURLE_OK) {
            attempts++;
            printf("Attempt %d: Website is down!\n", attempts);
            if (attempts == MAX_ATTEMPTS) {
                // Send an email alert
                char command[256];
                snprintf(command, sizeof(command), "echo \"%s\" | mail -s \"%s\" %s", EMAIL_MESSAGE, EMAIL_SUBJECT, EMAIL_ADDRESS);
                system(command);
                attempts = 0;
            }
        } else {
            attempts = 0;
            printf("Website is up and running!\n");
        }
        
        // Wait for the next check
        sleep(INTERVAL);
            
    }
    
    // Clean up the CURL handle
    curl_easy_cleanup(curl_handle);
 
    return 0;
}