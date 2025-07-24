//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE  4096
#define ETHER_ADDR_LEN   6
#define IP_ADDR_LEN      4

struct eth_header {
    unsigned char dst[ETHER_ADDR_LEN];
    unsigned char src[ETHER_ADDR_LEN];
    unsigned short type; 
};

struct ip_header {
    unsigned char  ver_ihl;           
    unsigned char  tos;               
    unsigned short tlen;              
    unsigned short identification;   
    unsigned short flags_fo;          
    unsigned char  ttl;               
    unsigned char  proto;             
    unsigned short crc;               
    unsigned char  srcAddr[IP_ADDR_LEN];    
    unsigned char  dstAddr[IP_ADDR_LEN];    
};

void print_usage() {
    printf("Usage: wireless_scanner <interface>\n");
}

int main(int argc, char *argv[]) {
    int sock_raw;
    int bytes_read;
    struct sockaddr_in saddr;
    unsigned char packet[MAX_PACKET_SIZE];

    if (argc != 2) {
        print_usage();
        return -1;
    }

    if ((sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) == -1) {
        printf("Error creating socket.\n");
        return -1;
    }

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port   = htons(0);
    saddr.sin_addr.s_addr = inet_addr("0.0.0.0");

    if (bind(sock_raw, (struct sockaddr *)&saddr, sizeof(saddr)) == -1) {
        printf("Error binding to socket.\n");
        return -1;
    }

    printf("Starting wireless scanner...\n\n");

    while (1) {
        bytes_read = recv(sock_raw, packet, MAX_PACKET_SIZE, 0);
        if (bytes_read <= 0) {
            printf("Error while reading packet.\n");
            continue;
        }

        struct eth_header *eth_hdr = (struct eth_header *)packet;

        if (ntohs(eth_hdr->type) != 0x0800) {
            continue; 
        }

        struct ip_header *ip_hdr = (struct ip_header *)(packet + sizeof(struct eth_header));

        if (ip_hdr->proto != 17) {
            continue;
        }

        printf("Packet received from %d.%d.%d.%d\n", 
            ip_hdr->srcAddr[0], 
            ip_hdr->srcAddr[1], 
            ip_hdr->srcAddr[2], 
            ip_hdr->srcAddr[3]);
    }

    return 0;
}