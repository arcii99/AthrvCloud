//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: future-proof
#include <stdio.h>
#include <pcap.h>

#define MAX_PACKET_LEN 65536

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData) {
    printf("Packet capture length: %d\n", pkthdr->caplen);
    printf("Packet total length %d\n", pkthdr->len);
    printf("Packet Data:\n");

    for (int i = 0; i < pkthdr->caplen; i++) {
        printf("%02x ", packetData[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }

    printf("\n\n");
}

int main(int argc, char* argv[]) {
    char* device = NULL; // Capture device name
    char errorBuffer[PCAP_ERRBUF_SIZE]; // Error buffer
    pcap_t* captureHandle; // Packet capture handle

    // Check for capture device argument
    if (argc < 2) {
        printf("Usage: %s <capture-device>\n", argv[0]);
        return 1;
    }
    
    // Open the capture device
    device = argv[1];
    captureHandle = pcap_open_live(device, MAX_PACKET_LEN, 1, 1000, errorBuffer);
    if (!captureHandle) {
        printf("Error opening capture device %s: %s\n", device, errorBuffer);
        return 1;
    }

    // Set the packet filter (optional)
    struct bpf_program filter;
    char filterExp[] = "port 80";
    if (pcap_compile(captureHandle, &filter, filterExp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error compiling packet filter: %s\n", pcap_geterr(captureHandle));
        pcap_close(captureHandle);
        return 1;
    }
    if (pcap_setfilter(captureHandle, &filter) == -1) {
        printf("Error setting packet filter: %s\n", pcap_geterr(captureHandle));
        pcap_freecode(&filter);
        pcap_close(captureHandle);
        return 1;
    }
    pcap_freecode(&filter);

    // Begin packet capture loop
    pcap_loop(captureHandle, -1, packetHandler, NULL);

    // Cleanup and exit
    pcap_close(captureHandle);
    return 0;
}