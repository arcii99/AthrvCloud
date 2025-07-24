//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int download_speed, upload_speed, latency;
    srand(time(NULL));      // Initiate random seed

    // Simulate internet speed test
    download_speed = rand() % 100 + 1;    // Random download speed between 1-100 Mbps
    upload_speed = rand() % 20 + 1;     // Random upload speed between 1-20 Mbps
    latency = rand() % 50 + 1;         // Random latency between 1-50 milliseconds
    
    // Display result to user
    printf("Testing internet speed...\n");
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
    printf("Latency: %d ms\n", latency);

    return 0;
}