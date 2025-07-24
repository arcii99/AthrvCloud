//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_BUFFER_SIZE     65536   // Maximum size of the buffer
#define MAX_TCP_PACK_SIZE   256     // Maximum size of the TCP package

// Function to print the error message and exit
void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

// Function to calculate the checksum of the TCP package
unsigned short csum(unsigned short *buf, int nwords) {
    unsigned long sum;
    for(sum=0; nwords>0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum &0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

// The main function of the program
int main(int argc, char *argv[]) {
    if(argc != 2) {     // Check if the user provided the IP address
        fprintf(stderr, "Usage: %s IP_ADDRESS\n", argv[0]);
        exit(1);
    }

    // Create a raw socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sockfd < 0)
        error("Failed to create socket");

    // Enable IP_HDRINCL option
    int one = 1;
    const int *val = &one;
    if(setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0)
        error("Error setting IP_HDRINCL option");

    // Set the IP header parameters
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(80);
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Set the TCP header parameters
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    struct iphdr *ip = (struct iphdr *) buffer;
    struct tcphdr *tcp = (struct tcphdr *) (buffer + sizeof(struct iphdr));

    ip->ihl = 5;
    ip->version = 4;
    ip->tos = 0;
    ip->tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr);
    ip->id = htonl(54321);
    ip->frag_off = 0;
    ip->ttl = 255;
    ip->protocol = IPPROTO_TCP;
    ip->check = 0;
    ip->saddr = inet_addr("1.2.3.4");
    ip->daddr = dest_addr.sin_addr.s_addr;

    tcp->source = htons(1234);
    tcp->dest = htons(80);
    tcp->seq = 0;
    tcp->ack_seq = 0;
    tcp->doff = 5;
    tcp->syn = 1;
    tcp->window = htons(5840);
    tcp->check = 0;
    tcp->urg_ptr = 0;

    // Send the TCP SYN packet
    int res;
    while(1) {
        if(sendto(sockfd, buffer, ip->tot_len, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0)
            error("Error sending packet");
        else
            printf("Packet sent successfully\n");

        // Wait for the response packet
        char res_buffer[MAX_TCP_PACK_SIZE];
        memset(res_buffer, 0, MAX_TCP_PACK_SIZE);
        struct sockaddr_in res_addr;
        int res_addr_len = sizeof(res_addr);
        if(recvfrom(sockfd, res_buffer, MAX_TCP_PACK_SIZE, 0, (struct sockaddr *)&res_addr, &res_addr_len) < 0)
            error("Error receiving packet");
        else
            printf("Packet received successfully\n");

        // Parse the response packet
        struct iphdr *res_ip = (struct iphdr *) res_buffer;
        struct tcphdr *res_tcp = (struct tcphdr *) (res_buffer + sizeof(struct iphdr));
        if(res_tcp->syn && res_tcp->ack && res_tcp->ack_seq == tcp->seq + 1) {
            printf("Connection established\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}