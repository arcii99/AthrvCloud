//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to check if website is up or down
bool isWebsiteUp() {
    // Generate a random number between 0 and 9
    int randomNum = rand() % 10;
    
    // If the number is less than 5, website is up. Otherwise, it's down.
    if(randomNum < 5) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Define the URL to monitor
    char *url = "https://www.example.com";
    
    // Set the initial status of the website to up
    bool isUp = true;
    
    // Check the status of the website every 5 seconds
    while(true) {
        // If the website is up, print a success message
        if(isUp) {
            printf("%s is up!\n", url);
        } else { // Otherwise, print an error message
            printf("%s is down!\n", url);
        }
        
        // Check the status of the website
        isUp = isWebsiteUp();
        
        // Sleep for 5 seconds before checking again
        sleep(5);
    }
    
    return 0;
}