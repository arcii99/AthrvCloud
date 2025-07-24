//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv) {

    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    bpf_u_int32 subnet_mask, ip;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <Interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(pcap_lookupnet(argv[1], &ip, &subnet_mask, error_buffer) == -1) {
        fprintf(stderr, "Could not get information for interface %s: %s\n", argv[1], pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, error_buffer);
    if(handle == NULL) {
        fprintf(stderr, "Could not open interface %s: %s\n", argv[1], error_buffer);
        exit(EXIT_FAILURE);
    }

    if(pcap_compile(handle, &filter, filter_exp, 0, subnet_mask) == -1) {
        fprintf(stderr, "Unable to compile filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if(pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Unable to set filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    return 0;
}


void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {

    static int count = 0;
    printf("\nPacket number %d:\n", ++count);
    printf("Packet size: %d bytes\n", header->len);

    for(int i=0; i<header->len; i++) {
        printf("%02x", *(pkt_data + i));
        if((i+1) % 16 == 0)
            printf("\n");
    }

    printf("\n\n");
}