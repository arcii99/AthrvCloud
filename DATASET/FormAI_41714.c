//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds) {}
}

int main() {
    char buffer[1024];
    int upload_speed, download_speed, latency;

    printf("Welcome to Retro Speedtest!\n");
    printf("Press any key to begin...\n");
    fgets(buffer, sizeof(buffer), stdin);

    printf("Testing download speed...\n");
    delay(3000);
    download_speed = rand() % 90 + 10;
    printf("Your download speed is: %d Mbps\n", download_speed);

    printf("Testing upload speed...\n");
    delay(3000);
    upload_speed = rand() % 90 + 10;
    printf("Your upload speed is: %d Mbps\n", upload_speed);

    printf("Testing latency...\n");
    delay(2000);
    latency = rand() % 50 + 10;
    printf("Your latency is: %d ms\n", latency);

    if (download_speed < 20 || upload_speed < 10 || latency > 30) {
        printf("Your internet connection is slow... Please consider upgrading.\n");
    } else {
        printf("Your internet connection appears to be working well!\n");
    }

    printf("Thanks for using Retro Speedtest!\n");
    return 0;
}