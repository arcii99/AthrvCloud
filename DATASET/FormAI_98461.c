//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int internetSpeedTest() {
    int downloadSpeed, uploadSpeed; // declare variables

    printf("Welcome to the internet speed test application.\n");

    // generate random download speed between 1 and 100 Mbps
    srand(time(0)); 
    downloadSpeed = rand() % 100 + 1;
    printf("Your download speed is: %d Mbps.\n", downloadSpeed);

    // generate random upload speed between 1 and 50 Mbps
    srand(time(0) + 1); 
    uploadSpeed = rand() % 50 + 1;
    printf("Your upload speed is: %d Mbps.\n", uploadSpeed);

    // determine internet speed tier based on download speed
    if (downloadSpeed >= 50) {
        printf("You have a blazing fast internet speed!\n");
    } else if (downloadSpeed >= 25) {
        printf("You have a fast internet speed.\n");
    } else if (downloadSpeed >= 10) {
        printf("Your internet speed is average.\n");
    } else {
        printf("Your internet speed is slow.\n");
    }

    return 0;
}

int main() {
    internetSpeedTest(); // call the internet speed test function
    return 0;
}