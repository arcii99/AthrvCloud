//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <pcap.h>


#define PROMISCUOUS_MODE 1
#define BYTE 8

/* Ethernet header */
struct ethernet_header {
    u_char dst_mac[6];
    u_char src_mac[6];
    u_short type;
};

/* IP header */
struct ip_header {
    u_char version_ihl;
    u_char tos;
    u_short length;
    u_short id;
    u_short flags_offset;
    u_char ttl;
    u_char protocol;
    u_short checksum;
    struct in_addr src_ip_address;
    struct in_addr dst_ip_address;
};

/* TCP header */
struct tcp_header {
    u_short src_port;
    u_short dst_port;
    u_int sequence_number;
    u_int acknowledgment_number;
    u_char reserved:4;
    u_char data_offset:4;
    u_char flags;
    u_short window_size;
    u_short checksum;
    u_short urgent_pointer;
};

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main (int argc, char **argv) {
    char *device = NULL;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    struct bpf_program filter;
    char filter_string[] = "tcp";
    bpf_u_int32 subnet_mask = 0;
    bpf_u_int32 ip_address = 0;
    int timeout_limit = 10000;

    if (argc == 1) {
        device = pcap_lookupdev(error_buffer);
        if (device == NULL) {
            printf("No device found. %s\n", error_buffer);
            exit(1);
        }
    } else if (argc == 2) {
        device = argv[1];
    } else {
        printf("Too many arguments supplied.\n");
        exit(1);
    }

    if (pcap_lookupnet(device, &ip_address, &subnet_mask, error_buffer) < 0) {
        printf("Could not determine device subnet mask.\n%s", error_buffer);
        subnet_mask = 0;
        ip_address = 0;
    }

    handle = pcap_open_live(device, BUFSIZ, PROMISCUOUS_MODE, timeout_limit, error_buffer);
    if (handle == NULL) {
        printf("Could not open device %s.\n%s\n", device, error_buffer);
        exit(1);
    }

    if (pcap_compile(handle, &filter, filter_string, 0, subnet_mask) == -1) {
        printf("Could not compile filter string.\n%s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &filter) < 0) {
        printf("Could not set filter.\n");
        exit(1);
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_freecode(&filter);
    pcap_close(handle);

    exit(0);
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethernet_header *ether;
    struct ip_header *ip;
    struct tcp_header *tcp;
    const char *payload;
    int payload_length = 0;
    int i, size_ip, size_tcp;

    ether = (struct ethernet_header*)(packet);
    ip = (struct ip_header*)(packet + sizeof(struct ethernet_header));
    size_ip = ((ip->version_ihl) & 0x0F) * 4;
    if (size_ip < 20) return;
    tcp = (struct tcp_header*)(packet + sizeof(struct ethernet_header) + size_ip);
    size_tcp = ((tcp->data_offset) & 0x0F) * 4;
    if (size_tcp < 20) {
        printf("Invalid TCP header size: %d bytes.\n", size_tcp);
        return;
    }
    payload = (char*)(packet + sizeof(struct ethernet_header) + size_ip + size_tcp);
    payload_length = ntohs(ip->length) - (size_ip + size_tcp);

    printf("Ethernet Header\n");
    printf("\t|-Destination Address  : %.2X:%.2X:%.2X:%.2X:%.2X:%.2X \n", ether->dst_mac[0], ether->dst_mac[1], ether->dst_mac[2], ether->dst_mac[3], ether->dst_mac[4], ether->dst_mac[5] );
    printf("\t|-Source Address       : %.2X:%.2X:%.2X:%.2X:%.2X:%.2X \n", ether->src_mac[0], ether->src_mac[1], ether->src_mac[2], ether->src_mac[3], ether->src_mac[4], ether->src_mac[5] );
    printf("\t|-Protocol             : %u \n",(unsigned short) ether->type);

    printf("\nIP Header\n");
    printf("\t|-IP Version           : %d\n", (ip->version_ihl >> 4) & 0xF);
    printf("\t|-IP Header Length     : %d DWORDS or %d Bytes\n", (ip->version_ihl & 0xF) * 4, size_ip);
    printf("\t|-Type Of Service      : %d\n", ip->tos);
    printf("\t|-IP Total Length      : %d Bytes\n", ntohs(ip->length));
    printf("\t|-Identification       : %d\n", ntohs(ip->id));
    printf("\t|-IP Flags             : %d\n", ntohs(ip->flags_offset) & 0xE000);
    printf("\t|-Fragment Offset      : %d\n", ntohs(ip->flags_offset) & 0x1FFF);
    printf("\t|-Time To Live         : %d\n", ip->ttl);
    printf("\t|-Protocol             : %d\n", ip->protocol);
    printf("\t|-Header Checksum      : %d\n", ntohs(ip->checksum));
    printf("\t|-Source IP Address    : %s\n", inet_ntoa(ip->src_ip_address));
    printf("\t|-Destination IP Address : %s\n", inet_ntoa(ip->dst_ip_address));

    printf("\nTCP Header\n");
    printf("\t|-Source Port          : %d\n", ntohs(tcp->src_port));
    printf("\t|-Destination Port     : %d\n", ntohs(tcp->dst_port));
    printf("\t|-Sequence Number      : %lu\n", (unsigned long)ntohl(tcp->sequence_number));
    printf("\t|-Acknowledge Number   : %lu\n", (unsigned long)ntohl(tcp->acknowledgment_number));
    printf("\t|-Header Length        : %d DWORDS or %d bytes\n", (tcp->data_offset >> 4) & 0xF, size_tcp);
    printf("\t  |-Data Offset        : %d\n",(tcp->data_offset >> 4) & 0xF);
    printf("\t  |-Reserved           : %d\n",(tcp->reserved & 0xF));
    printf("\t  |-Flags              : %d\n",(tcp->flags & 0x7F));
    printf("\t  | |-Urgent           : %d\n",(tcp->flags & 0x20));
    printf("\t  | |-Acknowledge      : %d\n",(tcp->flags & 0x10));
    printf("\t  | |-Push             : %d\n",(tcp->flags & 0x08));
    printf("\t  | |-Reset            : %d\n",(tcp->flags & 0x04));
    printf("\t  | |-Synchronize      : %d\n",(tcp->flags & 0x02));
    printf("\t  | |-Finish           : %d\n",(tcp->flags & 0x01));
    printf("\t|-Window Size          : %d\n", ntohs(tcp->window_size));
    printf("\t|-Checksum             : %d\n", ntohs(tcp->checksum));
    printf("\t|-Urgent Pointer       : %d\n", tcp->urgent_pointer);

    printf("\nData Payload\n");
    for (i = 0; i < payload_length / BYTE; i++) {
        if (i % 8 == 0) printf("\n\t");
        printf(" %02X ", payload[i]);
    }
    printf("\n");

    printf("\n================================================\n\n");
}