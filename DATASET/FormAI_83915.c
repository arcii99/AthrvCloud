//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SPEED 1000
#define MIN_SPEED 10

int main() {
    int speed = 0;
    int downloadTime = 0;

    srand((unsigned) time(NULL));

    printf("Starting internet speed test...\n");

    // simulate internet speed test by generating a random speed between MIN_SPEED and MAX_SPEED
    speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;

    printf("Your internet speed is: %d Mbps\n", speed);

    // calculate estimated download time for a 1GB file based on internet speed
    downloadTime = ceil(1000.00 / speed);

    printf("Estimated download time for a 1GB file: %d seconds\n", downloadTime);

    return 0;
}