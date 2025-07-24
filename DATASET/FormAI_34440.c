//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet);

int main(int argc, char const *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;

    // Open the network device for packet capture
    handle = pcap_open_live("eth0", BUFSIZ, 0, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(1);
    }

    // Set a filter for capturing specific packet types
    struct bpf_program fp;
    pcap_compile(handle, &fp, "tcp", 0, 0);
    pcap_setfilter(handle, &fp);

    // Start capturing packets
    printf("Starting capture...\n");
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup and exit program
    pcap_close(handle);
    printf("Capture complete.\n");
    return 0;
}

void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    printf("Packet captured. Length: %d\n", header->len);
    // Process packet data here...
}