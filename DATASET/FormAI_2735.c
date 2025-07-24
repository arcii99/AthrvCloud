//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth = (struct ether_header *) packet;
    if (ntohs(eth->ether_type) == ETHERTYPE_IP) {
        struct iphdr *ip = (struct iphdr *)(packet + sizeof(struct ether_header));
        if (ip->protocol == IPPROTO_TCP) {
            struct tcphdr *tcp = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
            printf("TCP Packet: Source Port %d Destination Port: %d\n", ntohs(tcp->source), ntohs(tcp->dest));
        }
        else if (ip->protocol == IPPROTO_UDP) {
            struct udphdr *udp = (struct udphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
            printf("UDP Packet: Source Port %d Destination Port: %d\n", ntohs(udp->source), ntohs(udp->dest));
        }
        else {
            printf("Protocol other than TCP/UDP detected\n");
        }
    }
}

int main(int argc, char *argv[]) {
    char *device = argv[1];
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        printf("Error opening device: %s\n", error_buffer);
        return 1;
    }
    if (pcap_datalink(handle) != DLT_EN10MB) {
        printf("Device %s doesn't provide Ethernet headers - not supported\n", device);
        return 1;
    }
    struct bpf_program filter;
    char filter_expression[] = "ip";
    if (pcap_compile(handle, &filter, filter_expression, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error compiling filter\n");
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter\n");
        return 1;
    }
    pcap_loop(handle, -1, handle_packet, NULL);
    pcap_close(handle);
    return 0;
}