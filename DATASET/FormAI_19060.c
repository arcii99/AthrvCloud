//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: brave
#include <stdio.h>
#include <pcap.h>

void print_packet_info(const u_char *packet_data, struct pcap_pkthdr packet_header) {
    printf("Packet capture length: %u\n", packet_header.caplen);
    printf("Packet total length: %u\n", packet_header.len);

    // Print out packet payload
    for (u_int i = 0; i < packet_header.caplen; i++) {
        printf("%.2x ", *(packet_data + i));
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("enp0s3", 65536, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }

    while (1) {
        struct pcap_pkthdr packet_header;
        const u_char *packet_data = pcap_next(handle, &packet_header);
        if (packet_data == NULL) {
            printf("No packet received.\n");
        } else {
            printf("Packet received at %ld.%ld.\n", packet_header.ts.tv_sec, packet_header.ts.tv_usec);
            print_packet_info(packet_data, packet_header);
        }
    }

    pcap_close(handle);
    return 0;
}