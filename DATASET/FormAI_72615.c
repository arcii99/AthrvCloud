//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random internet speed
float generateSpeed() {
    return rand() % 100 + 1; // Generate random speed in the range 1-100 Mbps
}

int main() {
    srand(time(NULL)); // Initialize random seed
    
    printf("Welcome to the Internet Speed Test Application!\n\n");
    printf("This program will generate a random internet speed between 1-100 Mbps and test your connection.\n\n");
    
    float speed = generateSpeed();
    
    printf("Testing your internet speed...\n\n");
    printf("Your internet speed is %.2f Mbps.\n\n", speed);
    
    if (speed >= 70) {
        printf("Wow, your internet speed is excellent! You can easily stream and download large files without any lag.\n");
    } else if (speed >= 50 && speed < 70) {
        printf("Your internet speed is good. You can stream videos and download files at a decent speed.\n");
    } else if (speed >= 30 && speed < 50) {
        printf("Your internet speed is average. You may experience some buffering while streaming videos.\n");
    } else {
        printf("Sorry, your internet speed is slow. You may experience frequent buffering while streaming videos.\n");
    }
    
    return 0; // Exit program
}