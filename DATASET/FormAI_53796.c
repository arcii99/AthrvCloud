//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define TEST_URL "https://example.com"

#define MAX_RESPONSE_TIME 5000 // Maximum time a website can take to respond
#define CHECK_INTERVAL 60 // Time interval between checks (in seconds)

// Function to print timestamp in the format YYYY-MM-DD HH:MM:SS
void print_timestamp() {
    time_t current_time;
    struct tm *time_info;
    char timestamp[20];
    
    time(&current_time);
    time_info = localtime(&current_time);
    
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", time_info);
    
    printf("[%s] ", timestamp);
}

// Callback function for CURL
size_t curl_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

int main() {
    CURL *curl; // CURL handle
    CURLcode res; // CURL result
    int status_code; // HTTP status code
    long response_time; // Response time (in ms)
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    if (curl) {
        while (1) {
            print_timestamp();
            res = curl_easy_setopt(curl, CURLOPT_URL, TEST_URL);
            res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_callback);
            res = curl_easy_perform(curl);
            res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
            res = curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &response_time);
            
            if (res != CURLE_OK) {
                printf("ERROR: %s\n", curl_easy_strerror(res));
            } else {
                if (status_code == 200) {
                    if (response_time > MAX_RESPONSE_TIME) {
                        printf("ALERT - Response time too high: %ld ms\n", response_time);
                    } else {
                        printf("Website is online\n");
                    }
                } else {
                    printf("ALERT - Website is offline (HTTP status code %d)\n", status_code);
                }
            }
            
            sleep(CHECK_INTERVAL);
        }
        
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
    
    return EXIT_SUCCESS;
}