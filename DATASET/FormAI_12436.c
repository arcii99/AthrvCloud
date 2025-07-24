//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>

void print_packet(const unsigned char* data, int size);

int main(int argc, char** argv) {
    int sockfd;
    char buffer[2048];
    struct sockaddr_in addr;
    socklen_t addr_size;
    int total;
    
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("socket");
        exit(1);
    }
    
    memset((char*) &addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_size = sizeof(addr);
    
    if (bind(sockfd, (struct sockaddr*) &addr, addr_size) < 0) {
        perror("bind");
        exit(1);
    }
    
    while (1) {
        total = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &addr, &addr_size);
        if (total < 0) {
            perror("recvfrom");
            exit(1);
        }
        print_packet(buffer, total);
    }
    return 0;
}

void print_packet(const unsigned char* data, int size) {
    struct iphdr* iph;
    struct tcphdr* tcph;
    struct sockaddr_in src_addr, dst_addr;
    
    iph = (struct iphdr*) data;
    memset(&src_addr, 0, sizeof(src_addr));
    src_addr.sin_addr.s_addr = iph->saddr;
    memset(&dst_addr, 0, sizeof(dst_addr));
    dst_addr.sin_addr.s_addr = iph->daddr;
    
    if (iph->protocol != IPPROTO_TCP) {
        fprintf(stdout, "Non-TCP Packet: ");
    }
    else {
        tcph = (struct tcphdr*) (data + sizeof(struct iphdr));
        
        fprintf(stdout, "\n---------------TCP Packet Starts-------------\n");
        fprintf(stdout, "Source IP Address: %s\n", inet_ntoa(src_addr.sin_addr));
        fprintf(stdout, "Destination IP Address: %s\n", inet_ntoa(dst_addr.sin_addr));
        fprintf(stdout, "Source Port Number: %d\n", ntohs(tcph->source));
        fprintf(stdout, "Destination Port Number: %d\n", ntohs(tcph->dest));
        fprintf(stdout, "TCP Flags: %x\n", tcph->th_flags);
        fprintf(stdout, "TCP Data: \n");
        for (int i = 0; i < size; i++) {
            fprintf(stdout, "%02x ", data[i]);
            if ((i + 1) % 16 == 0) {
                fprintf(stdout, "\n");
            }
        }
        fprintf(stdout, "\n---------------TCP Packet Ends---------------\n");
    }
    fflush(stdout);
}