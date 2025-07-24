//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <string.h>

#define MAX_PACKET_SIZE 65536

// Function to print the payload data of the packet.
void print_payload(const unsigned char *payload, int len)
{
    printf("\nPayload:\n");

    int count = 0;
    while (count < len)
    {
        printf("%02x ", *(payload++));
        count++;
        if (count % 16 == 0)
            printf("\n");
    }
    printf("\n");
}

// Main function to monitor network traffic.
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./monitor <IP>\n");
        exit(1);
    }

    int sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP); // Create raw socket to read packets.
    if (sock_raw < 0)
    {
        printf("Error creating socket. You must have sudo privileges to run this program.\n");
        exit(1);
    }

    struct sockaddr_in saddr;
    unsigned char buffer[MAX_PACKET_SIZE];

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(0);
    saddr.sin_addr.s_addr = inet_addr(argv[1]);

    // Bind socket to interface.
    if (bind(sock_raw, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
    {
        perror("Bind failed\n");
        close(sock_raw);
        exit(1);
    }

    printf("Monitoring traffic to: %s\n", argv[1]);

    while (1)
    {
        int saddr_len = sizeof(saddr);
        int data_len = recvfrom(sock_raw, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&saddr, &saddr_len);
        if (data_len < 0)
        {
            printf("Error receiving data.\n");
            close(sock_raw);
            exit(1);
        }

        // Extract IP header.
        struct iphdr *ip_hdr = (struct iphdr *)buffer;
        if (ip_hdr->protocol == 6) // TCP protocol.
        {
            // Extract TCP header and payload data.
            struct tcphdr *tcp_hdr = (struct tcphdr *)(buffer + sizeof(struct iphdr));
            int tcp_hdr_len = tcp_hdr->doff * 4;
            int payload_len = data_len - sizeof(struct iphdr) - tcp_hdr_len;

            printf("Source IP: %s\n", inet_ntoa((struct in_addr){ip_hdr->saddr}));
            printf("Destination IP: %s\n", inet_ntoa((struct in_addr){ip_hdr->daddr}));
            printf("Source Port: %d\n", ntohs(tcp_hdr->source));
            printf("Destination Port: %d\n", ntohs(tcp_hdr->dest));
            printf("Sequence Number: %u\n", ntohl(tcp_hdr->seq));
            printf("Acknowledgement Number: %u\n", ntohl(tcp_hdr->ack_seq));
            printf("TCP Header Length: %d bytes\n", tcp_hdr_len);
            printf("Payload Length: %d bytes\n", payload_len);

            if (payload_len > 0)
            {
                print_payload(buffer + sizeof(struct iphdr) + tcp_hdr_len, payload_len);
            }
        }
    }

    close(sock_raw);
    return 0;
}