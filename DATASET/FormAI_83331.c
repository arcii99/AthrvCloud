//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double start_time, elapsed_time;
    int download_speed, upload_speed;
    int download_size = 10000000; // 10 megabytes
    int upload_size = 5000000; // 5 megabytes

    // Start timer
    start_time = clock();

    // Simulate download speed test
    printf("Starting download test...\n");
    for (int i = 0; i < download_size; i++) {
        // Simulate download of 1 byte
        // Random delay between 1 and 10 milliseconds
        delay(rand() % 10 + 1);
    }

    // Calculate elapsed time and speed
    elapsed_time = (clock() - start_time) / CLOCKS_PER_SEC;
    download_speed = download_size / elapsed_time;
    printf("Download speed: %d bytes per second\n", download_speed);

    // Start timer
    start_time = clock();

    // Simulate upload speed test
    printf("Starting upload test...\n");
    for (int i = 0; i < upload_size; i++) {
        // Simulate upload of 1 byte
        // Random delay between 1 and 10 milliseconds
        delay(rand() % 10 + 1);
    }

    // Calculate elapsed time and speed
    elapsed_time = (clock() - start_time) / CLOCKS_PER_SEC;
    upload_speed = upload_size / elapsed_time;
    printf("Upload speed: %d bytes per second\n", upload_speed);

    return 0;
}

void delay(int milliseconds) {
    // Delay function
    // Parameter: milliseconds
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds) {}
}