//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define URL_MAX_LENGTH 100
#define MAX_URLS 10

struct url {
    char address[URL_MAX_LENGTH];
    int uptime;
};

int main() {
    struct url urls[MAX_URLS];
    
    // Input URLs to monitor
    int num_urls;
    printf("Enter number of URLs to monitor (Maximum %d allowed): ", MAX_URLS);
    scanf("%d", &num_urls);
    printf("Enter URLs to monitor (Maximum length %d):\n", URL_MAX_LENGTH);
    for (int i = 0; i < num_urls; i++) {
        printf("URL %d address: ", i+1);
        scanf("%s", urls[i].address);
        urls[i].uptime = 0;
    }
    
    // Monitor URLs
    printf("\nMonitoring URLs...\n");
    while (1) {
        for (int i = 0; i < num_urls; i++) {
            int random_status = rand() % 10;
            if (random_status < 3) { // Randomly generate downtime
                urls[i].uptime = 0;
                printf("%s is currently down!\n", urls[i].address);
            }
            else {
                urls[i].uptime++;
                printf("%s is up! Uptime: %d\n", urls[i].address, urls[i].uptime);
            }
        }
        printf("\n");
        sleep(10);
    }
    
    return 0;
}