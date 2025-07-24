//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Internet Speed Test Application!\n\n");

    int downloadSpeed, uploadSpeed;
    srand(time(NULL));

    // Generate download speed between 5 and 100 Mbps
    downloadSpeed = rand() % 96 + 5;
    printf("Testing download speed... Please wait...\n");
    printf("Your download speed is %d Mbps.\n\n", downloadSpeed);

    // Generate upload speed between 1 and 20 Mbps
    uploadSpeed = rand() % 19 + 1;
    printf("Testing upload speed... Please wait...\n");
    printf("Your upload speed is %d Mbps.\n\n", uploadSpeed);

    // Check download speed
    if (downloadSpeed <= 10) {
        printf("Your download speed is very slow.\n");
    } else if (downloadSpeed <= 50) {
        printf("Your download speed is average.\n");
    } else {
        printf("Your download speed is excellent!\n");
    }

    // Check upload speed
    if (uploadSpeed <= 5) {
        printf("Your upload speed is very slow.\n");
    } else if (uploadSpeed <= 10) {
        printf("Your upload speed is average.\n");
    } else {
        printf("Your upload speed is excellent!\n");
    }

    return 0;
}