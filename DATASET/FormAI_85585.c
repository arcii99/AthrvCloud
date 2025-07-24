//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int download = 0;
    int upload = 0;
    int latency = 0;
    srand(time(NULL));

    // Simulate download speed test
    printf("Testing download speed...\n");
    for (int i = 0; i < 10; i++) {
        int speed = rand() % 100 + 1; // Generate random speed between 1 and 100 Mbps
        printf("Downloading at %d Mbps\n", speed);
        download += speed;
    }
    download /= 10;
    printf("Download speed: %d Mbps\n", download);

    // Simulate upload speed test
    printf("Testing upload speed...\n");
    for (int i = 0; i < 10; i++) {
        int speed = rand() % 100 + 1; // Generate random speed between 1 and 100 Mbps
        printf("Uploading at %d Mbps\n", speed);
        upload += speed;
    }
    upload /= 10;
    printf("Upload speed: %d Mbps\n", upload);

    // Simulate latency test
    printf("Testing latency...\n");
    for (int i = 0; i < 10; i++) {
        int time = rand() % 10 + 1; // Generate random time between 1 and 10 ms
        printf("Ping: %d ms\n", time);
        latency += time;
    }
    latency /= 10;
    printf("Latency: %d ms\n", latency);

    return 0;
}