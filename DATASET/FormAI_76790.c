//FormAI DATASET v1.0 Category: Firewall ; Style: mathematical
#include <stdio.h>

// Define variables
unsigned int packets_received = 0;
unsigned int packets_dropped = 0;
unsigned int packets_allowed = 0;

// Define the Firewall Rule
int is_packet_allowed(unsigned int src_ip, unsigned int dest_ip, unsigned int src_port, unsigned int dest_port)
{
    if (src_ip == 0x11111111 && dest_ip == 0x22222222 && src_port == 80 && dest_port == 8080)
    {
        // Packet allowed, increment packet counter
        packets_allowed++;
        return 1;
    }
    else
    {
        // Packet dropped, increment packet counter
        packets_dropped++;
        return 0;
    }
}

int main()
{
    // Initialize variables
    unsigned int src_ip = 0x11111111;
    unsigned int dest_ip = 0x22222222;
    unsigned int src_port = 80;
    unsigned int dest_port = 8080;

    // Call the Firewall rule
    if (is_packet_allowed(src_ip, dest_ip, src_port, dest_port))
    {
        printf("Packet allowed\n");
    }
    else
    {
        printf("Packet dropped\n");
    }

    // Print the statistics
    printf("Packets received: %u\n", packets_received);
    printf("Packets allowed: %u\n", packets_allowed);
    printf("Packets dropped: %u\n", packets_dropped);

    return 0;
}