//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: brave
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured of length %d\n", header->len);
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 subnet_mask, ip;

    if(argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(pcap_lookupnet(argv[1], &ip, &subnet_mask, errbuf) == -1) {
        printf("Error while getting netmask - %s\n", errbuf);
        ip = 0;
        subnet_mask = 0;
    }

    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error while opening device %s - %s\n", argv[1], errbuf);
        exit(EXIT_FAILURE);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, ip) == -1) {
        printf("Error while compiling BPF filter - %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error while setting BPF filter - %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}