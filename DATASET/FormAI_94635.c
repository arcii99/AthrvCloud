//FormAI DATASET v1.0 Category: Firewall ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

int main() {
    int sock, bytes_received;
    struct sockaddr_in host_addr;
    char buffer[4096], source_ip[16];
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;
    const char *firewall_rule = "DENY";

    sock = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("Socket error");
        return 1;
    }

    while (1) {
        memset(buffer, 0, 4096);
        bytes_received = recv(sock, buffer, 4096, 0);

        if (bytes_received < 0) {
            perror("recv error");
            return 1;
        }

        ip_header = (struct iphdr*)(buffer);
        tcp_header = (struct tcphdr*)(buffer + (ip_header->ihl * 4));
        strcpy(source_ip, inet_ntoa((struct in_addr){ip_header->saddr}));

        if (tcp_header->dest == htons(80)) {
            if (strcmp(source_ip, "192.168.0.1") == 0) {
                printf("ALLOWED - connection from trusted IP\n");
            } else {
                printf("BLOCKED - connection from unknown IP\n");
                if (strcmp(firewall_rule, "DENY") == 0) {
                    continue;
                } else {
                    printf("WARNING - unhandled firewall rule\n");
                    continue;
                }
            }
        } else {
            printf("ALLOWED - not a HTTP connection\n");
        }
    }

    close(sock);
    return 0;
}