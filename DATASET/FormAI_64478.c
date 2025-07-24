//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to handle packet capture
void capture_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int count = 1;

    printf("Packet number %d:\n", count);
    printf("Packet size: %d bytes\n\n", header->len);

    // Print the packet's hex dump
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);

        // Print 16 bytes per line
        if (!((i + 1) % 16)) printf("\n");
    }

    printf("\n\n");

    count++;
}

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    char *device = NULL;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Find the device that matches the specified IP address
    char *ip_address = "192.168.0.101";
    char filter_exp[100];
    sprintf(filter_exp, "host %s", ip_address);

    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", device, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the capture device
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
        return 2;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    // Capture the packets
    if (pcap_loop(handle, 10, capture_packet, NULL) == -1) {
        fprintf(stderr, "Error while capturing packets: %s\n", pcap_geterr(handle));
        return 2;
    }

    // Clean up
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}