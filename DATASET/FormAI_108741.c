//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define DOWNLOAD_SIZE 1000000 // bytes
#define UPLOAD_SIZE 500000 // bytes
#define DELAY 1000000 // microseconds
#define MAX_TEST_CASES 3 // number of times to run the test

// function to simulate a download
double downloadTest() {
    double startTime = clock();
    // simulate download delay
    usleep(DELAY);
    double endTime = clock();
    double downloadTime = (endTime - startTime) / CLOCKS_PER_SEC;
    return DOWNLOAD_SIZE / downloadTime;
}

//function to simulate an upload
double uploadTest() {
    double startTime = clock();
    // simulate upload delay
    usleep(DELAY);
    double endTime = clock();
    double uploadTime = (endTime - startTime) / CLOCKS_PER_SEC;
    return UPLOAD_SIZE / uploadTime;
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Press Enter to start the test...\n");
    getchar(); // wait for user to hit Enter

    for (int i = 0; i < MAX_TEST_CASES; i++) {
        printf("Running test #%d...\n", i+1);
        double downloadSpeed = downloadTest();
        double uploadSpeed = uploadTest();
        printf("Download speed: %0.2f Mbps\n", downloadSpeed);
        printf("Upload speed: %0.2f Mbps\n", uploadSpeed);
        printf("\n");
        usleep(DELAY*2); // delay between test cases
    }

    printf("Test complete!\n");
    return 0;
}