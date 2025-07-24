//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define PACKET_SIZE 1024

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Got a packet!\n");
    printf("Header length: %d\n", header->len);
    printf("Packet length: %d\n", header->caplen);
    printf("Packet data:");

    for(int i = 0; i < header->caplen; i++) {
        printf("%02x ", packet[i]);
    }

    printf("\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    if(pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        printf("Can't get network address for device eth0: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live("eth0", PACKET_SIZE, 1, 1000, errbuf);

    if(handle == NULL) {
        printf("Couldn't open device eth0: %s\n", errbuf);
        exit(1);
    }

    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }

    if(pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }

    printf("Listening on eth0...\n");
    pcap_loop(handle, -1, process_packet, NULL);
    pcap_close(handle);

    return 0;
}