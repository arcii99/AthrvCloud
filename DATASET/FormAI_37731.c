//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define ETHER_ADDR_LEN 6
#define ETHER_TYPE_LEN 2
#define ETHER_HDR_LEN 14

#define IP_ADDR_LEN 4
#define IP_HDR_LEN 20

#define TCP_HDR_LEN 20

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;

typedef struct eth_hdr {
    u_char  ether_dhost[ETHER_ADDR_LEN];
    u_char  ether_shost[ETHER_ADDR_LEN];
    u_short ether_type;
} eth_hdr;

typedef struct ip_hdr{
    u_char  ip_version_and_header_length;
    u_char  ip_tos;
    u_short ip_total_length;
    u_short ip_id;
    u_short ip_flags_and_offset;
    u_char  ip_ttl;
    u_char  ip_protocol;
    u_short ip_checksum;
    u_char  ip_src_addr[IP_ADDR_LEN];
    u_char  ip_dest_addr[IP_ADDR_LEN];
}ip_hdr;

typedef struct tcp_hdr{
    u_short src_port;
    u_short dst_port;
    u_int   sequence;
    u_int   acknowledgement;
    u_char  data_offset_and_reserved;
    u_char  flags;
    u_short window_size;
    u_short checksum;
    u_short urgent_pointer;
}tcp_hdr;

void print_ethernet_header(const u_char *Buffer, int Size)
{
    eth_hdr *ethernet_header = (eth_hdr *)Buffer;

    printf("Eth Header\n");
    printf("   |-Destination Address : %02X-%02X-%02X-%02X-%02X-%02X \n",
            ethernet_header->ether_dhost[0],
            ethernet_header->ether_dhost[1],
            ethernet_header->ether_dhost[2],
            ethernet_header->ether_dhost[3],
            ethernet_header->ether_dhost[4],
            ethernet_header->ether_dhost[5]);

    printf("   |-Source Address      : %02X-%02X-%02X-%02X-%02X-%02X \n",
            ethernet_header->ether_shost[0],
            ethernet_header->ether_shost[1],
            ethernet_header->ether_shost[2],
            ethernet_header->ether_shost[3],
            ethernet_header->ether_shost[4],
            ethernet_header->ether_shost[5]);

    printf("   |-Protocol            : %02X \n", ethernet_header->ether_type);
}

void print_ip_header(const u_char *Buffer, int Size)
{
    unsigned short iphdrlen;
         
    ip_hdr *ip_header = (ip_hdr *)Buffer;
    iphdrlen = ip_header->ip_version_and_header_length & 0x0f;
    iphdrlen = iphdrlen * 4;
     
    printf("IP Header\n");
    printf("   |-IP Version        : %d\n",(ip_header->ip_version_and_header_length>>4));
    printf("   |-IP Header Length  : %d DWORDS or %d Bytes\n", iphdrlen,iphdrlen*4);
    printf("   |-Type Of Service   : %d\n",ip_header->ip_tos);
    printf("   |-IP Total Length   : %d  Bytes(Size of Packet)\n",ntohs(ip_header->ip_total_length));
    printf("   |-Identification    : %d\n",ntohs(ip_header->ip_id));
    printf("   |-TTL      : %d\n",ip_header->ip_ttl);
    printf("   |-Protocol : %d\n",ip_header->ip_protocol);
    printf("   |-Checksum : %d\n",ntohs(ip_header->ip_checksum));
    printf("   |-Source IP        : %d.%d.%d.%d\n",ip_header->ip_src_addr[0],ip_header->ip_src_addr[1],ip_header->ip_src_addr[2],ip_header->ip_src_addr[3]);
    printf("   |-Destination IP   : %d.%d.%d.%d\n",ip_header->ip_dest_addr[0],ip_header->ip_dest_addr[1],ip_header->ip_dest_addr[2],ip_header->ip_dest_addr[3]);
}

void print_tcp_packet(const u_char *Buffer, int Size)
{
    unsigned short iphdrlen;

    ip_hdr *ip_header = (ip_hdr *)Buffer;
    iphdrlen = ip_header->ip_version_and_header_length & 0x0f;
    iphdrlen = iphdrlen * 4;
     
    tcp_hdr *tcp_packet = (tcp_hdr*)(Buffer + ETHER_HDR_LEN + iphdrlen);

    int header_size = tcp_packet->data_offset_and_reserved >> 4;
    printf("TCP Header\n");
    printf("   |-Source Port          : %u\n", ntohs(tcp_packet->src_port));
    printf("   |-Destination Port     : %u\n", ntohs(tcp_packet->dst_port));
    printf("   |-Sequence Number      : %u\n", ntohl(tcp_packet->sequence));
    printf("   |-Acknowledge Number   : %u\n", ntohl(tcp_packet->acknowledgement));
    printf("   |-Header Length        : %d DWORDS or %d BYTES\n" , header_size, header_size*4);
    printf("   |-Urgent Flag          : %d\n", (tcp_packet->flags & 32)?1:0);
    printf("   |-Acknowledgement Flag : %d\n", (tcp_packet->flags & 16)?1:0);
    printf("   |-Push Flag            : %d\n", (tcp_packet->flags & 8)?1:0);
    printf("   |-Reset Flag           : %d\n", (tcp_packet->flags & 4)?1:0);
    printf("   |-Synchronise Flag     : %d\n", (tcp_packet->flags & 2)?1:0);
    printf("   |-Finish Flag          : %d\n", (tcp_packet->flags & 1)?1:0);
    printf("   |-Window Size          : %d\n", ntohs(tcp_packet->window_size));
    printf("   |-Checksum             : %d\n", ntohs(tcp_packet->checksum));
    printf("   |-Urgent Pointer       : %d\n", tcp_packet->urgent_pointer);
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    int size = header->len;
     
    //print the packet header
    printf("Packet Header\n");
    printf("   |-Packet Length      : %d\n", header->len);
    printf("   |-Number of Bytes captured     : %d\n", header->caplen);
    printf("   |-Timestamp (seconds) : %lld\n", header->ts.tv_sec);
    printf("   |-Timestamp (microseconds): %lld\n", header->ts.tv_usec);
     
    print_ethernet_header(pkt_data , size);
    print_ip_header(pkt_data, size);
    print_tcp_packet(pkt_data, size);
}

int main()
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    bpf_u_int32 net;
    bpf_u_int32 mask;
    char *dev = NULL;
    int promiscuous = 1;
    int timeout_ms = 1000;

    // get the name of the first NIC found
    dev = pcap_lookupdev(errbuf);

    // find the network address and mask
    pcap_lookupnet(dev, &net, &mask, errbuf);

    // open a capture handle
    handle = pcap_open_live(dev, BUFSIZ, promiscuous, timeout_ms, errbuf);

    // compile the filter expression
    pcap_compile(handle, &fp, "tcp", 0, net);

    // apply the filter
    pcap_setfilter(handle, &fp);

    // start the capture loop
    pcap_loop(handle, -1, packet_handler, NULL);

    return 0;
}