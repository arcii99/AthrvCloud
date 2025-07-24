//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The function to simulate an Internet speed test
double speedTest() {
    // A random download speed between 1 and 100 Mbps
    double downloadSpeed = 1 + rand() % 100;
    
    // A random upload speed between 1 and 50 Mbps
    double uploadSpeed = 1 + rand() % 50;
    
    // Sleep for random time between 1 and 5 seconds to simulate the test
    int sleepTime = 1 + rand() % 5;
    printf("Testing your internet speed, please wait for %d seconds...\n", sleepTime);
    sleep(sleepTime);
    
    // Print the results of the test
    printf("Your internet speed test results are:\n");
    printf("Download Speed: %.2f Mbps\n", downloadSpeed);
    printf("Upload Speed: %.2f Mbps\n", uploadSpeed);
    
    // Return the download speed in Mbps
    return downloadSpeed;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Call the speedTest function to start the test and get the download speed in Mbps
    double downloadSpeed = speedTest();
    
    // Determine the quality of the download speed
    if (downloadSpeed >= 50) {
        printf("Your internet speed is excellent!\n");
    } else if (downloadSpeed >= 25 && downloadSpeed < 50) {
        printf("Your internet speed is good.\n");
    } else if (downloadSpeed >= 10 && downloadSpeed < 25) {
        printf("Your internet speed is average.\n");
    } else {
        printf("Your internet speed is poor.\n");
    }
    
    return 0;
}