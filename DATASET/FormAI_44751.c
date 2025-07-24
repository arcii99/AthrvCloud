//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1024

float download_speed_test() {
    // Generate random data of size 10MB
    char data[BUFFER_SIZE];
    srand(time(NULL)); // Seed for generating random numbers
    for (int i = 0; i < BUFFER_SIZE; i++) {
        data[i] = rand() % 256; // Fill data with random 8-bit values
    }

    printf("Starting download speed test...\n");

    // Start timer
    clock_t start_time = clock();

    // Simulate downloading data
    for (int i = 0; i < 10000; i++) {
        printf("Downloading chunk %d...\n", i+1);
        // Simulate network delay by sleeping for a random number of microseconds
        usleep(rand()%1000);
    }

    // Stop timer
    clock_t end_time = clock();

    float download_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate time in seconds
    float download_speed = (BUFFER_SIZE * 10000) / (download_time * 1024 * 1024); // Calculate download speed in Mbps
    printf("Download speed: %.2f Mbps\n", download_speed);

    return download_speed;
}

float upload_speed_test() {
    char data[BUFFER_SIZE];
    printf("Starting upload speed test...\n");

    // Start timer
    clock_t start_time = clock();

    // Simulate uploading data
    for (int i = 0; i < 100; i++) {
        printf("Uploading chunk %d...\n", i+1);
        // Simulate network delay by sleeping for a random number of microseconds
        usleep(rand()%1000);
    }

    // Stop timer
    clock_t end_time = clock();

    float upload_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate time in seconds
    float upload_speed = (BUFFER_SIZE * 100) / (upload_time * 1024 * 1024); // Calculate upload speed in Mbps
    printf("Upload speed: %.2f Mbps\n", upload_speed);

    return upload_speed;
}

int main() {
    // Run download and upload speed tests
    float download_speed = download_speed_test();
    float upload_speed = upload_speed_test();

    // Calculate average speed
    float avg_speed = (download_speed + upload_speed) / 2;
    printf("Average speed: %.2f Mbps\n", avg_speed);

    return 0;
}