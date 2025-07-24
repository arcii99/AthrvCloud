//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: random
#include <stdio.h>
#include <pcap.h>

void print_packet_info(const u_char* packet, struct pcap_pkthdr packet_header) {
    printf("Packet length:\t\t%d\n", packet_header.len);
    printf("Packet data (in hex):\n");

    for (int i = 0; i < packet_header.len; i++) {
        printf("%02x", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        } else if ((i + 1) % 8 == 0) {
            printf("  ");
        } else {
            printf(" ");
        }
    }

    printf("\n");
}

void process_packet(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    printf("Received a packet:\n");
    print_packet_info(packet, *header);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live("lo", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Could not open device - %s\n", errbuf);
        return 1;
    }

    printf("Started monitoring packet traffic...\n");
    pcap_loop(handle, -1, process_packet, NULL);
    pcap_close(handle);

    return 0;
}