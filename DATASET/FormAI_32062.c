//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function that generates a random speed between 1 to 100 Mbps
int generateSpeed() {
    return (rand() % 100) + 1;
}

int main() {
    srand(time(NULL));  // Initializing the random number generator

    printf("Welcome to the Internet Speed Test!\n\n");

    // Generating the speeds for download and upload
    int downloadSpeed = generateSpeed();
    int uploadSpeed = generateSpeed();

    // Displaying the generated speeds
    printf("Download speed: %d Mbps\n", downloadSpeed);
    printf("Upload speed: %d Mbps\n", uploadSpeed);
    
    // Calculating the average speed
    float averageSpeed = (downloadSpeed + uploadSpeed) / 2.0;
    printf("Average speed: %.2f Mbps\n", averageSpeed);
    
    // Checking if the average speed is good or bad
    if (averageSpeed >= 50) {
        printf("Great internet speed! You can stream HD videos without any buffering.\n");
    } else if (averageSpeed >= 20) {
        printf("Good internet speed! You can stream SD videos without any buffering.\n");
    } else {
        printf("Poor internet speed! You may face buffering issues while streaming videos.\n");
    }
    
    return 0;
}