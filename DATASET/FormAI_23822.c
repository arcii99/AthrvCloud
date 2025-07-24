//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

// Define URL and timeout for testing
#define URL "https://example.com"
#define TIMEOUT 10

// Function to check if website is up or down
bool isWebsiteUp() {
    FILE *fp = NULL;
    char command[1024] = "";
    sprintf(command, "curl --connect-timeout %d -Is %s | head -n 1 | cut -d ' ' -f 2", TIMEOUT, URL);
    fp = popen(command, "r");
    if(fp == NULL) {
        return false;
    }
    char result[10];
    fgets(result, sizeof(result), fp);
    pclose(fp);
    return (strcmp(result, "200") == 0);
}

int main() {
    bool isUp = false;
    while(1) {
        isUp = isWebsiteUp();
        if(isUp) {
            printf("Website is up!\n");
        } else {
            printf("Website is down!\n");
        }
        sleep(60);
    }
    return 0;
}