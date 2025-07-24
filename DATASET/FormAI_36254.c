//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function that simulates internet speed test */
void speedtest() {
    srand(time(NULL));
    int download_speed = rand() % 100 + 1; // Generate random download speed from 1 to 100 Mbps
    int upload_speed = rand() % 100 + 1; // Generate random upload speed from 1 to 100 Mbps
    
    printf("Testing download speed...\n");
    for (int i = 0; i < download_speed; i++) {
        printf("Downloading: %d Mbps\n", i+1);
        usleep(100000); // Simulate download by waiting for 0.1 seconds
    }
    
    printf("\nTesting upload speed...\n");
    for (int i = 0; i < upload_speed; i++) {
        printf("Uploading: %d Mbps\n", i+1);
        usleep(100000); // Simulate upload by waiting for 0.1 seconds
    }
    
    printf("\nDownload speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
}

/* Main function */
int main() {
    printf("Welcome to the Internet Speed Test\n");
    printf("Press any key to start the test...\n");
    getchar(); // Wait for user input
    
    speedtest(); // Call speedtest function
    
    printf("\nTest completed. Thank you for using the Internet Speed Test!\n");
    return 0;
}