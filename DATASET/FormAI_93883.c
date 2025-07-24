//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define BUFFER_SIZE 65536

void print_packet(unsigned char *buffer, int size);

int main(int argc, char *argv[]) {
    int sock_raw, data_size;
    struct sockaddr_in saddr;
    unsigned char buffer[BUFFER_SIZE];
    
    // Create a raw socket that receives all the incoming packets
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    
    if (sock_raw < 0) {
        perror("Error creating socket");
        return 1;
    }
    
    // Set the socket option to receive all the incoming packets
    int enable = 1;
    
    if (setsockopt(sock_raw, IPPROTO_IP, IP_HDRINCL, &enable, sizeof(enable)) < 0) {
        perror("Error setting socket options");
        return 1;
    }
    
    printf("Packet monitoring started...\n");
    
    // Receive and process the incoming packets
    while (1) {
        data_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, NULL, NULL);
        
        if (data_size < 0) {
            perror("Error receiving data");
            break;
        }
        
        // Print the incoming packet details
        print_packet(buffer, data_size);
    }
    
    close(sock_raw);
    printf("Packet monitoring stopped.\n");
    
    return 0;
}

void print_packet(unsigned char *buffer, int size) {
    struct iphdr *iph = (struct iphdr*)buffer;
    unsigned short iphdr_length = iph->ihl*4;
    struct tcphdr *tcph = (struct tcphdr*)(buffer + iphdr_length);
    unsigned int src_ip = iph->saddr;
    unsigned int dest_ip = iph->daddr;
    unsigned short src_port = ntohs(tcph->source);
    unsigned short dest_port = ntohs(tcph->dest);
    
    printf("Incoming Packet\n");
    printf("-----------------\n");
    printf("Source IP: %u.%u.%u.%u\n", (unsigned char)(src_ip), (unsigned char)(src_ip>>8), (unsigned char)(src_ip>>16), (unsigned char)(src_ip>>24));
    printf("Destination IP: %u.%u.%u.%u\n", (unsigned char)(dest_ip), (unsigned char)(dest_ip>>8), (unsigned char)(dest_ip>>16), (unsigned char)(dest_ip>>24));
    printf("Source Port: %u\n", src_port);
    printf("Destination Port: %u\n", dest_port);
    printf("\n\n");
}