//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100 // Maximum internet speed in Mbps
#define MIN_SPEED 1 // Minimum internet speed in Mbps

double random_speed(double min, double max) {
    return min + (((double) rand()) / RAND_MAX) * (max - min);
}

int main() {
    srand(time(NULL));

    double download_speed = random_speed(MIN_SPEED, MAX_SPEED);
    double upload_speed = random_speed(MIN_SPEED, MAX_SPEED);

    printf("Welcome to the Internet Speed Test Application!\n\n");
    printf("Testing Download Speed... %.2f Mbps\n", download_speed);
    printf("Testing Upload Speed... %.2f Mbps\n\n", upload_speed);

    printf("Your internet speed is:\n");
    if (download_speed >= 50 && upload_speed >= 50) {
        printf("Blazing Fast!\n");
    } else if (download_speed >= 20 && upload_speed >= 20) {
        printf("Fast\n");
    } else if (download_speed >= 5 && upload_speed >= 5) {
        printf("OK\n");
    } else {
        printf("Slow\n");
    }

    return 0;
}