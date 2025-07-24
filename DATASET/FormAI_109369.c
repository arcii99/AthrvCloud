//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char ip[20];
    printf("Enter an IP address: ");
    scanf("%s",ip);

    char mask[5];
    printf("Enter the subnet mask prefix (e.g. 24): ");
    scanf("%s",mask);

    int subnet_size = 32 - atoi(mask);

    char *token;
    int octets[4];
    int i = 0;

    token = strtok(ip,".");
    while(token != NULL){
        octets[i++] = atoi(token);
        token = strtok(NULL,".");
    }

    int subnet_mask = 0;
    for(i=0; i<subnet_size; i++){
        subnet_mask |= (1<<i);
    }

    int network_address = (octets[0]<<24) | (octets[1]<<16) | (octets[2]<<8) | octets[3];
    int subnet_address = network_address & (subnet_mask<<subnet_size);
    int usable_hosts = (subnet_mask) - 1;

    printf("\nIP Address: %s", ip);
    printf("\nSubnet Mask: %s", mask);
    printf("\nSubnet Size: /%d", 32- subnet_size);
    printf("\nSubnet Mask: %d.%d.%d.%d", subnet_mask>>24, (subnet_mask>>16) & 0xff, (subnet_mask>>8) & 0xff, subnet_mask & 0xff);
    printf("\nNetwork Address: %d.%d.%d.%d", network_address>>24, (network_address>>16) & 0xff, (network_address>>8) & 0xff, network_address & 0xff);
    printf("\nSubnet Address: %d.%d.%d.%d", subnet_address>>24, (subnet_address>>16) & 0xff, (subnet_address>>8) & 0xff, subnet_address & 0xff);
    printf("\nUsable Hosts: %d", usable_hosts);

    return 0;
}