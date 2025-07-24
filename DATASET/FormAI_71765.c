//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 65536

void process_packet(unsigned char*, int);
void print_tcp_packet(unsigned char*, int);
void print_ip_header(unsigned char*);
void print_ethernet_header(unsigned char*);

int main() {
    int sock_raw, read_size, saddr_size;
    struct sockaddr saddr;
    unsigned char *buffer = (unsigned char*) malloc(BUFFER_SIZE);

    if (buffer == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_raw < 0) {
        printf("Failed to create socket.\n");
        free(buffer);
        return 1;
    }

    printf("Packet monitoring started...\n");

    while (1) {
        saddr_size = sizeof(saddr);
        read_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t*)&saddr_size);

        if (read_size > 0) {
            process_packet(buffer, read_size);
        }
    }

    free(buffer);
    close(sock_raw);

    return 0;
}

void process_packet(unsigned char *buffer, int size) {
    struct iphdr *iph = (struct iphdr*) buffer;

    if (iph->protocol == IPPROTO_TCP) {
        print_tcp_packet(buffer, size);
    }
}

void print_tcp_packet(unsigned char *buffer, int size) {
    struct iphdr *iph = (struct iphdr*) buffer;
    unsigned short iphdrlen = iph->ihl*4;
    struct tcphdr *tcph = (struct tcphdr*) (buffer + iphdrlen + sizeof(struct ethhdr));
    int header_size = sizeof(struct ethhdr) + iphdrlen + tcph->doff*4;

    printf("TCP Packet:\n");

    print_ethernet_header(buffer);

    print_ip_header(buffer);

    printf("TCP Header:\n");
    printf("   |-Source Port      : %u\n", ntohs(tcph->source));
    printf("   |-Destination Port : %u\n", ntohs(tcph->dest));
    printf("   |-Sequence Number  : %u\n", ntohl(tcph->seq));
    printf("   |-Acknowledge Number : %u\n", ntohl(tcph->ack_seq));
    printf("   |-Header Length : %d DWORDS or %d BYTES\n", tcph->doff, tcph->doff*4);
    printf("   |-Urgent Flag          : %d\n", tcph->urg);
    printf("   |-Acknowledgement Flag : %d\n", tcph->ack);
    printf("   |-Push Flag            : %d\n", tcph->psh);
    printf("   |-Reset Flag           : %d\n", tcph->rst);
    printf("   |-Synchronise Flag     : %d\n", tcph->syn);
    printf("   |-Finish Flag          : %d\n", tcph->fin);
    printf("   |-Window         : %d\n", ntohs(tcph->window));
    printf("   |-Checksum       : %d\n", ntohs(tcph->check));
    printf("   |-Urgent Pointer : %d\n", tcph->urg_ptr);
    printf("\n");
    printf("Data Payload:\n");

    unsigned char *data = buffer + header_size;
    int data_size = size - header_size;

    if (data_size > 0) {
        for (int i = 0; i < data_size; i++) {
            if (i != 0 && i%16 == 0) {
                printf("         ");
                for (int j = i - 16; j < i; j++) {
                    if (data[j] >= 32 && data[j] <= 128) {
                        printf("%c", (unsigned char)data[j]);
                    } else {
                        printf(".");
                    }
                }
                printf("\n");
            }

            if (i%16 == 0) printf("   ");
            printf(" %02X", (unsigned int)data[i]);
            
            if (i == data_size - 1) {
                for (int j = 0; j < 15 - i%16; j++) {
                    printf("   ");
                }
                printf("         ");
                for (int j = i - i%16; j <= i; j++) {
                    if (data[j] >= 32 && data[j] <= 128) {
                        printf("%c", (unsigned char)data[j]);
                    } else {
                        printf(".");
                    }
                }
                printf("\n");
            }
        }
    }

    printf("\n");
}

void print_ip_header(unsigned char *buffer) {
    struct iphdr *iph = (struct iphdr*) buffer;

    printf("IP Header:\n");
    printf("   |-Version : %d\n", (unsigned int)iph->version);
    printf("   |-Internet Header Length : %d DWORDS or %d Bytes\n", (unsigned int)iph->ihl, ((unsigned int)(iph->ihl))*4);
    printf("   |-Type Of Service : %d\n", (unsigned int)iph->tos);
    printf("   |-Total Length : %d Bytes\n", ntohs(iph->tot_len));
    printf("   |-Identification : %d\n", ntohs(iph->id));
    printf("   |-Time To Live : %d\n", (unsigned int) iph->ttl);
    printf("   |-Protocol : %d\n", (unsigned int)iph->protocol);
    printf("   |-Header Checksum : %d\n", ntohs(iph->check));
    printf("   |-Source IP : %s\n", inet_ntoa(*(struct in_addr *)&iph->saddr) );
    printf("   |-Destination IP : %s\n", inet_ntoa(*(struct in_addr *)&iph->daddr) );
}

void print_ethernet_header(unsigned char *buffer) {
    struct ethhdr *eth = (struct ethhdr *)buffer;

    printf("Ethernet Header:\n");
    printf("   |-Destination Address : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n", eth->h_dest[0], eth->h_dest[1], eth->h_dest[2], eth->h_dest[3], eth->h_dest[4], eth->h_dest[5] );
    printf("   |-Source Address      : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n", eth->h_source[0], eth->h_source[1], eth->h_source[2], eth->h_source[3], eth->h_source[4], eth->h_source[5] );
    printf("   |-Protocol            : %u \n", (unsigned short)eth->h_proto);
}