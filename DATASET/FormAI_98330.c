//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define BUFFER_SIZE 2048

void callback(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // Extract and print packet information
    printf("\nPacket received with length: %d", header->len);

    int i;
    for (i = 0; i < header->len; i++) {
        // Print each byte of the packet
        printf("%02X ", packet[i]);
    }
}

int main(int argc, char **argv)
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "udp port 53";  // Capture only DNS traffic
    bpf_u_int32 net, mask;

    // Get network and mask information for current device
    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error getting network mask: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    // Open the network device for packet capture
    handle = pcap_open_live("eth0", BUFFER_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(1);
    }

    // Compile and apply the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error applying filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Call the callback function indefinitely to capture packets
    pcap_loop(handle, -1, callback, NULL);

    // Close the network device
    pcap_close(handle);

    return 0;
}