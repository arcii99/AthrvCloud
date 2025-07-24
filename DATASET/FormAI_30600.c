//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int download_speed = rand() % 101;
    int upload_speed = rand() % 101;
    int latency = rand() % 101;

    printf("===== NETWORK QUALITY OF SERVICE (QoS) MONITOR =====\n\n");

    printf("DOWNLOAD SPEED: %d Mbps\n", download_speed);
    printf("UPLOAD SPEED: %d Mbps\n", upload_speed);
    printf("LATENCY: %d ms\n\n", latency);

    if (download_speed >= 80 && upload_speed >= 80 && latency <= 20) {
        printf("CONNECTION: EXCELLENT\n");
    } else if (download_speed >= 60 && upload_speed >= 60 && latency <= 50) {
        printf("CONNECTION: GOOD\n");
    } else if (download_speed >= 40 && upload_speed >= 40 && latency <= 100) {
        printf("CONNECTION: FAIR\n");
    } else {
        printf("CONNECTION: POOR\n");
    }

    return 0;
}