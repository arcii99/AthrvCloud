//FormAI DATASET v1.0 Category: Firewall ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <errno.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define ETH_ADDR_LEN 6

typedef struct eth_hdr eth_hdr_t;

struct eth_hdr {
    unsigned char eth_dest_addr[ETH_ADDR_LEN];
    unsigned char eth_src_addr[ETH_ADDR_LEN];
    unsigned short eth_type;
};

typedef struct ip_hdr ip_hdr_t;

struct ip_hdr {
    unsigned char ip_hl:4;
    unsigned char ip_v:4;
    unsigned char ip_tos;
    unsigned short ip_len;
    unsigned short ip_id;
    unsigned short ip_offset;
    unsigned char ip_ttl;
    unsigned char ip_protocol;
    unsigned short ip_chksum;
    struct in_addr ip_src;
    struct in_addr ip_dst;
};

typedef struct tcp_hdr tcp_hdr_t;

struct tcp_hdr {
    unsigned short tcp_src_port;
    unsigned short tcp_dest_port;
    unsigned int tcp_seq_no;
    unsigned int tcp_ack_no;
    unsigned char tcp_data_off;
    unsigned char tcp_flags;
    unsigned short tcp_window_size;
    unsigned short tcp_chksum;
    unsigned short tcp_urg_ptr;
};

void usage(char *prog_name);
void parse_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void print_eth_addr(const unsigned char *addr);
void print_packet(const u_char *packet, int len);

int main(int argc, char **argv) {
    if (argc != 3) {
        usage(argv[0]);
        return -1;
    }

    bpf_u_int32 net;
    bpf_u_int32 mask;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;

    dev = argv[1];
    char *filter = argv[2];

    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Could not get netmask for device '%s': %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Could not open device '%s': %s\n", dev, errbuf);
        return -1;
    }

    if (pcap_compile(handle, &fp, filter, 0, net) == -1) {
        fprintf(stderr, "Could not compile filter '%s': %s\n", filter, pcap_geterr(handle));
        return -1;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not set filter '%s': %s\n", filter, pcap_geterr(handle));
        return -1;
    }

    pcap_loop(handle, -1, parse_packet, NULL);

    pcap_close(handle);

    return 0;
}

void usage(char *prog_name) {
    printf("Usage: %s <interface> <filter>\n\n", prog_name);
    printf("  <interface>: Network interface to listen on\n");
    printf("  <filter>:    BPF filter expression\n");
}

void parse_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured\n");

    eth_hdr_t *eth_hdr = (eth_hdr_t *) packet;

    printf("Source MAC Address: ");
    print_eth_addr(eth_hdr->eth_src_addr);
    printf("\n");

    printf("Destination MAC Address: ");
    print_eth_addr(eth_hdr->eth_dest_addr);
    printf("\n");

    if (ntohs(eth_hdr->eth_type) != ETHERTYPE_IP) {
        printf("Not an IP packet\n\n");
        return;
    }

    ip_hdr_t *ip_hdr = (ip_hdr_t *) (packet + sizeof(eth_hdr_t));

    printf("Source IP Address: %s\n", inet_ntoa(ip_hdr->ip_src));
    printf("Destination IP Address: %s\n", inet_ntoa(ip_hdr->ip_dst));

    if (ip_hdr->ip_protocol != IPPROTO_TCP) {
        printf("Not a TCP packet\n\n");
        return;
    }

    tcp_hdr_t *tcp_hdr = (tcp_hdr_t *) (packet + sizeof(eth_hdr_t) + (ip_hdr->ip_hl * 4));

    printf("Source Port: %d\n", ntohs(tcp_hdr->tcp_src_port));
    printf("Destination Port: %d\n", ntohs(tcp_hdr->tcp_dest_port));

    printf("Packet payload:\n");
    print_packet(packet, header->len);

    printf("\n");
}

void print_eth_addr(const unsigned char *addr) {
    printf("%02X:%02X:%02X:%02X:%02X:%02X",
           addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);
}

void print_packet(const u_char *packet, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%02X ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    if (i % 16 != 0) {
        printf("\n");
    }
}