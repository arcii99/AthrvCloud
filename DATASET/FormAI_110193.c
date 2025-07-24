//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define ETH_HEADER_LEN 14
#define IPV4_HEADER_LEN 20

void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet);

int main(int argc, char *argv[]) {
    char *device;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    bpf_u_int32 subnet_mask, ip;
    char *filter_exp = "ip";
    int timeout_limit = 10000;

    if (argc == 2) {
        device = argv[1];
    }
    else {
        device = pcap_lookupdev(error_buffer);
        if (device == NULL) {
            fprintf(stderr, "Couldn't find default device: %s\n", error_buffer);
            return 1;
        }
    }

    if (pcap_lookupnet(device, &ip, &subnet_mask, error_buffer) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", device, error_buffer);
        return 1;
    }

    handle = pcap_open_live(device, BUFSIZ, 1, timeout_limit, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, error_buffer);
        return 1;
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, ip) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    pcap_loop(handle, -1, packet_handler, NULL);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    struct ethhdr *ethernet_header;
    struct iphdr *ip_header;
    int size_ip;
    const char *payload;

    ethernet_header = (struct ethhdr *) packet;
    printf("Source MAC: %s\n", ether_ntoa((struct ether_addr *) ethernet_header->h_source));
    printf("Destination MAC: %s\n", ether_ntoa((struct ether_addr *) ethernet_header->h_dest));

    ip_header = (struct iphdr *) (packet + ETH_HEADER_LEN);
    if (ip_header->version == 4 && ip_header->ihl == 5) {
        size_ip = IPV4_HEADER_LEN;
        printf("Source Address: %s\n", inet_ntoa(*(struct in_addr *) &ip_header->saddr));
        printf("Destination Address: %s\n", inet_ntoa(*(struct in_addr *) &ip_header->daddr));

        payload = (char *) (packet + ETH_HEADER_LEN + size_ip);
        if (ip_header->protocol == IPPROTO_TCP) {
            struct tcphdr *tcp_header;
            tcp_header = (struct tcphdr *) (payload);
            printf("Source Port: %d\n", ntohs(tcp_header->source));
            printf("Destination Port: %d\n", ntohs(tcp_header->dest));
        }
        else if (ip_header->protocol == IPPROTO_UDP) {
            struct udphdr *udp_header;
            udp_header = (struct udphdr *) (payload);
            printf("Source Port: %d\n", ntohs(udp_header->source));
            printf("Destination Port: %d\n", ntohs(udp_header->dest));
        }
    }
    printf("-----------------------\n");
}