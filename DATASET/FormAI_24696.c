//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define ADDR_SIZE 16 //the maximum size of an IPv4 address

int main(int argc, char *argv[]) {
    char ip[ADDR_SIZE] = {0};
    int prefix_len, cidr_mask;
    
    //Read the IP address and prefix length from the user
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter prefix length: ");
    scanf("%d", &prefix_len);
    
    //Calculate the subnet mask using the prefix length
    cidr_mask = (0xFFFFFFFF << (32 - prefix_len)) & 0xFFFFFFFF;
    
    struct in_addr addr;
    inet_pton(AF_INET, ip, &addr); //convert the IP address string to a binary format
    
    unsigned int net_addr = ntohl(addr.s_addr) & cidr_mask; //calculate the network address
    
    //Print the network address and subnet mask
    printf("Network Address: %s\n", inet_ntoa((struct in_addr){htonl(net_addr)}));
    printf("Subnet Mask: %s\n", inet_ntoa((struct in_addr){htonl(cidr_mask)}));
    
    return 0;
}