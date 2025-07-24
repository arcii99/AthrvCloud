//FormAI DATASET v1.0 Category: Firewall ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

/* Define the banned addresses */
char *banned[] = {"10.0.0.2", "192.168.0.1", "172.16.0.5"};

/* The main function */
int main() {
    int sock, optval=1;
    struct sockaddr_in sin;
    struct iphdr *ip_hdr;
    struct tcphdr *tcp_hdr;
    char buf[65535];

    /* Create the socket */
    sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Set the socket options */
    setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(int));

    /* Bind to port 0 */
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(0);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    /* Start receiving packets */
    while (1) {
        int len = sizeof(sin);
        int n = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *) &sin, &len);

        /* Parse the IP header */
        ip_hdr = (struct iphdr *) buf;
        if (ip_hdr->protocol != IPPROTO_TCP)
            continue;

        /* Parse the TCP header */
        tcp_hdr = (struct tcphdr *) (buf + (ip_hdr->ihl << 2));
        if (tcp_hdr->syn && !tcp_hdr->ack) {
            char ip_src[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(ip_hdr->saddr), ip_src, INET_ADDRSTRLEN);

            /* Check if source IP is in our banned list */
            int i;
            for (i = 0; i < 3; i++) {
                if (strcmp(ip_src, banned[i]) == 0) {
                    printf("Blocked %s\n", ip_src);
                    goto blocked;
                }
            }
        }

        /* Forward the packet */
        if (sendto(sock, buf, n, 0, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
            perror("sendto");
        }

        continue;

        /* Handle blocked IP address */
        blocked:
        /* Send reset packet */
        ip_hdr->tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr);
        tcp_hdr->rst = 1;
        tcp_hdr->ack = 1;
        sendto(sock, buf, ntohs(ip_hdr->tot_len), 0, (struct sockaddr *) &sin, sizeof(sin));
    }

    /* We should never get here */
    close(sock);
    return 0;
}