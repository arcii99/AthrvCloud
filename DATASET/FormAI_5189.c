//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256

typedef struct {
    char url[MAX_URL_LENGTH];
    int status;
} site_status;

// Function to check the status of a single URL
int check_site_status(const char* url) {
    CURL *curl;
    CURLcode res;
    long http_status;

    curl = curl_easy_init();
    if(curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Follow any redirects
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Only get header information for efficiency
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        // Perform the request
        res = curl_easy_perform(curl);

        // Get the HTTP status code
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_status);

        // Cleanup curl
        curl_easy_cleanup(curl);

        if(res != CURLE_OK) {
            // Return error code for unsuccessful curl request
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return -1;
        }

        return http_status;
    }

    // Return error code for unsuccessful curl initialization
    return -1;
}

// Function to continuously monitor the status of a set of URLs
void monitor_websites(site_status* sites, int num_sites, int interval) {
    while(1) {
        // Check the status of each site
        for(int i=0; i<num_sites; i++) {
            sites[i].status = check_site_status(sites[i].url);
        }

        // Print out the status of each site
        printf("Website Statuses:\n");
        for(int i=0; i<num_sites; i++) {
            printf("%s: %d\n", sites[i].url, sites[i].status);
        }

        // Wait for the specified interval
        sleep(interval);
    }
}

int main() {
    // Define the URLs to monitor and their initial statuses
    site_status sites[] = {
        {"https://www.google.com", 0},
        {"https://example.com", 0},
        {"https://www.youtube.com", 0},
    };

    int num_sites = sizeof(sites) / sizeof(site_status);

    // Continuously monitor the status of the sites with a 10 second interval
    monitor_websites(sites, num_sites, 10);

    return 0;
}