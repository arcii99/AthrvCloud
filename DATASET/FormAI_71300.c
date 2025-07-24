//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(NULL));
    int download_speed = rand() % 101 + 1; // generates random download speed between 1 and 100
    int upload_speed = rand() % 101 + 1; // generates random upload speed between 1 and 100
    int latency = rand() % 101 + 1; // generates random latency between 1 and 100

    printf("Welcome to the Happy Internet Speed Test Application!\n\n");
    sleep(1); // adds delay for dramatic effect
    printf("Initiating test...\n");
    sleep(2); // adds delay for dramatic effect
    printf("Download speed: %d Mbps\n", download_speed);
    sleep(1); // adds delay for dramatic effect
    printf("Upload speed: %d Mbps\n", upload_speed);
    sleep(1); // adds delay for dramatic effect
    printf("Latency: %d ms\n", latency);
    sleep(1); // adds delay for dramatic effect

    if (download_speed > 50 && upload_speed > 50 && latency < 50) {
        printf("\nCongratulations! You have a Happy Internet connection!\n");
    } else {
        printf("\nSorry, but your Internet connection is not Happy.\n");
        if (download_speed <= 50) {
            printf("You should consider upgrading your download speed.\n");
        }
        if (upload_speed <= 50) {
            printf("You should consider upgrading your upload speed.\n");
        }
        if (latency >= 50) {
            printf("You should consider improving your network latency.\n");
        }
    }

    return 0;
}