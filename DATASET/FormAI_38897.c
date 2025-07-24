//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define constants
#define MAX_URL_LENGTH 200
#define MAX_RETRIES 3

// Define functions
void printBanner();
void checkWebsite(char url[MAX_URL_LENGTH], int tries);

int main() {
    srand(time(0));  // Seed random number generator with current time
    char websites[5][MAX_URL_LENGTH] = {"www.google.com", "www.facebook.com", "www.twitter.com", "www.amazon.com", "www.youtube.com"};

    printBanner();

    // Loop through each website and check its uptime status
    for (int i = 0; i < 5; i++) {
        checkWebsite(websites[i], MAX_RETRIES);
    }

    return 0;
}

// Function to print program banner
void printBanner() {
    printf("=======================================\n");
    printf("===== WEBSITE UPTIME MONITOR v1.0 =====\n");
    printf("=======================================\n\n");
}

// Function to check website uptime status
void checkWebsite(char url[MAX_URL_LENGTH], int tries) {
    int status = rand() % 2;  // Generate random 0 or 1 for website status
    int delay = rand() % 5 + 1;  // Generate random delay between 1 and 5 seconds

    printf("Checking %s...\n", url);

    // Retry checking website for specified number of times if it is down
    for (int i = 0; i < tries; i++) {
        if (status == 0) {
            printf("Website is down. Retrying in %d second(s).\n", delay);
            sleep(delay);
            status = rand() % 2;  // Generate new random status after delay
        } else {
            printf("Website is up!\n\n");
            return;
        }
    }

    printf("Website is still down after %d retries. Please check your internet connection.\n\n", tries);
}