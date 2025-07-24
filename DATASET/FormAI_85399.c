//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    int *counter = (int*)args;
    int size = header->len;

    // Show the packet's size
    printf("Packet number %d - size: %d bytes\n", ++(*counter), size);

    // Loop through each byte in the packet
    for (int i = 0; i < size; i++)
    {
        // Print each byte in hexadecimal format
        printf("%02x ", packet[i]);

        // If the byte is a printable character, print it
        if (packet[i] >= 32 && packet[i] < 127)
        {
            printf("%c", packet[i]);
        }
    }

    // Print two newlines for formatting
    printf("\n\n");
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Get the name of the network interface to monitor
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Failed to find default network device: %s\n", errbuf);
        return 1;
    }

    printf("Monitoring network device %s...\n", dev);

    // Open the network interface for monitoring
    handle = pcap_open_live(dev, 65535, 1, 0, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Failed to open device %s for monitoring: %s\n", dev, errbuf);
        return 1;
    }

    // Create a counter to keep track of the number of packets processed
    int counter = 0;

    // Continuously monitor the network interface for packets
    if (pcap_loop(handle, -1, process_packet, (u_char*)&counter) < 0)
    {
        fprintf(stderr, "Packet monitoring loop failed: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Close the handle when monitoring is complete
    pcap_close(handle);

    return 0;
}