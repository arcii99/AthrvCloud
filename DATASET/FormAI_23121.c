//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
    char ip[12];
    int subnet_mask;
    int octect[4] = {0};
    int i, j, k;

    printf("Enter IP address in dotted decimal notation: ");
    scanf("%s", ip);

    printf("Enter Subnet Mask (1 - 32): ");
    scanf("%d", &subnet_mask);

    // Split IP address into octects
    i = 0;
    j = 0;
    k = 0;
    while (ip[k] != '\0') {
        if (ip[k] == '.') {
            octect[i++] = j;
            j = 0;
        } else {
            j = j * 10 + (int)(ip[k] - '0');
        }
        k++;
    }
    octect[i] = j;
    
    // Calculate number of subnet bits
    int bits = 32 - subnet_mask;
    int subnet_num = pow(2, bits);
    int hosts = pow(2, 8-bits) - 2;

    // Create subnet addresses and broadcast addresses
    int subnet_addrs[subnet_num];
    int broadcast_addrs[subnet_num];
    int increment_factor = pow(2, bits);

    for (i=0; i<subnet_num; i++) {
        subnet_addrs[i] = octect[3] + increment_factor*i;
        broadcast_addrs[i] = subnet_addrs[i] + hosts + 1;
    }

    // Display results
    printf("\n");

    printf("IP address: %s\n", ip);
    printf("Subnet Mask: %d\n", subnet_mask);
    printf("Number of subnet bits: %d\n", bits);
    printf("Total number of subnets: %d\n", subnet_num);
    printf("Total number of hosts per subnet: %d\n", hosts);
    printf("\n");

    for (i=0; i<subnet_num; i++) {
        printf("Subnet %d:\n", i+1);
        printf("  Network Address: %d.%d.%d.%d\n", octect[0], octect[1], octect[2], subnet_addrs[i]);
        printf("  Broadcast Address: %d.%d.%d.%d\n", octect[0], octect[1], octect[2], broadcast_addrs[i]);
        printf("  Usable Host Addresses: %d.%d.%d.%d - %d.%d.%d.%d\n", octect[0], octect[1], octect[2], subnet_addrs[i]+1, octect[0], octect[1], octect[2], broadcast_addrs[i]-1);
        printf("\n");
    }

    return 0;
}