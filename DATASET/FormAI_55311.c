//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: sophisticated
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define PROMISCUOUS 1

void handler(u_char *userdata, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data) {
    static int count = 1;

    struct in_addr src_addr, dst_addr;
    struct ether_header *eth;
    struct iphdr *ip;
    struct tcphdr *tcp;
    const u_char *data;
    int size_ip, size_tcp, size_data;

    printf("Packet %d:\n", count);

    eth = (struct ether_header *) pkt_data;
    printf("\tSource MAC: %s\n", ether_ntoa((const struct ether_addr *) eth->ether_shost));
    printf("\tDest MAC: %s\n", ether_ntoa((const struct ether_addr *) eth->ether_dhost));
    pkt_data += sizeof(struct ether_header);

    ip = (struct iphdr *) pkt_data;
    size_ip = ip->ihl * 4;
    printf("\tSource IP: %s\n", inet_ntoa(*(struct in_addr *) &ip->saddr));
    printf("\tDest IP: %s\n", inet_ntoa(*(struct in_addr *) &ip->daddr));
    pkt_data += size_ip;

    tcp = (struct tcphdr *) pkt_data;
    size_tcp = tcp->doff * 4;
    printf("\tSource Port: %d\n", ntohs(tcp->source));
    printf("\tDest Port: %d\n", ntohs(tcp->dest));
    pkt_data += size_tcp;

    size_data = pkt_header->len - (pkt_data - pkt_data);
    if (size_data > 0) {
        printf("\tData:\n");
        data = pkt_data;
        for (int i = 0; i < size_data; i++) {
            printf("%c", *(data++));
        }
        printf("\n");
    }

    count++;
}

int main() {
    char err_buf[PCAP_ERRBUF_SIZE];
    char *dev_name;
    pcap_t *handle;
    int max_bytes = 1024;
    int network_timeout = 1000;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    dev_name = pcap_lookupdev(err_buf);
    if (dev_name == NULL) {
        fprintf(stderr, "Error finding default device: %s\n", err_buf);
        exit(EXIT_FAILURE);
    }

    printf("Using device: %s\n", dev_name);

    if (pcap_lookupnet(dev_name, &net, &mask, err_buf) == -1) {
        fprintf(stderr, "Error looking up netmask: %s\n", err_buf);
        exit(EXIT_FAILURE);
    }

    handle = pcap_open_live(dev_name, max_bytes, PROMISCUOUS, network_timeout, err_buf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", err_buf);
        exit(EXIT_FAILURE);
    }

    if (pcap_compile(handle, &fp, "tcp", 0, net) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_loop(handle, -1, handler, NULL);

    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}