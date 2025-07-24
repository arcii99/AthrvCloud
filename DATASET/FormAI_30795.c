//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: multiplayer
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>

#define MAX_PACKET_SIZE 65535

int main(int argc, char *argv[]) {
    char *interface;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr packet_header;
    const u_char *packet_data;

    if (argc != 2) {
        printf("Please provide a network interface name as an argument.\n");
        return 1;
    }

    interface = argv[1];
    handle = pcap_open_live(interface, MAX_PACKET_SIZE, 1, 0, error_buffer);
    if (handle == NULL) {
        printf("Error opening interface %s: %s\n", interface, error_buffer);
        return 1;
    }
    
    while (1) {
        packet_data = pcap_next(handle, &packet_header);
        if (packet_data != NULL) {
            printf("Packet captured.\n");
            // Insert code here to handle the packet data.
        }
    }
    
    return 0;
}