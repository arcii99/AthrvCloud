//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE]; // Define error buffer
    pcap_t *handle; // Define pcap handle
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf); // Opening network interface for capturing

    if (handle == NULL)
    {
        fprintf(stderr, "Error: %s", errbuf);
        return 1;
    }

    struct pcap_pkthdr header; // The header that pcap gives us
    const u_char *packet; // The actual packet

    packet = pcap_next(handle, &header); // Capture a packet

    // Print its length
    printf("Jacked a packet with length of [%d]\n", header.len);

    // Dump packet in hex format
    for (int i=0; i<header.len; i++)
    {
        printf("%02x ", packet[i]);
        if ((i+1) % 16 == 0)
            printf("\n");
    }

    pcap_close(handle); // Close the handle

    return 0;
}