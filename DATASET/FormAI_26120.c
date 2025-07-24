//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to the Happy Intrusion Detection System!\n");

    // Initialize variables for monitoring network traffic
    int packets_received = 0;
    int packets_sent = 0;
    int packets_dropped = 0;

    while (1) {
        // Simulate network traffic
        int incoming_packets = rand() % 10;
        int outgoing_packets = rand() % 10;

        // Update packet counts
        packets_received += incoming_packets;
        packets_sent += outgoing_packets;

        // Check for potential intrusion
        if (incoming_packets > outgoing_packets) {
            printf("ALERT: More incoming packets than outgoing packets detected!\n");
            printf("Possible intrusion detected!\n");
            printf("Dropping all incoming packets.\n");
            packets_dropped += incoming_packets;
        }

        // Print packet information
        printf("Packets received: %d\n", packets_received);
        printf("Packets sent: %d\n", packets_sent);
        printf("Packets dropped: %d\n", packets_dropped);

        // Pause for 1 second
        sleep(1);
    }

    return 0;
}