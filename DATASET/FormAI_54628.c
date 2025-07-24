//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting up variables
    int download_speed, upload_speed;
    int random_num1, random_num2;
    int time_elapsed;
    time_t start_time, end_time;

    // Generating random numbers between 1 and 100 for download and upload speeds
    srand(time(NULL));
    random_num1 = rand() % 100 + 1;
    random_num2 = rand() % 100 + 1;

    // Starting timer
    printf("Starting Internet Speed Test...\n");
    time(&start_time);

    // Simulating download and upload speeds
    printf("Downloading test file...\n");
    for (int i = 0; i < 10; i++) {
        printf("Downloading... %d%% complete\n", (i + 1) * 10);
        sleep(1);
    }
    printf("Download complete!\n");
    download_speed = random_num1 * 1000;

    printf("Uploading test file...\n");
    for (int i = 0; i < 10; i++) {
        printf("Uploading... %d%% complete\n", (i + 1) * 10);
        sleep(1);
    }
    printf("Upload complete!\n");
    upload_speed = random_num2 * 1000;

    // Ending timer and calculating time elapsed
    time(&end_time);
    time_elapsed = difftime(end_time, start_time);

    // Displaying results
    printf("\nRESULTS:\n");
    printf("Download speed: %d kbps\n", download_speed);
    printf("Upload speed: %d kbps\n", upload_speed);
    printf("Time elapsed: %d seconds\n", time_elapsed);

    // Checking for suspicious activity
    if (download_speed < 1000 || upload_speed < 1000 || time_elapsed > 30) {
        printf("\nWARNING: Suspicious activity detected!\n");
    }

    printf("\nInternet Speed Test Complete.\n");

    return 0;
}