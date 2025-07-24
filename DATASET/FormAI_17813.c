//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle; // packet capture handle
    
    // open the network device for packet capture
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Could not open device %s: %s\n", argv[1], errbuf);
        return 1;
    }
    
    // create a filter to capture only TCP traffic
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error compiling filter\n");
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting filter\n");
        return 1;
    }
    
    // loop through each packet and print out payload, source and destination IP addresses
    struct pcap_pkthdr header;
    const u_char *packet;
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) continue;
        printf("Packet length: %d\n", header.len);
        printf("Source IP address: %d.%d.%d.%d\n", packet[26], packet[27], packet[28], packet[29]);
        printf("Destination IP address: %d.%d.%d.%d\n", packet[30], packet[31], packet[32], packet[33]);
        printf("Payload: ");
        for (int i=54; i<header.len; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n\n");
    }
    
    // close the packet capture handle
    pcap_close(handle);
    
    return 0;
}