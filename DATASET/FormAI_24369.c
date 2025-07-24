//FormAI DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <signal.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

typedef struct FirewallRule {
    char* source_ip;
    char* destination_ip;
    int source_port;
    int destination_port;
} FirewallRule;

FirewallRule firewall_rules[10];

int rule_count = 0;

void handle_sigint(int sig) {
    printf("\nExiting...\n");
    exit(0);
}

void add_rule(char* source_ip, char* destination_ip, int source_port, int destination_port) {
    FirewallRule rule;
    rule.source_ip = source_ip;
    rule.destination_ip = destination_ip;
    rule.source_port = source_port;
    rule.destination_port = destination_port;

    firewall_rules[rule_count] = rule;
    rule_count++;
}

int check_if_packet_matches_rule(FirewallRule rule, struct iphdr* ip_header, int header_length) {
    struct sockaddr_in source, dest;
    memset(&source, 0, sizeof(source));
    memset(&dest, 0, sizeof(dest));
    source.sin_addr.s_addr = ip_header->saddr;
    dest.sin_addr.s_addr = ip_header->daddr;

    int source_port = 0;
    int destination_port = 0;
    int protocol = ip_header->protocol;
    if (protocol == IPPROTO_TCP) {
        struct tcphdr* tcp_header = (struct tcphdr*)((char*)ip_header + header_length);
        source_port = ntohs(tcp_header->source);
        destination_port = ntohs(tcp_header->dest);
    } else if (protocol == IPPROTO_UDP) {
        struct udphdr* udp_header = (struct udphdr*)((char*)ip_header + header_length);
        source_port = ntohs(udp_header->source);
        destination_port = ntohs(udp_header->dest);
    }

    if (strcmp(rule.source_ip, "any") != 0 && strcmp(inet_ntoa(source.sin_addr), rule.source_ip) != 0) {
        return 0;
    }
    if (strcmp(rule.destination_ip, "any") != 0 && strcmp(inet_ntoa(dest.sin_addr), rule.destination_ip) != 0) {
        return 0;
    }
    if (rule.source_port != 0 && source_port != rule.source_port) {
        return 0;
    }
    if (rule.destination_port != 0 && destination_port != rule.destination_port) {
        return 0;
    }

    return 1;
}

int check_if_packet_is_allowed(struct iphdr* ip_header, int header_length) {
    for (int i = 0; i < rule_count; i++) {
        FirewallRule rule = firewall_rules[i];
        if (check_if_packet_matches_rule(rule, ip_header, header_length)) {
            return 1;
        }
    }

    return 0;
}

void handle_packet(char* buffer, int size) {
    struct iphdr* ip_header = (struct iphdr*)buffer;
    int header_length = ip_header->ihl * 4;

    if (check_if_packet_is_allowed(ip_header, header_length)) {
        printf("Packet allowed.\n");
    } else {
        printf("Packet blocked.\n");
    }
}

int main() {
    printf("Starting firewall...\n");

    signal(SIGINT, handle_sigint);

    add_rule("any", "any", 0, 80);
    add_rule("192.168.1.10", "any", 0, 0);

    int sockfd, new_socket;
    struct sockaddr_in server_address, client_address;
    int client_address_length = sizeof(client_address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");

    // Accept incoming connections
    if ((new_socket = accept(sockfd, (struct sockaddr *)&client_address, (socklen_t*)&client_address_length))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Read data from client
    int valread = read(new_socket, buffer, BUFFER_SIZE);
    handle_packet(buffer, valread);

    close(new_socket);
    close(sockfd);

    return 0;
}