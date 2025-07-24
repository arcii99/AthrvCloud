//FormAI DATASET v1.0 Category: Firewall ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define BUFFER_SIZE 1024

void block_ip(char* ip)
{
    char command[BUFFER_SIZE];
    sprintf(command, "iptables -A INPUT -s %s -j DROP", ip);
    system(command);
    printf("Blocked IP %s\n", ip);
}

int main()
{
    int sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if(sock_raw < 0)
    {
        printf("Error: Could not create socket\n");
        exit(-1);
    }

    struct sockaddr_in source, dest;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int data_size, ip_header_size, tcp_header_size;

    while(1)
    {
        data_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if(data_size < 0)
        {
            printf("Error: Failed to read packet\n");
            exit(-1);
        }

        struct iphdr* ip_header = (struct iphdr*)buffer;
        ip_header_size = ip_header->ihl * 4;
        
        if(ip_header->protocol == IPPROTO_TCP)
        {
            struct tcphdr* tcp_header = (struct tcphdr*)(buffer + ip_header_size);
            tcp_header_size = tcp_header->doff * 4;

            char* payload = buffer + ip_header_size + tcp_header_size;
            int payload_size = data_size - ip_header_size - tcp_header_size;

            char source_ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(ip_header->saddr), source_ip, INET_ADDRSTRLEN);

            char dest_ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(ip_header->daddr), dest_ip, INET_ADDRSTRLEN);

            printf("Received TCP packet from %s:%u to %s:%u. Payload size: %d\n",
                    source_ip, ntohs(tcp_header->source), dest_ip, ntohs(tcp_header->dest), payload_size);

            if(strstr(payload, "badword") != NULL)
            {
                printf("Bad word found in payload. Blocking IP...\n");
                block_ip(source_ip);
            }
        }
    }

    close(sock_raw);
    return 0;
}