//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: enthusiastic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h> 

void packet_callback(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    // Print timestamp and packet length
    printf("%ld:%ld (%ld)\n", header->ts.tv_sec, header->ts.tv_usec, header->len);

    // Parse packet data
    // ...

    // Print relevant packet details
    // ...
}

int main(int argc, char **argv)
{
    pcap_t *handle;              // Session handle
    char *dev;                   // The device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE];   // Error string
    struct bpf_program fp;          // The compiled filter expression
    bpf_u_int32 mask;           // Our netmask
    bpf_u_int32 net;            // Our IP address and subnet mask
    struct pcap_pkthdr header;      // The header that pcap gives us
    const u_char *packet;           // The actual packet

    // Define filter expression
    // ...

    // Find a suitable device to sniff on
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Get devices IP address and subnet mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Can't get netmask for device %s\n", dev);
        net = 0;
        mask = 0;
    }

    // Open capture device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile filter expression
    // ...

    // Set filter expression
    // ...

    // Loop through packets and call packet_callback for each one
    pcap_loop(handle, -1, packet_callback, NULL);

    // Close the session
    pcap_close(handle);

    return EXIT_SUCCESS;
}