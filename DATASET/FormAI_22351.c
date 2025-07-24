//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>

#define SOURCE_PORT 8888 // source port number
#define DEST_PORT 80 // destination port number
#define MAX_PACKET_SIZE 65536 // maximum packet size
#define MAX_PAYLOAD_SIZE MAX_PACKET_SIZE - sizeof(struct iphdr) - sizeof(struct tcphdr) // maximum payload size
#define MAX_RETRIES 5 // maximum number of retries

// function to calculate checksum
unsigned short calculate_checksum(unsigned short *ptr, int length) {
    unsigned long sum = 0;
    while(length > 1) {
        sum += *ptr++;
        length -= 2;
    }
    if(length == 1) {
        sum += *(unsigned char*)ptr;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

// function to create raw socket
int create_raw_socket() {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sockfd == -1) {
        perror("Error creating raw socket");
        exit(EXIT_FAILURE);
    }
    
    return sockfd;
}

// function to set IP header fields
void set_ip_hdr_fields(struct iphdr* ip_hdr, struct sockaddr_in dest_addr) {
    ip_hdr->ihl = 5;
    ip_hdr->version = 4;
    ip_hdr->tos = 0;
    ip_hdr->tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr);
    ip_hdr->id = htons(54321);
    ip_hdr->frag_off = htons(0);
    ip_hdr->ttl = 255;
    ip_hdr->protocol = IPPROTO_TCP;
    ip_hdr->check = 0;
    ip_hdr->saddr = INADDR_ANY;
    ip_hdr->daddr = dest_addr.sin_addr.s_addr;
    ip_hdr->check = calculate_checksum((unsigned short*)ip_hdr, ip_hdr->tot_len >> 1);
}

// function to set TCP header fields
void set_tcp_hdr_fields(struct tcphdr *tcp_hdr) {
    tcp_hdr->seq = htonl(1105024978);
    tcp_hdr->ack_seq = 0;
    tcp_hdr->doff = sizeof(struct tcphdr) / 4;
    tcp_hdr->fin = 0;
    tcp_hdr->syn = 1;
    tcp_hdr->rst = 0;
    tcp_hdr->psh = 0;
    tcp_hdr->ack = 0;
    tcp_hdr->urg = 0;
    tcp_hdr->window = htons(14600);
    tcp_hdr->check = 0;
    tcp_hdr->urg_ptr = 0;
}

// function to send TCP packet
void send_tcp_packet(int sockfd, struct sockaddr_in dest_addr) {
    char packet[MAX_PACKET_SIZE];
    struct iphdr *ip_hdr = (struct iphdr*)packet;
    struct tcphdr *tcp_hdr = (struct tcphdr*)(packet + sizeof(struct iphdr));
    memset(packet, 0, MAX_PACKET_SIZE);
    
    // set IP header fields
    set_ip_hdr_fields(ip_hdr, dest_addr);
    
    // set TCP header fields
    set_tcp_hdr_fields(tcp_hdr);
    
    // calculate TCP checksum
    tcp_hdr->source = htons(SOURCE_PORT);
    tcp_hdr->dest = htons(DEST_PORT);
    tcp_hdr->check = calculate_checksum((unsigned short*)tcp_hdr, sizeof(struct tcphdr));
    
    // set destination address
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(DEST_PORT);
    
    // send packet
    int num_retries = 0;
    while(num_retries < MAX_RETRIES) {
        if(sendto(sockfd, (char*)packet, ip_hdr->tot_len, 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) == -1) {
            perror("Error sending packet");
            exit(EXIT_FAILURE);
        } else {
            printf("Packet sent successfully\n");
            break;
        }
        num_retries++;
    }
}

// signal handler for packet loss
void handle_packet_loss(int signum) {
    printf("Packet loss detected\n");
}

// function to listen for incoming packets
void listen_for_packets(int sockfd) {
    struct sockaddr_in dest_addr;
    char buffer[MAX_PACKET_SIZE];
    memset(buffer, 0, MAX_PACKET_SIZE);
    
    signal(SIGALRM, handle_packet_loss);
    
    while(1) {
        socklen_t addrlen = sizeof(dest_addr);
        
        // wait for incoming packet
        if(recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr*)&dest_addr, &addrlen) == -1) {
            perror("Error receiving packet");
            exit(EXIT_FAILURE);
        } else {
            printf("Packet received successfully\n");
            printf("Source IP: %s\n", inet_ntoa(dest_addr.sin_addr));
            printf("Source Port: %d\n", ntohs(dest_addr.sin_port));
            printf("Payload: %s\n", buffer + sizeof(struct iphdr) + sizeof(struct tcphdr));
        }
    }
}

int main() {
    int sockfd = create_raw_socket();
    
    struct hostent *he;
    struct sockaddr_in dest_addr;
    char *dest_ip = "127.0.0.1";
    
    if((he = gethostbyname(dest_ip)) == NULL) {
        perror("Error resolving host");
        exit(EXIT_FAILURE);
    }
    
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(DEST_PORT);
    dest_addr.sin_addr = *((struct in_addr*)he->h_addr);
    
    // send TCP packet
    send_tcp_packet(sockfd, dest_addr);
    
    // listen for incoming packets
    listen_for_packets(sockfd);
    
    return 0;
}