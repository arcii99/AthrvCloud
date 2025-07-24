//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv){
    if(argc != 2){
        printf("Usage: %s <IP Address>/<CIDR>\n", argv[0]);
        return 0;
    }
    
    char *ip_addr = strtok(argv[1], "/");
    char *cidr = strtok(NULL, "/");
    if(cidr == NULL){
        printf("Invalid CIDR mask\n");
        return 0;
    }
    
    struct in_addr ip;
    if(inet_pton(AF_INET, ip_addr, &ip) == 0){
        printf("Invalid IP address\n");
        return 0;
    }
    
    unsigned int prefix = atoi(cidr);
    if(prefix > 32){
        printf("Invalid CIDR mask\n");
        return 0;
    }

    unsigned int mask = 0xffffffff << (32-prefix);
    unsigned int network_ip = ntohl(ip.s_addr) & mask;
    unsigned int broadcast_ip = network_ip | ~mask;
    
    printf("IP Address: %s\n", ip_addr);
    printf("CIDR Mask: /%u\n", prefix);
    printf("Network: %u.%u.%u.%u\n", (network_ip >> 24) & 0xff, (network_ip >> 16) & 0xff,
                                     (network_ip >> 8) & 0xff, network_ip & 0xff);
    printf("Broadcast: %u.%u.%u.%u\n", (broadcast_ip >> 24) & 0xff, (broadcast_ip >> 16) & 0xff,
                                       (broadcast_ip >> 8) & 0xff, broadcast_ip & 0xff);
    printf("Number of Hosts: %d\n", (~mask - 1));
    return 0;
}