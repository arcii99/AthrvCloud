//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

typedef struct packet {
    struct ip{
        struct in_addr src;
        struct in_addr dest;
        u_short protocol;
    }ip_hdr;
    struct icmp{
        u_char type;
        u_char code;
        u_short checksum;
    }icmp_hdr;
    struct tcp{
        u_short src_port;
        u_short dest_port;
        u_int seq_no;
        u_int ack_no;
        u_short flags;
    }tcp_hdr;
    struct udp{
        u_short src_port;
        u_short dest_port;
        u_short length;
    }udp_hdr;
}packet_t;

void capture_packet(u_char* user, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    packet_t *packet_ptr = (packet_t *) packet;
    printf("IP Src: %s\n", inet_ntoa(packet_ptr->ip_hdr.src));
    printf("IP Dest: %s\n", inet_ntoa(packet_ptr->ip_hdr.dest));
    switch (packet_ptr->ip_hdr.protocol) {
        case IPPROTO_ICMP:
            printf("Protocol: ICMP\n");
            printf("Type: %d\n", packet_ptr->icmp_hdr.type);
            printf("Code: %d\n", packet_ptr->icmp_hdr.code);
            break;
        case IPPROTO_TCP:
            printf("Protocol: TCP\n");
            printf("Src Port: %d\n", ntohs(packet_ptr->tcp_hdr.src_port));
            printf("Dest Port: %d\n", ntohs(packet_ptr->tcp_hdr.dest_port));
            printf("Sequence No: %u\n", ntohl(packet_ptr->tcp_hdr.seq_no));
            printf("Ack No: %u\n", ntohl(packet_ptr->tcp_hdr.ack_no));
            break;
        case IPPROTO_UDP:
            printf("Protocol: UDP\n");
            printf("Src Port: %d\n", ntohs(packet_ptr->udp_hdr.src_port));
            printf("Dest Port: %d\n", ntohs(packet_ptr->udp_hdr.dest_port));
            printf("Length: %d\n", ntohs(packet_ptr->udp_hdr.length));
            break;
        default:
            printf("Unknown Protocol\n");
            break;
    }
    printf("\n");
}

void packet_monitor(char* device) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;

    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Can't get netmask for device %s\n", device);
        net = 0;
        mask = 0;
    }
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open device %s: %s\n", device, errbuf);
        exit(EXIT_FAILURE);
    }
    if (pcap_compile(handle, &fp, "tcp or udp or icmp", 0, net) == -1) {
        fprintf(stderr, "Failed to compile BPF filter, %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Failed to apply BPF filter, %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }
    if (pcap_loop(handle, -1, capture_packet, NULL) == -1) {
        fprintf(stderr, "Failed to capture packets, %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }
    pcap_close(handle);
}

int main(int argc, char** argv) {
    char* device;
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    device = argv[1];
    printf("Monitoring packets on device: %s\n\n", device);
    packet_monitor(device);
    return 0;
}