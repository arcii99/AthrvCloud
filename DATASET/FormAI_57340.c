//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packetData)
{
    printf("Packet size: %d bytes\n", pkthdr->len);
    // Process packet data here
}

int main(int argc, char *argv[])
{
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    int timeout = 1000; // Timeout value in milliseconds

    // Get network interface device
    device = pcap_lookupdev(errbuf);
    if (device == NULL)
    {
        fprintf(stderr, "Error finding network interface: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    printf("Using network interface: %s\n", device);

    // Open network interface for packet capture
    handle = pcap_open_live(device, MAX_PACKET_SIZE, 1, timeout, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Error opening network interface: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Compile and apply packet filter
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1)
    {
        fprintf(stderr, "Error compiling packet filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &filter) == -1)
    {
        fprintf(stderr, "Error applying packet filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Capture packets
    printf("Listening for TCP packets...\n");
    pcap_loop(handle, -1, packetHandler, NULL);

    // Cleanup
    pcap_freecode(&filter);
    pcap_close(handle);

    return EXIT_SUCCESS;
}