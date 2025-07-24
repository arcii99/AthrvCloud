//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    int mbps = 0;
    int download_speed = 0;
    int upload_speed = 0;
    int duration = 0;

    printf("Welcome to the Internet Speed Test Application!\n");

    printf("Please enter the speed of your internet connection in Mbps: ");
    scanf("%d", &mbps);

    if (mbps < 0) { // Checking if mbps is a positive integer
        printf("Invalid input. Please enter a positive integer for internet speed.");
        return 0; 
    }

    printf("Testing download speed...\n");
    // Simulating download speed test
    srand(time(NULL));
    download_speed = rand() % (mbps + 1); // Download speed cannot exceed internet speed
    duration = rand() % 10 + 1; // Test duration between 1 to 10 seconds
    printf("Your download speed is %d Mbps in %d seconds.\n", download_speed, duration);

    printf("Testing upload speed...\n");
    // Simulating upload speed test
    srand(time(NULL));
    upload_speed = rand() % (mbps + 1); // Upload speed cannot exceed internet speed
    duration = rand() % 10 + 1; // Test duration between 1 to 10 seconds
    printf("Your upload speed is %d Mbps in %d seconds.\n", upload_speed, duration);

    printf("Thank you for using the Internet Speed Test Application!\n");
    return 0;
}