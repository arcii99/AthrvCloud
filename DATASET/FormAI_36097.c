//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ERRBUF_SIZE 1024
#define BUF_SIZE 64

char *IP;

void usage(char *filename) {
    printf("Usage: %s <ip_address> <subnet_mask>\n", filename);
    printf("Example: %s 192.168.1.1 24\n", filename);
}

void validate_input(char *ip_address, char *subnet_mask) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
    if (result != 1) {
        printf("Invalid IP address: %s\n", ip_address);
        exit(1);
    }
    if (!isdigit(subnet_mask[0])) {
        printf("Invalid subnet mask: %s\n", subnet_mask);
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    IP = argv[1];
    char *subnet_mask_str = argv[2];
    validate_input(IP, subnet_mask_str);
    
    int subnet_mask = atoi(subnet_mask_str);
    int num_hosts = pow(2, 32 - subnet_mask) - 2;
    int num_subnets = pow(2, subnet_mask);

    // calculate network address
    struct in_addr ip_addr;
    inet_aton(IP, &ip_addr);
    uint32_t ip = ntohl(ip_addr.s_addr);
    uint32_t network_address = ip & ~(num_subnets - 1);

    // calculate broadcast address
    uint32_t broadcast_address = network_address | (num_subnets - 1);

    // print results
    printf("\nIP Address:\t%s\n", IP);
    printf("Subnet Mask:\t%s\n", subnet_mask_str);
    printf("Network Address:\t%s\n", inet_ntoa(*(struct in_addr *)&network_address));
    printf("Broadcast Address:\t%s\n", inet_ntoa(*(struct in_addr *)&broadcast_address));
    printf("Number of Hosts:\t%d\n", num_hosts);
    printf("Number of Subnets:\t%d\n\n", num_subnets);

    return 0;
}