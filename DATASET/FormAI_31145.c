//FormAI DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s hostname/ip-address\n", argv[0]);
        return 1;
    }
    char *ip_address;
    struct hostent *host_entry = gethostbyname(argv[1]);
    if (host_entry == NULL) {
        printf("Unable to resolve the hostname\n");
        return 1;
    }
    ip_address = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0]));
    printf("IP Address: %s\n", ip_address);
    int sockfd;
    struct sockaddr_in target_addr;
    socklen_t addr_size = sizeof(target_addr);
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(0);
    target_addr.sin_addr.s_addr = inet_addr(ip_address);
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }
    int port_range[] = {22, 80, 443};
    int num_ports = sizeof(port_range) / sizeof(int);
    printf("Scanning target with IP address %s...\n", ip_address);
    for (int i = 0; i < num_ports; i++) {
        target_addr.sin_port = htons(port_range[i]);
        if (connect(sockfd, (struct sockaddr*)&target_addr, addr_size) == 0) {
            printf("Port %d is open\n", port_range[i]);
        } else {
            printf("Port %d is closed\n", port_range[i]);
        }
    }
    close(sockfd);
    printf("Scanning completed\n");
    return 0;
}