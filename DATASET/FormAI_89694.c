//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define constants for conversion to Mbps & KB/s
#define BITS_IN_BYTE 8
#define KILO_BYTE_PER_SEC 1024
#define MEGA_BIT_PER_SEC 1000000

// Declare function to calculate download speed
float calculate_download_speed(int downloaded_bytes, int elapsed_time) {
    float download_speed = (float)(downloaded_bytes * BITS_IN_BYTE) / (float)(elapsed_time * MEGA_BIT_PER_SEC);
    return download_speed;
}

// Declare function to calculate upload speed
float calculate_upload_speed(int uploaded_bytes, int elapsed_time) {
    float upload_speed = (float)(uploaded_bytes * BITS_IN_BYTE) / (float)(elapsed_time * MEGA_BIT_PER_SEC);
    return upload_speed;
}

// Function for running internet speed test
void run_speed_test() {
    // Define variables for tracking download and upload speed
    int downloaded_bytes = 0;
    int uploaded_bytes = 0;
    float download_speed = 0.0;
    float upload_speed = 0.0;

    // Get current time as start time
    time_t start_time = time(NULL);

    // Simulate download speed test by downloading a file
    printf("Testing download speed...\n");
    for (int i = 0; i < 10 * KILO_BYTE_PER_SEC * 1024; i++) {
        downloaded_bytes++;
    }

    // Get time difference between now and start time
    time_t end_time = time(NULL);
    int elapsed_time = difftime(end_time, start_time);

    // Calculate download speed
    download_speed = calculate_download_speed(downloaded_bytes, elapsed_time);

    // Simulate upload speed test by uploading a file
    printf("Testing upload speed...\n");
    for (int i = 0; i < 5 * KILO_BYTE_PER_SEC * 1024; i++) {
        uploaded_bytes++;
    }

    // Get time difference between now and start time
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    // Calculate upload speed
    upload_speed = calculate_upload_speed(uploaded_bytes, elapsed_time);

    // Print results
    printf("\n");
    printf("Download speed: %.2f Mbps\n", download_speed);
    printf("Upload speed: %.2f Mbps\n", upload_speed);
    printf("Download speed in KB/s: %.2f KB/s\n", download_speed * MEGA_BIT_PER_SEC / KILO_BYTE_PER_SEC);
    printf("Upload speed in KB/s: %.2f KB/s\n", upload_speed * MEGA_BIT_PER_SEC / KILO_BYTE_PER_SEC);
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Introduce the program
    printf("Welcome to the minimalistic internet speed test!\n\n");

    // Start speed test
    run_speed_test();

    return 0;
}