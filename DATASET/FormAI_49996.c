//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define PACKET_BUFFER_SIZE 65536

int main()
{
    int sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(sock_raw == -1)
    {
        printf("Socket creation failed with error : %d\n" , errno);
        return 1;
    }

    unsigned char *buffer = (unsigned char *)malloc(PACKET_BUFFER_SIZE);
    if(buffer == NULL)
    {
        printf("Memory allocation error\n");
        return 1;
    }

    while(1)
    {
        memset(buffer, 0, PACKET_BUFFER_SIZE);

        int data_size = recvfrom(sock_raw, buffer, PACKET_BUFFER_SIZE, 0, NULL, NULL);
        if(data_size < 0)
        {
            printf("Recvfrom error , failed to get packets\n");
            return 1;
        }

        struct ethhdr *eth_header = (struct ethhdr *)buffer;
        struct iphdr *ip_header = (struct iphdr *)(buffer + sizeof(struct ethhdr));

        if(ntohs(eth_header->h_proto) == ETH_P_IP)
        {
            char source_address[INET_ADDRSTRLEN];
            char dest_address[INET_ADDRSTRLEN];

            inet_ntop(AF_INET, &(ip_header->saddr), source_address, INET_ADDRSTRLEN);
            inet_ntop(AF_INET, &(ip_header->daddr), dest_address, INET_ADDRSTRLEN);

            printf("Source IP: %s\n", source_address);
            printf("Destination IP: %s\n", dest_address);
            printf("Protocol: %d\n", (unsigned int)ip_header->protocol);

            switch(ip_header->protocol)
            {
                case IPPROTO_TCP:
                    {
                        struct tcphdr *tcp_header = (struct tcphdr *)((unsigned char *)ip_header + sizeof(struct iphdr));

                        printf("Source Port: %d\n", ntohs(tcp_header->source));
                        printf("Destination Port: %d\n", ntohs(tcp_header->dest));
                        printf("\n");

                        break;
                    }

                case IPPROTO_UDP:
                    {
                        struct udphdr *udp_header = (struct udphdr *)((unsigned char *)ip_header + sizeof(struct iphdr));

                        printf("Source Port: %d\n", ntohs(udp_header->source));
                        printf("Destination Port: %d\n", ntohs(udp_header->dest));
                        printf("\n");

                        break;
                    }

                default:
                    {
                        printf("Unknown protocol\n");
                        printf("\n");

                        break;
                    }
            }
        }
    }

    close(sock_raw);
    free(buffer);

    return 0;
}