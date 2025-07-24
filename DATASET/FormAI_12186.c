//FormAI DATASET v1.0 Category: Firewall ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <errno.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define ETHERNET_SIZE 14
#define IP_SIZE 20
#define TCP_SIZE 20
#define CMD_LENGTH 100

char *BLOCKED_IP = "192.168.1.3";
int BLOCKED_PORT = 80;

void block_traffic() {
    printf("Blocking traffic to %s:%d\n", BLOCKED_IP, BLOCKED_PORT);
    char cmd[CMD_LENGTH];
    sprintf(cmd, "sudo iptables -A INPUT -s %s -p tcp --destination-port %d -j DROP", BLOCKED_IP, BLOCKED_PORT);
    system(cmd);
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *ethernet_header;
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;

    const u_char *payload;
    int payload_size;

    ethernet_header = (struct ether_header *) packet;

    if (ntohs(ethernet_header->ether_type) != ETHERTYPE_IP) {
        return;
    }

    ip_header = (struct iphdr *) (packet + ETHERNET_SIZE);

    if (ip_header->protocol != IPPROTO_TCP) {
        return;
    }

    tcp_header = (struct tcphdr *) (packet + ETHERNET_SIZE + IP_SIZE);

    if (strcmp(inet_ntoa(*(struct in_addr *)&ip_header->daddr), BLOCKED_IP) == 0 &&
        ntohs(tcp_header->dest) == BLOCKED_PORT) {
        block_traffic();
    }
}

int main(int argc, char *argv[]) {
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    bpf_u_int32 subnet_mask, ip;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pcap_lookupnet(argv[1], &ip, &subnet_mask, error_buffer) == -1) {
        fprintf(stderr, "Error retrieving network information: %s\n", error_buffer);
        exit(EXIT_FAILURE);
    }

    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, error_buffer);

    if (handle == NULL) {
        fprintf(stderr, "Error opening network interface: %s\n", error_buffer);
        exit(EXIT_FAILURE);
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, ip) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_loop(handle, -1, process_packet, NULL);

    return EXIT_SUCCESS;
}