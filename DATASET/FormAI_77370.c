//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int downloadSpeed, uploadSpeed; // to store the speeds
    int randomNum; // to generate random integers
    int i; // counter variable

    srand(time(NULL)); // seed the random number generator with time

    // generate random download and upload speeds between 0 and 100 Mbps
    downloadSpeed = rand() % 101; 
    uploadSpeed = rand() % 101;

    // simulate download and upload speed tests
    printf("Running download speed test...\n");
    for (i = 0; i < 10; i++) {
        randomNum = rand() % 101;
        if (randomNum > downloadSpeed) {
            printf("Download speed test failed. Speed was %d Mbps\n", randomNum);
            return 1; // exit with error
        }
    }
    printf("Download speed test passed. Speed was %d Mbps\n", downloadSpeed);

    printf("Running upload speed test...\n");
    for (i = 0; i < 10; i++) {
        randomNum = rand() % 101;
        if (randomNum > uploadSpeed) {
            printf("Upload speed test failed. Speed was %d Mbps\n", randomNum);
            return 1; // exit with error
        }
    }
    printf("Upload speed test passed. Speed was %d Mbps\n", uploadSpeed);

    return 0; // exit successfully
}