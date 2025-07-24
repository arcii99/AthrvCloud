//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int speed_test() {
    int download_speed = rand_range(1, 100); // Random download speed in Mb/s
    printf("Starting speed test...\n");
    printf("Your download speed is %d Mb/s\n", download_speed);
    if (download_speed >= 50) {
        printf("Great news! Your internet speed is excellent.\n");
    } else if (download_speed >= 25 && download_speed < 50) {
        printf("Your internet speed is good, but there is room for improvement.\n");
    } else if (download_speed >= 10 && download_speed < 25) {
        printf("Your internet speed is average, consider upgrading your plan.\n");
    } else {
        printf("Your internet speed is slow, upgrade your plan or contact your provider.\n");
    }
    return download_speed;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int result = speed_test();
    return 0;
}