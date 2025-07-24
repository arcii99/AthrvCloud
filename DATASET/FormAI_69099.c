//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PACKET_SIZE 1000
#define MAX_LATENCY 500

int main()
{
    int num_packets = 0;
    int total_latency = 0;
    int max_latency = 0;
    int min_latency = MAX_LATENCY;
    int latency;
    int i;

    // Seed RNG
    srand(time(NULL));

    // Generate 50 packets
    for (i = 0; i < 50; i++) {
        // Simulate a packet
        latency = rand() % MAX_LATENCY;
        num_packets++;
        total_latency += latency;

        // Update min/max latency
        if (latency < min_latency) {
            min_latency = latency;
        }
        if (latency > max_latency) {
            max_latency = latency;
        }

        // Print stats for this packet
        printf("Packet #%d: Latency=%dms\n", num_packets, latency);
        printf("Current Average Latency: %dms\n", total_latency / num_packets);
        printf("Current Min Latency: %dms\n", min_latency);
        printf("Current Max Latency: %dms\n", max_latency);

        // Pause for effect
        sleep(1);
    }

    printf("\n");
    printf("------ QoS Metrics ------\n");
    printf("Total Number of Packets: %d\n", num_packets);
    printf("Average Latency: %dms\n", total_latency / num_packets);
    printf("Minimum Latency: %dms\n", min_latency);
    printf("Maximum Latency: %dms\n", max_latency);

    return 0;
}