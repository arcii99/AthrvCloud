//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ada Lovelace
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>

#define PORT 8080
#define BLOCK_LIST_SIZE 100

struct block_list {
    struct in_addr ip;
    struct block_list *next;
};

struct block_list *head = NULL;
pcap_t *handle;

void add_to_block_list(struct in_addr ip) {
    struct block_list *node = (struct block_list *) malloc(sizeof(struct block_list));
    node->ip = ip;
    node->next = head;
    head = node;
}

int is_blocked(struct in_addr ip) {
    struct block_list *ptr = head;
    while (ptr != NULL) {
        if (memcmp(&ptr->ip, &ip, sizeof(struct in_addr)) == 0)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}

void block_ip(struct in_addr ip) {
    /* Add firewall rule to block IP address */
    add_to_block_list(ip);
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    struct iphdr *ip_header = (struct iphdr *) buffer;
    if (ip_header->protocol == IPPROTO_TCP) {
        struct tcphdr *tcp_header = (struct tcphdr *) (buffer + ip_header->ihl * 4);
        if (ntohs(tcp_header->dest) == PORT) {
            struct in_addr ip_address;
            ip_address.s_addr = ip_header->saddr;
            if (is_blocked(ip_address)) {
                printf("Blocked traffic from IP %s\n", inet_ntoa(ip_address));
                return;
            }
            /* Perform rule-based analysis of TCP packet */
            if (tcp_header->syn == 1 && tcp_header->ack == 0) {
                /* New connection attempt */
                printf("New connection attempt from IP %s\n", inet_ntoa(ip_address));
            } else if (tcp_header->fin == 1 || tcp_header->rst == 1) {
                /* Connection closed or reset */
                printf("Connection closed/reset from IP %s\n", inet_ntoa(ip_address));
            } else if (tcp_header->psh == 1 && tcp_header->ack == 1) {
                /* Data transfer */
                printf("Data transfer from IP %s\n", inet_ntoa(ip_address));
            } else {
                /* Unknown behavior */
                printf("Unknown behavior from IP %s\n", inet_ntoa(ip_address));
            }
        }
    }
}

void sig_handler(int signo) {
    if (signo == SIGINT) {
        pcap_breakloop(handle);
    }
}

int main() {
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    bpf_u_int32 subnet_mask, ip_address;
    char *filter_expression = "tcp";

    signal(SIGINT, sig_handler);

    if (pcap_lookupnet("eth0", &ip_address, &subnet_mask, error_buffer) == -1) {
        fprintf(stderr, "Error: %s\n", error_buffer);
        exit(EXIT_FAILURE);
    }

    handle = pcap_open_live("eth0", BUFSIZ, 1, 0, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", error_buffer);
        exit(EXIT_FAILURE);
    }

    if (pcap_compile(handle, &filter, filter_expression, 0, ip_address) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_freecode(&filter);
    pcap_close(handle);
}