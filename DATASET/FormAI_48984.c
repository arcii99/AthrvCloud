//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define MAX_PACKET_SIZE 65535
#define ETHERNET_HEADER_SIZE 14

void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char **argv) {

    char *dev = NULL;                   // Device to sniff.
    char errbuf[PCAP_ERRBUF_SIZE];      // Error buffer to hold error messages.

    // Find a device to sniff. If no device is specified, use the default device.
    if (argc == 1) {
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            printf("Error finding default device: %s\n", errbuf);
            exit(1);
        }
    } else {
        dev = argv[1];
    }

    printf("Sniffing on device: %s\n", dev);

    pcap_t *handle = NULL;              // Handle to pcap session.
    struct bpf_program filter;          // The compiled filter expression.
    char filter_exp[] = "port 80";      // The filter expression.
    bpf_u_int32 mask = 0;               // The netmask of our sniffing device.
    bpf_u_int32 net = 0;                // The IP address of our sniffing device.

    // Open a pcap session on the specified device.
    handle = pcap_open_live(dev, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        exit(1);
    }

    // Compile and apply the filter expression.
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error applying filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start sniffing packets.
    pcap_loop(handle, -1, process_packet, NULL);

    // Close the pcap session.
    pcap_close(handle);

    return 0;
}

void process_packet(u_char *user_args, const struct pcap_pkthdr *packet_header, const u_char *packet) {

    static int packet_count = 1;                    // Count of packets processed so far.
    const u_char *packet_data = NULL;               // Pointer to the packet data.
    u_char *data = NULL;                            // Pointer to the payload data.

    printf("\nPacket %d:\n", packet_count);
    printf("\tTime: %s", ctime((const time_t *)&packet_header->ts.tv_sec));  // Time stamp of packet.

    packet_data = packet + ETHERNET_HEADER_SIZE;     // Skip the Ethernet header.
    printf("\tSource IP: %d.%d.%d.%d\n", packet_data[12], packet_data[13], packet_data[14], packet_data[15]);
    printf("\tDestination IP: %d.%d.%d.%d\n", packet_data[16], packet_data[17], packet_data[18], packet_data[19]);

    int data_len = packet_header->caplen - ETHERNET_HEADER_SIZE;    // Length of payload data.
    data = (u_char *)(packet + ETHERNET_HEADER_SIZE);              // Pointer to payload data.
    printf("\tPayload (%d bytes):\n", data_len);
    for (int i = 0; i < data_len; i++) {
        printf("%02x ", *(data + i));
        if ((i % 16) == 15 || (i == data_len - 1)) {
            for (int j = 0; j < 15 - (i % 16); j++) {
                printf("   ");
            }
            printf("\t");
            for (int j = (i - (i % 16)); j <= i; j++) {
                if (*(data + j) >= 32 && *(data + j) < 127) {
                    printf("%c", *(data + j));
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    }

    packet_count++;
}