//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define NUM_TESTS 5

/**
 * This function simulates downloading a file
 * It takes the download speed and the file size as input
 * and returns the download time in seconds
 */
double simulate_download(double speed, double size) {
    return size / speed;
}

/**
 * This function simulates uploading a file
 * It takes the upload speed and the file size as input
 * and returns the upload time in seconds
 */
double simulate_upload(double speed, double size) {
    return size / speed;
}

/**
 * This function calculates the average of an array of values
 * It takes the array of values and the number of values as input
 * and returns the average value
 */
double calculate_average(double values[], int num_values) {
    double sum = 0;
    int i;

    for (i = 0; i < num_values; i++) {
        sum += values[i];
    }

    return sum / num_values;
}

int main() {
    char response[BUFFER_SIZE];
    double download_speeds[NUM_TESTS], upload_speeds[NUM_TESTS];
    double download_time, upload_time, download_speed, upload_speed;
    double download_size = 1024000; // 1MB file
    double upload_size = 512000; // 500KB file
    int i;

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Please press enter to begin the test.\n");
    fgets(response, BUFFER_SIZE, stdin);

    srand(time(NULL));

    for (i = 0; i < NUM_TESTS; i++) {
        // Simulate download test
        download_speeds[i] = (double) rand() / RAND_MAX * 9 + 1; // Random speed between 1-10 Mbps
        download_time = simulate_download(download_speeds[i], download_size);
        printf("Download test %d\n", i+1);
        printf("Download speed: %.2f Mbps\n", download_speeds[i]);
        printf("Download time: %.2f seconds\n", download_time);

        // Simulate upload test
        upload_speeds[i] = (double) rand() / RAND_MAX * 4 + 1; // Random speed between 1-5 Mbps
        upload_time = simulate_upload(upload_speeds[i], upload_size);
        printf("Upload test %d\n", i+1);
        printf("Upload speed: %.2f Mbps\n", upload_speeds[i]);
        printf("Upload time: %.2f seconds\n", upload_time);

        printf("\n");
    }

    // Calculate and print average speeds
    download_speed = calculate_average(download_speeds, NUM_TESTS);
    upload_speed = calculate_average(upload_speeds, NUM_TESTS);

    printf("Overall Results:\n");
    printf("Download speed: %.2f Mbps\n", download_speed);
    printf("Upload speed: %.2f Mbps\n", upload_speed);

    return 0;
}