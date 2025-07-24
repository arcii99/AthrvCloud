//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SPEED_TEST_TIME_LIMIT 10 /* duration of speed test in seconds */
#define BUFFER_SIZE 128         /* size of buffer used to download data */

double speed_test() {
    double total_bytes_downloaded = 0;
    time_t start_time = time(NULL);
    time_t end_time = start_time + SPEED_TEST_TIME_LIMIT;
    while (time(NULL) < end_time) {
        /* simulate downloading data */
        sleep(1);
        total_bytes_downloaded += BUFFER_SIZE;
    }
    return total_bytes_downloaded / SPEED_TEST_TIME_LIMIT;
}

int main() {
    printf("Welcome to the C Internet Speed Test Application\n");
    printf("We will now perform a speed test of your internet connection\n");
    printf("Please wait while we download data...\n");
    double download_speed = speed_test();
    printf("Speed test complete!\n");
    printf("Your download speed is %.2f bytes per second\n", download_speed);
    return 0;
}