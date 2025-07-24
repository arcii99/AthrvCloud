//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PACKETS 1000
#define THRESHOLD 0.5

int main() {
    int packet_count = 0;
    float packet_size[MAX_PACKETS];
    bool detected = false;

    // initialize packet_size with random values
    srand(0);
    for(int i = 0; i < MAX_PACKETS; i++) {
        packet_size[i] = ((float)rand()/(float)(RAND_MAX)) * 1000;
    }

    // calculate mean and standard deviation of packet sizes
    float mean = 0.0;
    for(int i = 0; i < MAX_PACKETS; i++) {
        mean += packet_size[i];
    }
    mean /= MAX_PACKETS;

    float std_deviation = 0.0;
    for(int i = 0; i < MAX_PACKETS; i++) {
        std_deviation += (packet_size[i] - mean) * (packet_size[i] - mean);
    }
    std_deviation /= MAX_PACKETS;
    std_deviation = sqrt(std_deviation);

    // detect intrusion based on standard deviation
    for(int i = 0; i < MAX_PACKETS; i++) {
        if(packet_size[i] > mean + (THRESHOLD * std_deviation)) {
            detected = true;
            printf("Possible intrusion detected. Packet %d size: %f\n", i+1, packet_size[i]);
        }
        packet_count++;
    }

    if(!detected) {
        printf("No intrusion detected.\n");
    }

    return 0;
}