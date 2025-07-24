//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char *argv[]) {

    // Set the URL to monitor
    char *url = "https://www.yoursite.com";

    // Set the time interval in seconds for checking the website
    int interval = 60;

    // Keep track of the last status code received
    long previous_status = -1;

    // Set up the CURL handle
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    // Main loop for monitoring website status
    while(1) {

        // Send the HTTP request and get the response code
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        // Check if the response code has changed
        if (previous_status != response_code) {

            // Output the new status code to the console
            printf("Website Status Code: %ld\n", response_code);

            // Send a notification email
            char email_command[1000];
            sprintf(email_command, "echo 'Website Status Code: %ld' | mail -s 'Website Down!' your_email_here@example.com", response_code);
            system(email_command);

            // Update the previous status code
            previous_status = response_code;

        }

        // Sleep for the configured interval before checking the status again
        sleep(interval);

    }

    // Clean up the CURL handle
    curl_easy_cleanup(curl);

    return 0;
}