//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    printf("Welcome to the QoS Network Monitor!\n");

    // Set up some mock data for the network
    int downloadSpeed = 50;
    int uploadSpeed = 25;
    float latency = 25.0;
    int packetLoss = 2;

    // Now let's monitor the network for QoS
    while (1) {
        // Check download speed
        if (downloadSpeed < 50) {
            printf("Warning: Download speed is below 50 Mbps!\n");
        } else {
            printf("Download speed is good!\n");
        }

        // Check upload speed
        if (uploadSpeed < 25) {
            printf("Warning: Upload speed is below 25 Mbps!\n");
        } else {
            printf("Upload speed is good!\n");
        }

        // Check latency
        if (latency > 50.0) {
            printf("Warning: Latency is above 50 ms!\n");
        } else {
            printf("Latency is good!\n");
        }

        // Check packet loss
        if (packetLoss > 5) {
            printf("Warning: Packet loss is above 5 percent!\n");
        } else {
            printf("Packet loss is good!\n");
        }

        // Wait 5 seconds before checking again
        sleep(5);
    }

    return 0;
}