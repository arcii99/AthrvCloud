//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constant values
#define URL_LENGTH 50
#define MAX_RESPONSE_TIME 5000
#define MAX_FAILED_ATTEMPTS 3

// Define a struct to store website information
typedef struct website {
    char url[URL_LENGTH];
    int response_time;
    int failed_attempts;
} Website;

// Define a function to check website uptime
void check_website(Website *site) {
    // Simulate website response time
    site->response_time = (rand() % MAX_RESPONSE_TIME) + 1;
    if (site->response_time > 2000) {
        site->failed_attempts++;
        printf("\n%s: Offline (%dms)\n", site->url, site->response_time);
        if (site->failed_attempts >= MAX_FAILED_ATTEMPTS) {
            printf("ALERT: %s has gone offline permanently\n", site->url);
            site->response_time = -1;
        }
    } else {
        site->failed_attempts = 0;
        printf("\n%s: Online (%dms)\n", site->url, site->response_time);
    }
}

int main() {
    // Initialize random number generator
    srand(time(NULL));
    
    // Define an array of website structs
    Website sites[] = {
        {"www.google.com", 0, 0},
        {"www.yahoo.com", 0, 0},
        {"www.facebook.com", 0, 0},
        {"www.twitter.com", 0, 0},
        {"www.reddit.com", 0, 0},
        {"www.linkedin.com", 0, 0},
        {"www.amazon.com", 0, 0},
        {"www.microsoft.com", 0, 0},
        {"www.github.com", 0, 0},
        {"www.stackoverflow.com", 0, 0}
    };
    
    int num_sites = sizeof(sites) / sizeof(Website);
    
    // Loop through websites and check uptime
    while (1) {
        printf("\n\n=== WEBSITE UPTIME MONITOR ===\n\n");
        for (int i = 0; i < num_sites; i++) {
            check_website(&sites[i]);
        }
        printf("\n\nSleeping for 1 minute\n");
        sleep(60);
    }
    
    return 0;
}