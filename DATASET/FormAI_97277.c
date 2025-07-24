//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[16], subnet_mask[16];
    int subnet_bits;
    
    printf("Enter IP address: ");
    scanf("%s", ip);
    
    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);
    
    printf("Enter number of subnet bits: ");
    scanf("%d", &subnet_bits);
    
    // convert IP address to binary
    char *ptr = strtok(ip, ".");
    int ip_parts[4], i = 0;
    while (ptr != NULL) {
        ip_parts[i] = atoi(ptr);
        ptr = strtok(NULL, ".");
        i++;
    }
    unsigned long long int ip_address = (ip_parts[0] * 16777216) + (ip_parts[1] * 65536) + (ip_parts[2] * 256) + ip_parts[3];
    
    // convert subnet mask to binary
    ptr = strtok(subnet_mask, ".");
    int mask_parts[4];
    i = 0;
    while (ptr != NULL) {
        mask_parts[i] = atoi(ptr);
        ptr = strtok(NULL, ".");
        i++;
    }
    unsigned long long int subnet_mask_bin = (mask_parts[0] * 16777216) + (mask_parts[1] * 65536) + (mask_parts[2] * 256) + mask_parts[3];
    
    // calculate network and broadcast addresses
    unsigned long long int network_address = ip_address & subnet_mask_bin;
    unsigned long long int max_hosts = pow(2, (32 - subnet_bits)) - 2;
    unsigned long long int broadcast_address = network_address + max_hosts + 1;
    
    // print results
    printf("\n\nNetwork address: %d.%d.%d.%d", (int)(network_address / 16777216), (int)((network_address % 16777216) / 65536), (int)((network_address % 65536) / 256), (int)(network_address % 256));
    printf("\nBroadcast address: %d.%d.%d.%d", (int)(broadcast_address / 16777216), (int)((broadcast_address % 16777216) / 65536), (int)((broadcast_address % 65536) / 256), (int)(broadcast_address % 256));
    printf("\nNumber of valid host addresses per subnet: %llu\n", max_hosts);
    
    return 0;
}