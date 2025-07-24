//FormAI DATASET v1.0 Category: Firewall ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65536
#define MAX_RULES 100

struct rule {
    char source_ip[16];
    char destination_ip[16];
    int source_port;
    int destination_port;
    int protocol;
};

struct rule firewall_rules[MAX_RULES];
int num_rules = 0;

void add_firewall_rule(char* source_ip, char* destination_ip, int source_port, int destination_port, int protocol) {
    if (num_rules >= MAX_RULES) {
        printf("Cannot add any more firewall rules.\n");
        return;
    }
    strcpy(firewall_rules[num_rules].source_ip, source_ip);
    strcpy(firewall_rules[num_rules].destination_ip, destination_ip);
    firewall_rules[num_rules].source_port = source_port;
    firewall_rules[num_rules].destination_port = destination_port;
    firewall_rules[num_rules].protocol = protocol;
    num_rules++;
}

int is_allowed(struct iphdr* ip_header, struct tcphdr* tcp_header) {
    char source_ip[16];
    char destination_ip[16];
    strcpy(source_ip, inet_ntoa(*(struct in_addr*)&ip_header->saddr));
    strcpy(destination_ip, inet_ntoa(*(struct in_addr*)&ip_header->daddr));

    for (int i = 0; i < num_rules; i++) {
        struct rule current_rule = firewall_rules[i];
        if (strcmp(current_rule.source_ip, "any") != 0 && strcmp(current_rule.source_ip, source_ip) != 0) {
            continue; //source IP does not match
        }
        if (strcmp(current_rule.destination_ip, "any") != 0 && strcmp(current_rule.destination_ip, destination_ip) != 0) {
            continue; //destination IP does not match
        }
        if (current_rule.source_port != 0 && current_rule.source_port != ntohs(tcp_header->source)) {
            continue; //source port does not match
        }
        if (current_rule.destination_port != 0 && current_rule.destination_port != ntohs(tcp_header->dest)) {
            continue; //destination port does not match
        }
        if (current_rule.protocol != 0 && current_rule.protocol != ip_header->protocol) {
            continue; //protocol does not match
        }
        return 1; //match found, allow packet
    }
    return 0; //no match found, block packet
}

int main() {
    //create a raw socket
    int socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (socket_fd == -1) {
        perror("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    //set socket options to receive all packets
    int sock_opt = 1;
    if (setsockopt(socket_fd, IPPROTO_IP, IP_HDRINCL, &sock_opt, sizeof(sock_opt)) == -1) {
        perror("Error setting socket options\n");
        exit(EXIT_FAILURE);
    }

    //add firewall rules
    add_firewall_rule("192.168.1.100", "192.168.1.200", 0, 80, IPPROTO_TCP);
    add_firewall_rule("any", "192.168.1.50", 0, 0, 0);

    //loop to receive and process packets
    unsigned char buffer[MAX_PACKET_SIZE];
    while (1) {
        int data_size = recv(socket_fd, buffer, MAX_PACKET_SIZE, 0);
        if (data_size < 0) {
            perror("recv error\n");
            exit(EXIT_FAILURE);
        }
        struct iphdr *ip_header = (struct iphdr*)buffer;
        struct tcphdr *tcp_header = (struct tcphdr*)(buffer + sizeof(struct iphdr));
        if (is_allowed(ip_header, tcp_header) == 1) {
            printf("Packet allowed\n");
        }
        else {
            printf("Packet blocked\n");
        }
    }

    return 0;
}