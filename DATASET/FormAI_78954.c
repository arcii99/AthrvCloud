//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* pcap_handle;
    int retval;

    // Open libpcap capture handle
    pcap_handle = pcap_open_live(argv[1], 65535, 1, 0, errbuf);
    if (pcap_handle == NULL) {
        printf("Couldn't open device %s: %s\n", argv[1], errbuf);
        exit(1);
    }

    while (1) {
        struct pcap_pkthdr* header;     // Header of captured packet
        const u_char* packet_data;      // Packet data pointer
        int result;

        // Get the next available packet
        result = pcap_next_ex(pcap_handle, &header, &packet_data);

        if (result == 1) {
            // Print out packet data
            printf("Packet captured! Length=%d\n", header->len);
            printf("Data:\n");
            for (int i = 0; i < header->len; i++) {
                printf("%02x ", packet_data[i]);
            }
            printf("\n\n");
        }
        else if (result == -1) {
            // An error occurred
            printf("Error capturing packet: %s\n", pcap_geterr(pcap_handle));
            break;
        }
        else {
            // No more packets in capture file
            break;
        }
    }

    // Close the libpcap capture handle and exit
    pcap_close(pcap_handle);
    return 0;
}