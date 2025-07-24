//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    printf("Welcome to the happiest internet speed test!\n");

    // Generate random download speed between 5 and 100 Mbps
    srand(time(NULL));
    int download_speed = (rand() % 96) + 5;
    printf("Your download speed is: %d Mbps\n", download_speed);

    // Calculate expected download time for a 1GB file
    int file_size = 1000; // MB
    float download_time = ((float)file_size / download_speed) * 8;
    int hours = (int)floor(download_time / 3600);
    int minutes = (int)floor((download_time - (hours * 3600)) / 60);
    int seconds = (int)floor(download_time - (hours * 3600) - (minutes * 60));
    printf("It would take approximately %d hours, %d minutes, and %d seconds to download a 1GB file at %d Mbps.\n", hours, minutes, seconds, download_speed);

    // Generate random upload speed between 1 and 20 Mbps
    int upload_speed = (rand() % 20) + 1;
    printf("Your upload speed is: %d Mbps\n", upload_speed);

    // Calculate expected upload time for a 100MB file
    file_size = 100; // MB
    float upload_time = ((float)file_size / upload_speed) * 8;
    int upload_seconds = (int)floor(upload_time);
    printf("It would take approximately %d seconds to upload a 100MB file at %d Mbps.\n", upload_seconds, upload_speed);

    printf("Thank you for using the happiest internet speed test! Have a great day!\n");

    return 0;
}