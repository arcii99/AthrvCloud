//FormAI DATASET v1.0 Category: Firewall ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BLOCKED_IPS 10
#define MAX_PACKET_LEN 65536

struct iphdr* ip_header;
struct tcphdr* tcp_header;

char blocked_ips[BLOCKED_IPS][16] = {
    "10.0.0.1", 
    "192.168.1.1",
    "172.16.0.1",
    "127.0.0.1"
};

int is_blocked_ip(char* ip) {
    for(int i=0; i<BLOCKED_IPS; i++) {
        if(strcmp(blocked_ips[i], ip) == 0) {
            return 1;
        }
    }
    return 0;
}

void process_packet(char* buffer, int len) {
    if(len < sizeof(struct iphdr) + sizeof(struct tcphdr)) {
        printf("Invalid packet\n");
        return;
    }

    ip_header = (struct iphdr*) buffer;
    tcp_header = (struct tcphdr*)(buffer + sizeof(struct iphdr));

    char source_ip[16];
    char dest_ip[16];

    snprintf(source_ip, 16, "%s", inet_ntoa((struct in_addr) {ip_header->saddr}));
    snprintf(dest_ip, 16, "%s", inet_ntoa((struct in_addr) {ip_header->daddr}));

    if(is_blocked_ip(source_ip) || is_blocked_ip(dest_ip)) {
        printf("Blocked IP detected\n");
        return;
    }

    printf("Packet processed successfully\n");
}


int main(int argc, char* argv[]) {

    if(argc < 2) {
        printf("Usage: ./firewall INTERFACE\n");
        return 1;
    }

    int sockfd;
    struct sockaddr_in addr;
    int len;
    char buffer[MAX_PACKET_LEN];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sockfd, (struct sockaddr*) &addr, sizeof(addr)) == -1) {
        perror("Error binding socket");
        close(sockfd);
        return 1;
    }

    int opt_val = 1;
    setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &opt_val, sizeof(int));

    printf("Listening for packets...\n");

    while(1) {
        len = recvfrom(sockfd, buffer, MAX_PACKET_LEN, 0, NULL, NULL);
        if(len < 0) {
            perror("Error receiving packet");
            close(sockfd);
            return 1;
        }
        process_packet(buffer, len);
    }

    close(sockfd);
    return 0;
}