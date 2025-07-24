//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>

// Define maximum packet size
#define MAX_PACKET_SIZE 65536

// Define network interface
#define INTERFACE "eth0"

// Function to print packet data
void print_packet_data(const u_char *packet, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%.2x ", packet[i]);
        if ((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    char error_buffer[PCAP_ERRBUF_SIZE]; // Error Buffer for initialization
    pcap_t *handle;                      // Packet Capture handle

    // Open network interface for packet capture
    handle = pcap_open_live(INTERFACE, MAX_PACKET_SIZE, 1, 1000, error_buffer);
    if (handle == NULL)
    {
        fprintf(stderr, "Error: %s\n", error_buffer);
        exit(1);
    }

    // Loop through network packets and capture them
    pcap_loop(handle, -1, print_packet_data, NULL);

    // Close handle to free up resources
    pcap_close(handle);
    return 0;
}