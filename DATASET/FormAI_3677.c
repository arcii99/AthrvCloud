//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_PACKET_SIZE 65536

struct packet_info{
    struct sockaddr_in source_addr;
    struct sockaddr_in dest_addr;
    unsigned char* packet;
    int size;
};

void handle_packet(unsigned char* buffer, int size);
void process_packet(unsigned char* buffer, int size);
void print_packet_info(struct packet_info* packet_info);

int main(){
    int sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sock_raw < 0){
        printf("Socket creation error\n");
        exit(1);
    }
    struct sockaddr_in saddr;
    int saddr_len = sizeof(saddr);
    unsigned char buffer[MAX_PACKET_SIZE];
    while(1){
        int data_size = recvfrom(sock_raw, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr*)&saddr, &saddr_len);
        if(data_size < 0){
            printf("Recvfrom error\n");
            exit(1);
        }
        handle_packet(buffer, data_size);
    }
    close(sock_raw);
    return 0;
}

void handle_packet(unsigned char* buffer, int size){
    struct iphdr* ip_hdr = (struct iphdr*)buffer;
    struct packet_info packet_info;
    packet_info.source_addr.sin_addr.s_addr = ip_hdr->saddr;
    packet_info.dest_addr.sin_addr.s_addr = ip_hdr->daddr;
    packet_info.packet = buffer;
    packet_info.size = size;

    process_packet(buffer + sizeof(struct iphdr), size - sizeof(struct iphdr));
    print_packet_info(&packet_info);
}

void process_packet(unsigned char* buffer, int size){
    struct tcphdr* tcp_hdr = (struct tcphdr*)buffer;

    printf("Source Port : %d\n", ntohs(tcp_hdr->source));
    printf("Destination Port : %d\n", ntohs(tcp_hdr->dest));
    printf("Sequence Number : %u\n", ntohl(tcp_hdr->seq));
    printf("Ack Number : %u\n", ntohl(tcp_hdr->ack_seq));
    printf("Header Length : %d\n", tcp_hdr->doff*4);
    printf("\n");
}

void print_packet_info(struct packet_info* packet_info){
    printf("Source IP : %s\n", inet_ntoa(packet_info->source_addr.sin_addr));
    printf("Destination IP : %s\n", inet_ntoa(packet_info->dest_addr.sin_addr));
    printf("Packet Size : %d bytes\n", packet_info->size);
    printf("\n");
}