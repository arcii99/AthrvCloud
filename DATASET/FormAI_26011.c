//FormAI DATASET v1.0 Category: Firewall ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <unistd.h>
#include <errno.h>

#define BLOCKED_IPS_SIZE 100 // maximum number of blocked IPs

void block_ip(const char* ip_addr);

int is_ip_blocked(const char* ip_addr);

char blocked_ips[BLOCKED_IPS_SIZE][16];

int main(int argc, char const *argv[]) {
    int sockfd, addr_len, recv_len, optval;
    char buffer[4096];
    struct sockaddr_in server_addr, client_addr;
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;
    
    // create socket
    sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(1);
    }
    
    // set socket options
    optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) == -1) {
        perror("Failed to set socket options");
        exit(1);
    }
    
    // bind socket to local address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8888);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket");
        exit(1);
    }
    
    // listen for incoming connections
    if (listen(sockfd, 10) == -1) {
        perror("Failed to listen for connections");
        exit(1);
    }
    
    printf("Firewall started...\n");
    
    while (1) {
        addr_len = sizeof(client_addr);
        memset(&client_addr, 0, addr_len);
        
        // accept incoming connection
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sockfd == -1) {
            perror("Failed to accept connection");
            continue;
        }
        
        // read incoming data
        recv_len = read(client_sockfd, buffer, sizeof(buffer));
        if (recv_len == -1) {
            perror("Failed to read from socket");
            close(client_sockfd);
            continue;
        }
        
        // check if IP address is blocked
        if (is_ip_blocked(inet_ntoa(client_addr.sin_addr))) {
            printf("Blocked IP address: %s\n", inet_ntoa(client_addr.sin_addr));
            close(client_sockfd);
            continue;
        }
        
        // parse IP header
        ip_header = (struct iphdr*)buffer;
        if (ip_header->protocol == IPPROTO_TCP) {
            // parse TCP header
            tcp_header = (struct tcphdr*)(buffer + (ip_header->ihl * 4));
            
            // check for port number
            if (tcp_header->source == htons(80) || tcp_header->dest == htons(80)) {
                printf("Blocked request from IP address: %s\n", inet_ntoa(client_addr.sin_addr));
                block_ip(inet_ntoa(client_addr.sin_addr));
                close(client_sockfd);
                continue;
            }
        }
        
        // forward data to application
        printf("Received data from %s: %s\n", inet_ntoa(client_addr.sin_addr), buffer);
        close(client_sockfd);
    }
    
    return 0;
}

void block_ip(const char* ip_addr) {
    // check if IP address is already blocked
    if (is_ip_blocked(ip_addr)) {
        return;
    }
    
    // add IP address to list of blocked IPs
    int i;
    for (i = 0; i < BLOCKED_IPS_SIZE; i++) {
        if (strlen(blocked_ips[i]) == 0) {
            strncpy(blocked_ips[i], ip_addr, sizeof(blocked_ips[i]) - 1);
            break;
        }
    }
}

int is_ip_blocked(const char* ip_addr) {
    int i;
    for (i = 0; i < BLOCKED_IPS_SIZE; i++) {
        if (strcmp(blocked_ips[i], ip_addr) == 0) {
            return 1;
        }
    }
    return 0;
}