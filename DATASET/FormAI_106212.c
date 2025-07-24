//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Function to handle the packet */
void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Got a packet\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_create("eth0", errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Error creating pcap handle: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    if (pcap_set_snaplen(handle, BUFSIZ) != 0) {
        fprintf(stderr, "Error setting snaplen: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }

    if (pcap_set_promisc(handle, 1) != 0) {
        fprintf(stderr, "Error setting promiscuous mode: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }

    if (pcap_set_timeout(handle, 1000) != 0) {
        fprintf(stderr, "Error setting timeout: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }

    if (pcap_activate(handle) != 0) {
        fprintf(stderr, "Error activating pcap handle: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }

    printf("Listening for packets on eth0...\n");

    if (pcap_loop(handle, -1, got_packet, NULL) != 0) {
        fprintf(stderr, "Error in pcap_loop: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }

    pcap_close(handle);
    return 0;
}