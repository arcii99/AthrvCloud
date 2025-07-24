//FormAI DATASET v1.0 Category: Browser Plugin ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing statistics 
typedef struct {
    int numRequests;    // Total number of requests made by the user
    int numBlocked;     // Number of requests that were blocked by the plugin
    double blockRate;   // Percentage of requests that were blocked
} Statistics;

// Function to calculate the block rate
double calcBlockRate(Statistics *stats) {
    if (stats->numRequests == 0) {
        return 0.0;
    }
    return (double) stats->numBlocked / stats->numRequests * 100.0;
}

// Function to handle a browser request
void handleRequest(char *request, Statistics *stats) {
    // Check if the request contains a blocked domain
    if (strstr(request, "blocked-site.com") != NULL) {
        printf("Request for %s blocked by plugin\n", request);
        stats->numBlocked++;
    } else {
        printf("Request for %s allowed\n", request);
    }
    stats->numRequests++;
}

// Main function to run the plugin
int main() {
    printf("Starting plugin...\n");

    Statistics stats = {0, 0, 0.0};

    // Simulate some browser requests
    char *requests[10] = {"google.com", "facebook.com", "blocked-site.com", "twitter.com", 
                         "blocked-site.com", "youtube.com", "linkedin.com", "blocked-site.com", 
                         "amazon.com", "blocked-site.com"};
    for (int i = 0; i < 10; i++) {
        handleRequest(requests[i], &stats);
    }

    // Calculate block rate and update stats
    stats.blockRate = calcBlockRate(&stats);
    printf("Block rate: %.2f%%\n", stats.blockRate);

    printf("Plugin complete.\n");

    return 0;
}