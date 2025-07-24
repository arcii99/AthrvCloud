//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

// Define URL to monitor
#define WEBSITE_URL "https://www.example.com"

// Define monitoring interval in seconds
#define MONITOR_INTERVAL 60

// Define colors for terminal output
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_RESET "\033[0m"

int main() {
    // Initialize curl library
    curl_global_init(CURL_GLOBAL_ALL);

    while(1) {
        // Get current time
        time_t raw_time;
        struct tm *info;
        char time_buffer[80];
        time(&raw_time);
        info = localtime(&raw_time);
        strftime(time_buffer, 80, "%Y-%m-%d %H:%M:%S", info);

        // Start monitoring
        CURL *curl;
        CURLcode res;
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, WEBSITE_URL);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                // Display error message
                printf(COLOR_RED "[%s] Error: %s\n" COLOR_RESET, time_buffer, curl_easy_strerror(res));
            } else {
                // Display success message
                printf(COLOR_GREEN "[%s] Success: Website is up!\n" COLOR_RESET, time_buffer);
            }
            curl_easy_cleanup(curl);
        } else {
            // Display error message
            printf(COLOR_RED "[%s] Error: Failed to initialize curl library!\n" COLOR_RESET, time_buffer);
        }

        // Wait for next monitoring interval
        sleep(MONITOR_INTERVAL);
    }

    // Cleanup curl library
    curl_global_cleanup();

    return 0;
}