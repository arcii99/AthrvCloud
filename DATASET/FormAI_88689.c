//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

// Define global variables
const char *url = "https://www.example.com"; // Enter the website URL to monitor
int timeout = 5; // Set connection timeout in seconds
int interval = 60; // Set time interval for checks in seconds

// Function to check website status
int checkWebsiteStatus() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            return 1; // Website is up
        } else {
            return 0; // Website is down
        }
        curl_easy_cleanup(curl);
    } else {
        return 0; // Failed to initiate CURL
    }
}

// Function to write log to file
void writeToLog(char *message) {
    FILE *file;
    file = fopen("monitor-log.txt", "a"); // Open file in append mode
    if (file == NULL) {
        printf("Failed to write log to file!\n");
    } else {
        fprintf(file, "%s\n", message);
        fclose(file);
    }
}

int main() {
    time_t startTime, currentTime;
    char startMessage[100], upMessage[100], downMessage[100];

    // Get current time
    time(&currentTime);

    // Send start message to console and log file
    sprintf(startMessage, "Monitoring started at %s", ctime(&currentTime));
    printf("%s\n", startMessage);
    writeToLog(startMessage);

    // Start monitoring loop
    while (1) {
        // Get current time
        time(&currentTime);

        // Check website status
        int status = checkWebsiteStatus();

        if (status == 1) {
            sprintf(upMessage, "[%s] Website is up", ctime(&currentTime));
            printf("%s\n", upMessage);
            writeToLog(upMessage);
        } else {
            sprintf(downMessage, "[%s] Website is down", ctime(&currentTime));
            printf("%s\n", downMessage);
            writeToLog(downMessage);
        }

        // Wait for the specified interval before checking again
        sleep(interval);
    }

    return 0;
}