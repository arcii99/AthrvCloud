//FormAI DATASET v1.0 Category: Firewall ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Check if user has root access
    if (geteuid() != 0) {
        printf("Firewall must be run as root user.\n");
        return 1;
    }
    
    // Create socket
    int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sock_fd == -1) {
        perror("There was a problem creating the socket.\n");
        return 1;
    }
    
    // Bind socket to network interface
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, "eth0", strlen("eth0"));
    if (ioctl(sock_fd, SIOCGIFINDEX, &ifr) == -1) {
        perror("There was a problem getting the interface index.\n");
        return 1;
    }
    
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock_fd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror("There was a problem binding the socket to the interface.\n");
        return 1;
    }

    // Set IP_HDRINCL option
    const int one = 1;
    if (setsockopt(sock_fd, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) == -1) {
        perror("There was a problem setting IP_HDRINCL option.\n");
        return 1;
    }

    // Initialize buffer for incoming packets
    unsigned char buffer[BUFFER_SIZE];

    while (1) {
        // Receive packet
        ssize_t n = recvfrom(sock_fd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (n == -1) {
            perror("There was a problem receiving the packet.\n");
            return 1;
        }

        // Parse IP header
        struct iphdr *ip_header = (struct iphdr *)buffer;
        
        // Check if packet is TCP or UDP
        if (ip_header->protocol == IPPROTO_TCP) {
            struct tcphdr *tcp_header = (struct tcphdr *)((unsigned char *)ip_header + (ip_header->ihl * 4));
            
            // Check if source IP and port match our rules
            if ((ip_header->saddr == inet_addr("10.0.0.5")) && (ntohs(tcp_header->source) == 1234)) {
                printf("Blocked TCP packet from malicious source.\n");
                continue;
            }
        } else if (ip_header->protocol == IPPROTO_UDP) {
            struct udphdr *udp_header = (struct udphdr *)((unsigned char *)ip_header + (ip_header->ihl * 4));
            
            // Check if source IP and port match our rules
            if ((ip_header->saddr == inet_addr("10.0.0.5")) && (ntohs(udp_header->source) == 1234)) {
                printf("Blocked UDP packet from malicious source.\n");
                continue;
            }
        } else {
            // Ignore non-TCP and non-UDP packets
            continue;
        }

        // Forward packet to its destination
        struct sockaddr_in dest;
        dest.sin_family = AF_INET;
        dest.sin_addr.s_addr = ip_header->daddr;
        if (sendto(sock_fd, buffer, n, 0, (struct sockaddr *)&dest, sizeof(dest)) == -1) {
            perror("Failed to forward packet.\n");
            return 1;
        }
    }

    // Close socket
    close(sock_fd);

    return 0;
}