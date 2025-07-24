//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_WEBSITES 10
#define MAX_URL_LENGTH 100

typedef struct {
    char url[MAX_URL_LENGTH];
    int status;
    time_t last_checked;
} Website;

void check_website(Website* website) {
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
    
        res = curl_easy_perform(curl);
        
        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &website->status);
        } else {
            fprintf(stderr, "Error checking website %s: %s\n", website->url, curl_easy_strerror(res));
        }
        
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Error initializing cURL\n");
    }
    
    time(&website->last_checked);
}

int main() {
    Website websites[MAX_WEBSITES];
    int num_websites = 0;
    int i, j;
    time_t current_time;    
    
    // Add websites to the list
    strcpy(websites[0].url, "https://www.google.com");
    num_websites++;
    
    strcpy(websites[1].url, "https://www.apple.com");
    num_websites++;
    
    strcpy(websites[2].url, "https://www.microsoft.com");
    num_websites++;
    
    // Check website statuses every 5 seconds
    while(1) {
        for(i = 0; i < num_websites; i++) {
            check_website(&websites[i]);
            
            printf("%s - Status: %d\n", websites[i].url, websites[i].status);
        }
        
        // Check for any websites that have been down for more than 1 minute and send an alert
        time(&current_time);
        
        for(i = 0; i < num_websites; i++) {
            if(difftime(current_time, websites[i].last_checked) > 60 && websites[i].status != 200) {
                printf("Alert: Website %s has been down for more than 1 minute!\n", websites[i].url);
            }
        }
        
        // Wait 5 seconds before checking again
        sleep(5);
    }
    
    return 0;
}