//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the website is up or not
bool checkWebsite(char url[]) {
    // Use system ping command to check if the website is up
    char command[100];
    sprintf(command, "ping -c 1 %s", url);
    bool result = system(command) == 0;
    return result;
}

int main() {
    // Define the website to monitor
    char website[] = "www.example.com";
    // Define the frequency of checking the website status in seconds
    int frequency = 30;

    while (true) {
        // Check the website status
        bool isWebsiteUp = checkWebsite(website);

        if (isWebsiteUp) {
            printf("Website is up!\n");
        } else {
            printf("Website is down!\n");
        }

        // Wait for the specified frequency before checking the website status again
        sleep(frequency);
    }

    return 0;
}