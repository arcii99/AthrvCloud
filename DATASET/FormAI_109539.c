//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: futuristic
#include <stdio.h>
#include <pcap.h>

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    printf("Listening on interface: eth0\n");

    struct pcap_pkthdr packet_header;
    const u_char *packet;

    while (1) {
        packet = pcap_next(handle, &packet_header);

        if (packet != NULL) {
            printf("Packet capture length: %d\n", packet_header.caplen);
            printf("Packet total length: %d\n", packet_header.len);
            printf("Packet payload: ");

            for (int i = 0; i < packet_header.caplen; ++i) {
                printf("%02x ", packet[i]);
            }

            printf("\n");
        }
    }

    pcap_close(handle);

    return 0;
}