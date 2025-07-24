//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int milliseconds = seconds * 1000;
    clock_t start_time = clock();
    while(clock() < start_time + milliseconds) {}
}

int main() {
    int download_speed = 0;
    int upload_speed = 0;
    int latency = 0;
    int max_latency = 100;
    int min_latency = 10;

    printf("Testing download speed...\n");
    delay(5);
    download_speed = rand() % 1000;
    printf("Download speed: %d Mbps\n", download_speed);

    printf("Testing upload speed...\n");
    delay(5);
    upload_speed = rand() % 100;
    printf("Upload speed: %d Mbps\n", upload_speed);

    printf("Testing latency...\n");
    delay(1);
    latency = rand() % (max_latency - min_latency + 1) + min_latency;
    printf("Latency: %d ms\n", latency);

    return 0;
}