//FormAI DATASET v1.0 Category: Firewall ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

/* Function prototypes */
int checkPacket(unsigned char *, int);
void printPacket(unsigned char *, int);

/* Main function */
int main(int argc, char **argv) {
    int sockfd, buflen;
    unsigned char buffer[65536];

    /* Creating raw socket for IP Protocol */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    /* Receive packets in loop */
    while (1) {
        buflen = recv(sockfd, buffer, sizeof(buffer), 0);
        if (buflen < 0) {
            perror("Error receiving packet");
            exit(EXIT_FAILURE);
        }
        
        /* Check whether packet should be blocked or not */
        if (checkPacket(buffer, buflen)) {
            /* Packet blocked, print it */
            printf("\n\nBlocked packet:\n");
            printPacket(buffer, buflen);
        }
    }

    /* Close raw socket */
    close(sockfd);
    return 0;
}

/* Check packet content and decide if it should be blocked or not */
int checkPacket(unsigned char *buffer, int buflen) {
    /* Extract IP header and TCP header */
    struct iphdr *iph = (struct iphdr *)buffer;
    struct tcphdr *tcph = (struct tcphdr *)(buffer + sizeof(struct iphdr));

    /* Check if packet has TCP protocol and port */
    if (iph->protocol == IPPROTO_TCP && tcph->dest == htons(80)) {
        /* Packet matches the rule, block it */
        return 1;
    }

    /* Packet does not match any rules, allow it */
    return 0;
}

/* Print packet content in hexadecimal format */
void printPacket(unsigned char *buffer, int buflen) {
    int i;

    /* Loop through packet content */
    for (i = 0; i < buflen; i++) {
        /* Print one byte in hexadecimal format */
        printf("%02x ", buffer[i]);
        
        /* Print newline character every 16 bytes */
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    
    /* Print newline character at the end */
    printf("\n");
}