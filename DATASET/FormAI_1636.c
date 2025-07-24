//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

// function to handle incoming packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    // print size of packet
    printf("Packet captured with size of: %d\n", header->len);

    // print packet content
    for (int i = 0; i < header->caplen; i++) {
        printf("%.2x ", *(packet + i));
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n\n");
}

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: %s interface_name\n", argv[0]);
        exit(0);
    }

    // error buffer
    char errbuf[PCAP_ERRBUF_SIZE];

    // open interface for capturing packets
    pcap_t *handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open interface %s: %s\n", argv[1], errbuf);
        exit(1);
    }

    // start capturing packets
    printf("Capturing packets on %s...\n", argv[1]);
    printf("\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    // close the handle
    pcap_close(handle);
    return 0;
}