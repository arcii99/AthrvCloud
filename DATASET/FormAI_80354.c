//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct packet {
    int packet_id;
    int packet_size;
    int priority;
};

int main() {
    srand(time(0)); // Seed for random number generator

    // Creating an array of packets
    struct packet packets[10];
    for (int i = 0; i < 10; i++) {
        packets[i].packet_id = i + 1;
        packets[i].packet_size = rand() % 1024 + 1; // Random packet size between 1 and 1024
        packets[i].priority = rand() % 4; // Priority level 0 to 3
    }

    // Checking QoS for packets
    int total_size = 0;
    int max_priority = -1;
    int total_priority_packets = 0;

    for (int i = 0; i < 10; i++) {
        total_size += packets[i].packet_size;

        if (packets[i].priority > max_priority) {
            max_priority = packets[i].priority;
        }

        if (packets[i].priority > 0) {
            total_priority_packets += 1;
        }
    }

    float avg_size = (float) total_size / 10;
    float priority_percentage = (float) total_priority_packets / 10 * 100;

    // Printing QoS statistics
    printf("QoS Statistics:\n");
    printf("Average Packet Size: %.2f bytes\n", avg_size);
    printf("Max Priority Level: %d\n", max_priority);
    printf("Percentage of Priority Packets: %.2f %%\n", priority_percentage);

    return 0;
}