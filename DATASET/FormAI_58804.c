//FormAI DATASET v1.0 Category: Firewall ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <pcap.h>

#define SNAP_LEN 65535
#define SIZE_ETHERNET 14

typedef struct _tcp_packet {
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;
    unsigned char *payload;
    uint32_t payload_length;
} tcp_packet;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet_data) {
    tcp_packet *tcp_pkt;
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;
    unsigned char *payload;
    uint32_t payload_length;

    ip_header = (struct iphdr *)(packet_data + SIZE_ETHERNET);
    tcp_header = (struct tcphdr *)(packet_data + SIZE_ETHERNET + ip_header->ihl * 4);
    payload = (unsigned char *)(packet_data + SIZE_ETHERNET + ip_header->ihl * 4 + tcp_header->doff * 4);
    payload_length = ntohs(ip_header->tot_len) - (ip_header->ihl * 4) - (tcp_header->doff * 4);

    tcp_pkt = (tcp_packet *)malloc(sizeof(tcp_packet));
    tcp_pkt->ip_header = ip_header;
    tcp_pkt->tcp_header = tcp_header;
    tcp_pkt->payload = payload;
    tcp_pkt->payload_length = payload_length;

    // Insert firewall rules here
    // ...

    free(tcp_pkt);
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    char *dev = argv[1];

    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Error in pcap_lookupnet: %s\n", errbuf);
        exit(1);
    }

    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error in pcap_open_live: %s\n", errbuf);
        exit(1);
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        printf("Error: Device %s doesn't provide Ethernet headers - not supported\n", dev);
        exit(1);
    }

    if (pcap_compile(handle, &fp, "", 0, net) == -1) {
        printf("Error in pcap_compile: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error in pcap_setfilter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}