//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 65535

struct ipheader {
    unsigned char prot;         // protocol
    unsigned char tos;          // type of service
    unsigned short length;      // total length
    unsigned short id;          // identification
    unsigned short flags_offset;// flags and offset
    unsigned char ttl;          // time to live
    unsigned char src[4];       // source address
    unsigned char dst[4];       // destination address
};

struct tcpheader {
    unsigned short src_port;    // source port
    unsigned short dst_port;    // destination port
    unsigned int seq_num;       // sequence number
    unsigned int ack_num;       // acknowledgment number
    unsigned char header_len;   // TCP header length
    unsigned char flags;        // flags
    unsigned short win_size;    // window size
    unsigned short checksum;    // checksum
    unsigned short urg_ptr;     // urgent pointer
};

void packet_handler(unsigned char *, int);
void print_packet(unsigned char *, int);

int main(int argc, char **argv) {
    int sock, bytes;
    unsigned char buffer[BUFFER_SIZE];

    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bytes = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (bytes < 0) {
            perror("Failed to receive packet");
        } else {
            packet_handler(buffer, bytes);
        }
    }

    close(sock);
    return 0;
}

void packet_handler(unsigned char *buffer, int size) {
    struct ipheader *ip = (struct ipheader *)buffer;

    if (ip->prot == IPPROTO_TCP) {
        struct tcpheader *tcp = (struct tcpheader *)(buffer + sizeof(struct ipheader));

        if (ntohs(tcp->src_port) == 80 || ntohs(tcp->dst_port) == 80) {
            print_packet(buffer, size);
        }
    }
}

void print_packet(unsigned char *buffer, int size) {
    struct ipheader *ip = (struct ipheader *)buffer;
    struct tcpheader *tcp = (struct tcpheader *)(buffer + sizeof(struct ipheader));
    unsigned int ip_header_len = ip->length/4;
    unsigned int tcp_header_len = tcp->header_len/4;

    printf("Source IP: %d.%d.%d.%d\n", ip->src[0], ip->src[1], ip->src[2], ip->src[3]);
    printf("Destination IP: %d.%d.%d.%d\n", ip->dst[0], ip->dst[1], ip->dst[2], ip->dst[3]);
    printf("Protocol: TCP\n");
    printf("Source Port: %d\n", ntohs(tcp->src_port));
    printf("Destination Port: %d\n", ntohs(tcp->dst_port));
    printf("Sequence Number: %u\n", ntohl(tcp->seq_num));
    printf("Acknowledgment Number: %u\n", ntohl(tcp->ack_num));
    printf("Header Length: %u bytes\n", (int)tcp->header_len);
    printf("Window Size: %d\n", ntohs(tcp->win_size));
    printf("Checksum: 0x%04x\n", ntohs(tcp->checksum));
    printf("Urgent Pointer: %d\n", ntohs(tcp->urg_ptr));
    printf("\n");

    unsigned char *payload = buffer + sizeof(struct ipheader) + tcp_header_len;
    int payload_size = size - sizeof(struct ipheader) - tcp_header_len;

    if (payload_size > 0) {
        printf("Payload (%d bytes):\n\n", payload_size);
        int i;
        for (i = 0; i < payload_size; ++i) {
            printf("%02x ", payload[i]);
            if ((i + 1) % 16 == 0) printf("\n");
            if ((i + 1) % 8 == 0 && (i + 1) % 16 != 0) printf(" ");
        }
        printf("\n");
    }

    printf("******************************************\n");
}