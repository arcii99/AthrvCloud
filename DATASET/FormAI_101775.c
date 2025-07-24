//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float download_speed, upload_speed;
    int time_taken;

    printf("\nWelcome to the Internet Speed Test Application\n\n");

    time_t start_time = time(NULL);

    // Simulating download and upload by sleeping for random seconds between 1 and 10
    srand(time(0));

    int download_time = (rand() % 10) + 1;  // in seconds
    sleep(download_time);

    time_t download_end_time = time(NULL);

    int upload_time = (rand() % 10) + 1;  // in seconds
    sleep(upload_time);

    time_t upload_end_time = time(NULL);

    time_taken = (int)difftime(download_end_time, start_time) + (int)difftime(upload_end_time, download_end_time);
    download_speed = (float)(1024 * 8) / (float)download_time;
    upload_speed = (float)(1024 * 8) / (float)upload_time;

    printf("Download speed: %.1f Mbps\n", download_speed);
    printf("Upload speed: %.1f Mbps\n", upload_speed);
    printf("Time taken: %d seconds\n", time_taken);

    return 0;
}