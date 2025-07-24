//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char speed[20];

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Please enter the internet speed you want to test (in Mbps): ");
    fgets(speed, 20, stdin);

    int len = strlen(speed);
    if (speed[len - 1] == '\n') {
        speed[len - 1] = '\0';
    }

    printf("Okay, testing internet speed for %s...\n", speed);

    int speedInt = atoi(speed);
    if (speedInt < 10) {
        printf("Sorry, we cannot test internet speeds below 10 Mbps.\n");
        printf("Please enter a valid speed (in Mbps): ");
        fgets(speed, 20, stdin);
        len = strlen(speed);
        if (speed[len - 1] == '\n') {
            speed[len - 1] = '\0';
        }
        speedInt = atoi(speed);
    }

    printf("Testing download speed...\n");
    int downloadSpeed = (speedInt / 2) + (rand() % 10);
    printf("Download speed: %d Mbps.\n", downloadSpeed);

    printf("Testing upload speed...\n");
    int uploadSpeed = (speedInt / 4) + (rand() % 5);
    printf("Upload speed: %d Mbps.\n", uploadSpeed);

    if (downloadSpeed >= (speedInt / 2) && uploadSpeed >= (speedInt / 4)) {
        printf("Congratulations! Your internet speed is up to par with your expectations.\n");
    } else {
        printf("Unfortunately, your internet speed is not up to par with your expectations.\n");
    }

    return 0;
}