//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed random number generator
    
    int websiteStatus = rand() % 2; // Generate random number between 0 and 1
    
    if(websiteStatus == 1) {
        printf("Website is up and running smoothly!"); 
    } else {
        printf("Oh no! The website is down!");
    }
    
    return 0;
}