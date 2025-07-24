//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packetData);

int main(int argc, char **argv) {
    char *device = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    bpf_u_int32 subnetMask, ipAddress;

    // Find a capture device
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "No capture device found: %s\n", errbuf);
        return 1;
    }
    printf("Capture device: %s\n", device);

    // Open the device for capturing
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Cannot open device %s: %s\n", device, errbuf);
        return 1;
    }

    // Get IP address and subnet mask of device
    if (pcap_lookupnet(device, &ipAddress, &subnetMask, errbuf) == -1) {
        fprintf(stderr, "Error getting IP address and subnet mask of device %s: %s\n", device, errbuf);
        return 1;
    }

    // Compile filter expression
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "tcp and dst port 80", 1, subnetMask) == -1) {
        fprintf(stderr, "Cannot compile filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Apply filter
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Cannot set filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, -1, packetHandler, NULL);

    // Close the handle and free memory
    pcap_close(handle);
    pcap_freecode(&filter);

    return 0;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packetData) {
    printf("Packet captured at %s\n", ctime((const time_t *)&pkthdr->ts.tv_sec));
    printf("Packet length: %d\n", pkthdr->len);
    printf("Payload: ");
    for (int i = 0; i < pkthdr->len; i++) {
        printf("%02X ", packetData[i]);
    }
    printf("\n");
}