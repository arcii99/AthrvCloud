//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string.h>

#define ETH_ALEN 6
#define ETH_HLEN 14
#define SNAP_LEN 1518
#define true 1
#define false 0

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;

typedef struct ethernet_header{
    byte dest[ETH_ALEN];
    byte src[ETH_ALEN];
    word type;
}eth_hdr;

typedef struct ip_header{
    byte ver_ihl;
    byte tos;
    word tlen;
    word identification;
    word flags_fo;
    byte ttl;
    byte proto;
    word chksum;
    byte src[4];
    byte dest[4];
}ip_hdr;

typedef struct tcp_header{
    word sport;
    word dport;
    dword seq;
    dword ack;
    byte len_flags;
    byte win;
    word chksum;
    word urg;
}tcp_hdr;

typedef struct udp_header{
    word sport;
    word dport;
    word len;
    word chksum;
}udp_hdr;

int datalink = 0;

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* pkt);
void print_eth_header(const eth_hdr* eth);
void print_ip_header(const ip_hdr* ip);
void print_tcp_header(const tcp_hdr* tcp);
void print_udp_header(const udp_hdr* udp);

int main(int argc, char *argv[]) {
    pcap_t *descr;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    bpf_u_int32 netp;
    bpf_u_int32 maskp;
    struct bpf_program filter;

    if(argc < 2) {
        printf("Usage: %s interface\n", argv[0]);
        return 1;
    }

    dev = argv[1];

    if(pcap_lookupnet(dev, &netp, &maskp, errbuf) == -1) {
        printf("Error getting netmask for device %s: %s\n", dev, errbuf);
        netp = 0;
        maskp = 0;
    }

    /* Open device for live capture */
    descr = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if(descr == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        return 1;
    }

    /* Compile filter */
    if(pcap_compile(descr, &filter, "tcp or udp", 1, maskp) == -1) {
        printf("pcap_compile() failed\n");
        pcap_close(descr);
        return 1;
    }

    /* Apply compiled filter */
    if(pcap_setfilter(descr, &filter) == -1) {
        printf("pcap_setfilter() failed\n");
        pcap_close(descr);
        return 1;
    }

    /* Set callback function */
    pcap_loop(descr, 0, packet_handler, NULL);

    return 0;
}

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* pkt)
{
    const eth_hdr* eth;
    const ip_hdr* ip;
    const tcp_hdr* tcp;
    const udp_hdr* udp;

    datalink = pkthdr->caplen;
    eth = (eth_hdr *)pkt;

    if(ntohs(eth->type) == 0x0800) {
        ip = (ip_hdr *)(pkt + ETH_HLEN);

        switch(ip->proto) {
            case IPPROTO_TCP:
                tcp = (tcp_hdr *)(pkt + ETH_HLEN + sizeof(ip_hdr));
                print_eth_header(eth);
                print_ip_header(ip);
                printf("\n\t\tTCP Header\n");
                print_tcp_header(tcp);
                printf("\n----------------------------------------------------\n");
                break;
            case IPPROTO_UDP:
                udp = (udp_hdr *)(pkt + ETH_HLEN + sizeof(ip_hdr));
                print_eth_header(eth);
                print_ip_header(ip);
                printf("\n\t\tUDP Header\n");
                print_udp_header(udp);
                printf("\n----------------------------------------------------\n");
                break;
            default:
                break;
        }
    }
}

void print_eth_header(const eth_hdr* eth) {
    int i;
    printf("\nEthernet Header - ");
    printf("\n\tDestination Address : ");
    for(i=0; i<ETH_ALEN; i++)
        printf("%02x ", eth->dest[i]);

    printf("\n\tSource Address      : ");
    for(i=0; i<ETH_ALEN; i++)
        printf("%02x ", eth->src[i]);

    printf("\n\tType                : %u\n", ntohs(eth->type));
}

void print_ip_header(const ip_hdr* ip) {
    printf("\nIP Header - ");
    printf("\n\tVersion            : %u", (unsigned int)ip->ver_ihl >> 4);
    printf("\n\tIP Header Length   : %u bytes", ((unsigned int)ip->ver_ihl & 0x0f)*4);
    printf("\n\tType of Service    : %u", ip->tos);
    printf("\n\tTotal Length       : %u bytes", ntohs(ip->tlen));
    printf("\n\tIdentification     : %u", ntohs(ip->identification));
    printf("\n\tFlags              : %u", ntohs(ip->flags_fo) >> 13);
    printf("\n\tFragment Offset    : %u bytes", ntohs(ip->flags_fo) & 0x1fff);
    printf("\n\tTime to Live       : %u", ip->ttl);
    printf("\n\tProtocol           : %u", ip->proto);
    printf("\n\tChecksum           : %u", ntohs(ip->chksum));
    printf("\n\tSource IP          : %d.%d.%d.%d", ip->src[0], ip->src[1], ip->src[2], ip->src[3]);
    printf("\n\tDestination IP     : %d.%d.%d.%d", ip->dest[0], ip->dest[1], ip->dest[2], ip->dest[3]);
}

void print_tcp_header(const tcp_hdr* tcp) {
    printf("\n\tSource Port        : %u", ntohs(tcp->sport));
    printf("\n\tDestination Port   : %u", ntohs(tcp->dport));
    printf("\n\tSequence Number    : %u", ntohl(tcp->seq));
    printf("\n\tAcknowledgement    : %u", ntohl(tcp->ack));
    printf("\n\tData Offset        : %u bytes", (tcp->len_flags >> 4)*4);
    printf("\n\tReserved           : %u", (tcp->len_flags >> 1) & 0x7);
    printf("\n\tTCP Flags          :");
    if(tcp->len_flags & 0x80) printf(" FIN");
    if(tcp->len_flags & 0x40) printf(" SYN");
    if(tcp->len_flags & 0x20) printf(" RST");
    if(tcp->len_flags & 0x10) printf(" PSH");
    if(tcp->len_flags & 0x08) printf(" ACK");
    if(tcp->len_flags & 0x04) printf(" URG");
    if(tcp->len_flags & 0x02) printf(" ECE");
    if(tcp->len_flags & 0x01) printf(" CWR");
    printf("\n\tWindow             : %u", ntohs(tcp->win));
    printf("\n\tChecksum           : %u", ntohs(tcp->chksum));
    printf("\n\tUrgent Pointer     : %u\n", ntohs(tcp->urg));
}

void print_udp_header(const udp_hdr* udp) {
    printf("\n\tSource Port        : %u", ntohs(udp->sport));
    printf("\n\tDestination Port   : %u", ntohs(udp->dport));
    printf("\n\tLength             : %u bytes", ntohs(udp->len));
    printf("\n\tChecksum           : %u\n", ntohs(udp->chksum));
}