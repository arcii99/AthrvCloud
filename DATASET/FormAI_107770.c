//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <pcap.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define SNAP_LEN 1518
#define SIZE_ETHERNET 14

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {

    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask, net;

    // Get default network interface if not provided
    if (argc == 1) {
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
            exit(EXIT_FAILURE);
        }
    } else {
        dev = argv[1];
    }

    // Get network address and subnet mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile filter
    if (pcap_compile(handle, &fp, "tcp", 0, net) == -1) {
        fprintf(stderr, "Couldn't compile filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't set filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_loop(handle, -1, handle_packet, NULL);

    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    const struct ether_header *ethernet;
    const struct iphdr *ip;
    const struct tcphdr *tcp;
    const char *payload;

    u_int size_ip;
    u_int size_tcp;
    u_int size_payload;

    ethernet = (struct ether_header *)(packet);
    if (ntohs(ethernet->ether_type) != ETHERTYPE_IP) {
        return;
    }

    ip = (struct iphdr *)(packet + SIZE_ETHERNET);
    size_ip = ip->ihl * 4;
    if (size_ip < 20) {
        printf("Invalid IP header length: %u bytes\n", size_ip);
        return;
    }

    if (ip->protocol != IPPROTO_TCP) {
        return;
    }

    tcp = (struct tcphdr *)(packet + SIZE_ETHERNET + size_ip);
    size_tcp = tcp->doff * 4;
    if (size_tcp < 20) {
        printf("Invalid TCP header length: %u bytes\n", size_tcp);
        return;
    }

    payload = (u_char *)(packet + SIZE_ETHERNET + size_ip + size_tcp);
    size_payload = ntohs(ip->tot_len) - (size_ip + size_tcp);

    printf("%s:%d -> %s:%d\n", inet_ntoa(*(struct in_addr *)&ip->saddr), ntohs(tcp->source),
           inet_ntoa(*(struct in_addr *)&ip->daddr), ntohs(tcp->dest));
    printf("Payload (%d bytes):\n", size_payload);
    print_payload(payload, size_payload);

    return;
}

void print_payload(const char *payload, int len) {

    int i;
    const u_char *ch = (const u_char *)payload;

    for (i = 0; i < len; i++) {
        printf("%02x ", *ch);
        ch++;
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }

    if (i % 16 != 0) {
        printf("\n");
    }
}