//FormAI DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define MAX_PACKET_SIZE 65536

/* Function prototypes */
void handle_packet(unsigned char*, int);
int drop_packet(struct tcphdr*, struct iphdr*);
void sig_handler(int);

/* Global variables */
int drop_count = 0;
int allow_count = 0;

int main(int argc, char** argv) {
    int sockfd, recv_len;
    struct sockaddr_in addr;
    unsigned char packet[MAX_PACKET_SIZE];
    
    // Register signal handler
    signal(SIGINT, sig_handler);
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // Set address parameters
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(0);
    
    // Bind socket to address
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    // Receive packets
    while (1) {
        recv_len = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, NULL, NULL);
        if (recv_len < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }
        
        // Handle packet
        handle_packet(packet, recv_len);
    }
    
    return 0;
}

void handle_packet(unsigned char* packet, int len) {
    struct iphdr* ip_header = (struct iphdr*)packet;
    struct tcphdr* tcp_header = (struct tcphdr*)(packet + ip_header->ihl*4);
    
    // Check if TCP packet
    if (ip_header->protocol != IPPROTO_TCP) {
        return;
    }
    
    // Drop or allow packet
    if (drop_packet(tcp_header, ip_header)) {
        drop_count++;
    } else {
        allow_count++;
    }
}

int drop_packet(struct tcphdr* tcp_header, struct iphdr* ip_header) {
    char* src_ip = inet_ntoa((struct in_addr){ip_header->saddr});
    char* dst_ip = inet_ntoa((struct in_addr){ip_header->daddr});
    int src_port = ntohs(tcp_header->source);
    int dst_port = ntohs(tcp_header->dest);
    
    // Add firewall rules here
    if (strcmp(src_ip, "192.168.1.2") == 0 && dst_port == 80) {
        return 1;
    } else if (strcmp(src_ip, "10.0.0.1") == 0 && dst_port == 22) {
        return 1;
    }
    
    return 0;
}

void sig_handler(int signo) {
    printf("Received %d signal.\n", signo);
    printf("Firewall blocked %d packets and allowed %d packets.\n", drop_count, allow_count);
    exit(EXIT_SUCCESS);
}