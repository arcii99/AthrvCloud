//FormAI DATASET v1.0 Category: Firewall ; Style: grateful
/* Welcome to the Great Firewall of China! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BLOCKED_PORT 80
#define RESPONSE "HTTP/1.1 404 Not Found\r\n\r\n"

int main()
{
    /* Open a raw socket */
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }
    
    /* Bind the socket to the loopback address */
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }
    
    printf("The Great Firewall of China is up and running!\n");
    printf("Blocking all incoming traffic on port %d\n", BLOCKED_PORT);
    
    /* Listen for incoming packets */
    char buf[1024];
    while (1) {
        ssize_t n = recv(sock, buf, sizeof(buf), 0);
        if (n < 0) {
            perror("recv");
            continue;
        }
        
        /* Parse the IP and TCP headers */
        struct iphdr *ip = (struct iphdr *)buf;
        struct tcphdr *tcp = (struct tcphdr *)(buf + ip->ihl * 4);
        
        /* Check if the packet is coming in on the blocked port */
        if (ntohs(tcp->th_dport) == BLOCKED_PORT) {
            printf("Blocked incoming traffic on port %d from %d.%d.%d.%d\n", BLOCKED_PORT,
                   (ip->saddr >> 24) & 0xff, (ip->saddr >> 16) & 0xff,
                   (ip->saddr >> 8) & 0xff, ip->saddr & 0xff);
            
            /* Send a 404 response to the client */
            struct sockaddr_in client;
            memset(&client, 0, sizeof(client));
            client.sin_family = AF_INET;
            client.sin_addr.s_addr = ip->saddr;
            client.sin_port = tcp->th_sport;
            sendto(sock, RESPONSE, strlen(RESPONSE), 0,
                   (struct sockaddr *)&client, sizeof(client));
        }
    }
    
    return 0;
}