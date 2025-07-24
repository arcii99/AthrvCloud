//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>

void parse_packet(unsigned char* buffer, int size)
{
    struct iphdr* ip_header = (struct iphdr*)(buffer);
    unsigned short ip_header_length = ip_header->ihl * 4;
    
    switch (ip_header->protocol)
    {
        case IPPROTO_TCP:
        {
            struct tcphdr* tcp_header = (struct tcphdr*)(buffer + ip_header_length);
            printf("TCP Source Port: %d\n", ntohs(tcp_header->source));
            printf("TCP Destination Port: %d\n", ntohs(tcp_header->dest));
            printf("TCP Sequence Number: %u\n", ntohl(tcp_header->seq));
            printf("TCP Acknowledgement Number: %u\n", ntohl(tcp_header->ack_seq));
            break;
        }
        case IPPROTO_UDP:
        {
            struct udphdr* udp_header = (struct udphdr*)(buffer + ip_header_length);
            printf("UDP Source Port: %d\n", ntohs(udp_header->source));
            printf("UDP Destination Port: %d\n", ntohs(udp_header->dest));
            break;
        }
        default:
            break;
    }
}

int main()
{
    int raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (raw_socket < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in socket_address;
    socklen_t socket_address_length = sizeof(socket_address);
    
    while (1)
    {
        unsigned char buffer[4096];
        memset(buffer, 0, sizeof(buffer));
        int data_size = recvfrom(raw_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&socket_address, &socket_address_length);
        
        if (data_size < 0)
        {
            perror("Packet receive failed");
            exit(EXIT_FAILURE);
        }
        
        parse_packet(buffer, data_size);
    }
    
    close(raw_socket);
    return 0;
}