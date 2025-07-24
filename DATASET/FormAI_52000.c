//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int download_speed = 0;
    int upload_speed = 0;
    int latency = 0;

    printf("Starting internet speed test...\n");

    srand(time(0));

    download_speed = rand() % 100 + 1;
    upload_speed = rand() % 100 + 1;
    latency = rand() % 50 + 1;

    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
    printf("Latency: %d ms\n", latency);

    if(download_speed < 10 || upload_speed < 10 || latency > 50) {
        printf("Your internet connection is slow.\n");
    } else if(download_speed < 50 || upload_speed < 50 || latency > 20) {
        printf("Your internet connection is average.\n");
    } else {
        printf("Your internet connection is fast.\n");
    }

    return 0;
}