//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_URL_LENGTH 100
#define MAX_RESPONSE_LENGTH 1000

// Define a struct for holding website information
typedef struct website {
    char url[MAX_URL_LENGTH];
    int uptime;
    int downtime;
    int total_requests;
} website_t;

// Function to check the uptime of a website
int check_website(char *url) {
    // Use curl to send a GET request to the website
    // and check the response code
    char command[200];
    int response;
    sprintf(command, "curl --write-out %%{http_code} --silent --output /dev/null %s", url);
    response = atoi(system(command));

    return response >= 200 && response < 300;
}

// Function to update the uptime and downtime of a website
void update_website_stats(website_t *website) {
    int result = check_website(website->url);
    website->total_requests++;

    if (result) {
        website->uptime++;
    }
    else {
        website->downtime++;
    }
}

int main() {
    // Define an array of websites to monitor
    const char *monitor_urls[] = {"https://www.google.com", "https://www.facebook.com", "https://www.amazon.com"};

    // Calculate the number of websites to monitor
    int num_monitor_urls = sizeof(monitor_urls) / sizeof(char *);

    // Create an array of website structs to hold monitoring data
    website_t websites[num_monitor_urls];

    // Initialize website structs with URLs
    for (int i = 0; i < num_monitor_urls; i++) {
        strncpy(websites[i].url, monitor_urls[i], MAX_URL_LENGTH);
    }

    // Monitor website uptime
    while (1) {
        for (int i = 0; i < num_monitor_urls; i++) {
            update_website_stats(&websites[i]);
            printf("%s uptime: %d%%, downtime: %d%%\n", websites[i].url, (int)(websites[i].uptime / (float)websites[i].total_requests * 100), (int)(websites[i].downtime / (float)websites[i].total_requests * 100));
        }
        sleep(60); // wait for 1 minute
    }

    return 0;
}