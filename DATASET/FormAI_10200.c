//FormAI DATASET v1.0 Category: Firewall ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>

#define PORT 8080
#define MAX_BUFFER 2048

void block_website(const char *site_ip, const int port)
{
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("Socket connection failed");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(site_ip);

    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        close(sockfd);
        printf("Blocked website with IP address %s:%d\n", site_ip, port);
        exit(0);
    }

    close(sockfd);
}

int main()
{
    int dns_socket, conn_socket;
    char buffer[MAX_BUFFER];
    struct sockaddr_in dns_server_addr, client_addr;
    socklen_t len = sizeof(client_addr);
    memset(&dns_server_addr, 0, sizeof(dns_server_addr));

    // Create socket
    dns_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(dns_socket < 0)
    {
        perror("Socket connection failed");
        exit(1);
    }

    dns_server_addr.sin_family = AF_INET;
    dns_server_addr.sin_addr.s_addr = INADDR_ANY;
    dns_server_addr.sin_port = htons(PORT);

    // Bind socket
    if(bind(dns_socket, (struct sockaddr *)&dns_server_addr, sizeof(dns_server_addr)) < 0)
    {
        perror("Binding error");
        exit(1);
    }

    // Listen for incoming connections
    if(listen(dns_socket, 3) < 0)
    {
        perror("Listening error");
        exit(1);
    }

    while(1)
    {
        // Accept incoming connection
        conn_socket = accept(dns_socket, (struct sockaddr *)&client_addr, &len);
        if(conn_socket < 0)
        {
            perror("Connection error");
            exit(1);
        }

        // Receive DNS query
        memset(buffer, 0, MAX_BUFFER);
        if(recv(conn_socket, buffer, MAX_BUFFER, 0) < 0)
        {
            perror("Receive error");
            exit(1);
        }

        // Parse DNS query
        struct iphdr *ip;
        struct tcphdr *tcp;
        char source_ip[16], dest_ip[16];
        ip = (struct iphdr *)buffer;
        tcp = (struct tcphdr *)(buffer + sizeof(struct iphdr));
        inet_ntop(AF_INET, &(ip->saddr), source_ip, 16);
        inet_ntop(AF_INET, &(ip->daddr), dest_ip, 16);

        // Block website if match found
        if(strcmp(dest_ip, "192.168.1.10") == 0 && ntohs(tcp->dest) == 80)
        {
            block_website("192.168.1.10", 80);
        }

        // Forward DNS query
        send(conn_socket, buffer, MAX_BUFFER, 0);
        close(conn_socket);
    }

    close(dns_socket);
    return 0;
}