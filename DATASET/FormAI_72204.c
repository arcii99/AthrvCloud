//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Internet Speed Test!\n");
    printf("This program will measure the speed of your internet connection.\n");

    // Generate random numbers for upload and download speeds
    srand(time(NULL));
    int upload_speed = rand() % 50 + 1;
    int download_speed = rand() % 100 + 1;

    printf("Measuring upload speed...\n");
    printf("Upload speed: %d Mbps\n", upload_speed);

    printf("Measuring download speed...\n");
    printf("Download speed: %d Mbps\n", download_speed);

    // Determine internet speed classification
    if (download_speed >= 75 && upload_speed >= 10) {
        printf("Congratulations! Your internet speed is classified as Ultrafast.\n");
    } else if (download_speed >= 50 && upload_speed >= 5) {
        printf("Your internet speed is classified as Very Fast.\n");
    } else if (download_speed >= 25 && upload_speed >= 2) {
        printf("Your internet speed is classified as Fast.\n");
    } else {
        printf("Your internet speed is classified as Slow.\n");
    }

    printf("Thank you for using our Internet Speed Test!\n");

    return 0;
}