//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

// Define the callback function for pcap_loop
void capturePacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[])
{
    char *device;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int numPackets = 10; // number of packets to capture
    int timeoutms = 1000; // number of milliseconds to wait for packets

    // Get the name of the first available network device
    device = pcap_lookupdev(errorBuffer);
    if (device == NULL) {
        printf("Error finding network device: %s", errorBuffer);
        exit(1);
    }

    // Open the network device for packet capture
    handle = pcap_open_live(device, BUFSIZ, 1, timeoutms, errorBuffer);
    if (handle == NULL) {
        printf("Error opening network device: %s", errorBuffer);
        exit(1);
    }

    // Compile and apply packet filter to handle
    struct bpf_program filter;
    char filterExpression[] = "ip";
    if (pcap_compile(handle, &filter, filterExpression, 0, 0) == -1) {
        printf("Error compiling filter: %s", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s", pcap_geterr(handle));
        exit(1);
    }

    // Start packet capture
    pcap_loop(handle, numPackets, capturePacket, NULL);

    // Close the packet capture handle
    pcap_close(handle);

    return 0;
}

// Define the callback function for pcap_loop
void capturePacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int packetCount = 1;

    printf("Packet %d:\n", packetCount);
    printf("Length: %d bytes\n", header->len);

    // Print the raw packet data as hexadecimal bytes
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n\n");

    packetCount++;
}