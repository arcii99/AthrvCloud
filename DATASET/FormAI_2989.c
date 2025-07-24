//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Cryptic
//Sniff your Packets like a Spy
//with Cryptic Capturer using PCAP Library

#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>

void get_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    static int count = 1;

    printf("\nPacket number %d:\n", count);
    printf("    Length: %d bytes\n", header->len);
    printf("    Data:\n");

    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }

    printf("\n");

    count++;
}

int main() {

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Cannot get netmask for device eth0\n");
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Cannot open device eth0: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Cannot compile filter expression: %s\n", filter_exp);
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Cannot set filter expression: %s\n", filter_exp);
        return EXIT_FAILURE;
    }

    pcap_loop(handle, -1, get_packet, NULL);
    pcap_close(handle);

    return EXIT_SUCCESS;
}