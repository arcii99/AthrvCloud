//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sock_fd = 0;
    int bytes_received = 0;
    unsigned char buffer[2048] = {0};
    struct sockaddr_in saddr;
    struct sockaddr_in source, dest;
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;

    // create socket
    sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_fd < 0) {
        perror("Failed to create socket");
        return -1;
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        bytes_received = recvfrom(sock_fd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (bytes_received < 0) {
            perror("Failed to receive packet");
            close(sock_fd);
            return -1;
        }
        
        // Get the IP header
        ip_header = (struct iphdr*)buffer;

        // get source and destination IP addresses
        memset(&source, 0, sizeof(source));
        source.sin_addr.s_addr = ip_header->saddr;

        memset(&dest, 0, sizeof(dest));
        dest.sin_addr.s_addr = ip_header->daddr;

        // Check if packet is TCP protocol
        if (ip_header->protocol == IPPROTO_TCP) {

            // get TCP header
            tcp_header = (struct tcphdr*)(buffer + ip_header->ihl*4);

            // print information - source source ip, source port, dest ip, dest port
            printf("Source IP: %s\n", inet_ntoa(source.sin_addr));
            printf("Source Port: %d\n", ntohs(tcp_header->source));
            printf("Destination IP: %s\n", inet_ntoa(dest.sin_addr));
            printf("Destination Port: %d\n", ntohs(tcp_header->dest));
            printf("Packet Length: %d\n", ntohs(ip_header->tot_len));
            printf("\n");
        }
    }

    close(sock_fd);
    return 0;
}