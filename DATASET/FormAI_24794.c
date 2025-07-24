//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Generate random internet speed (in Mbps)
    srand(time(NULL));
    float speed = (rand() % 90) + 10; // Generate a random number between 10 and 100
    
    // Display internet speed
    printf("Your internet speed is: %.2f Mbps\n", speed);
    
    // Determine internet speed quality
    char quality[20];
    if (speed >= 90) {
        strcpy(quality, "Excellent");
    } else if (speed >= 60) {
        strcpy(quality, "Good");
    } else if (speed >= 30) {
        strcpy(quality, "Average");
    } else if (speed >= 10) {
        strcpy(quality, "Poor");
    } else {
        strcpy(quality, "No connection");
    }
    
    // Display internet speed quality
    printf("Internet speed quality: %s\n", quality);
    
    // Ask user to repeat test
    char repeat;
    printf("Do you want to test your internet speed again? (y/n) ");
    scanf(" %c", &repeat);
    
    // Loop until user enters 'n' to stop repeating test
    while (repeat != 'n') {
        // Generate random internet speed (in Mbps)
        speed = (rand() % 90) + 10;
        
        // Display internet speed
        printf("Your internet speed is: %.2f Mbps\n", speed);
        
        // Determine internet speed quality
        if (speed >= 90) {
            strcpy(quality, "Excellent");
        } else if (speed >= 60) {
            strcpy(quality, "Good");
        } else if (speed >= 30) {
            strcpy(quality, "Average");
        } else if (speed >= 10) {
            strcpy(quality, "Poor");
        } else {
            strcpy(quality, "No connection");
        }
        
        // Display internet speed quality
        printf("Internet speed quality: %s\n", quality);
        
        // Ask user to repeat test
        printf("Do you want to test your internet speed again? (y/n) ");
        scanf(" %c", &repeat);
    }
    
    // End program
    return 0;
}