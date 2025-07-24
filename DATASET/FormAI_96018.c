//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

int main() {
    int ip_address[4], subnet_mask, address_bits;
    printf("Enter IP address in dotted decimal notation (e.g. 192.168.0.1): ");
    scanf("%d.%d.%d.%d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);
    printf("Enter subnet mask in CIDR notation (e.g. 24 for 255.255.255.0): ");
    scanf("%d", &subnet_mask);
    address_bits = 32 - subnet_mask;
    int num_of_hosts = pow(2, address_bits) - 2;
    printf("IP Address: %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", (int)pow(2, (int)(subnet_mask/8)) - 1, (int)pow(2, (int)(subnet_mask/8)), (int)pow(2, (int)(subnet_mask/8)) - 1, (int)pow(2, (int)(subnet_mask%8)) - 1);
    printf("Number of addressable hosts in subnet: %d\n", num_of_hosts);

    printf("\nConnecting to the Neuralink chip and running a scan for subnet minions...\n");
    printf("Scanning...\n");
    for(int i=0; i<num_of_hosts; i++) {
        printf("Host %d scanned.\n", i+1);
        if(i%5 == 0) {
            printf("Encrypting data packets and deflecting incoming counter-attacks...\n");
        }
    }

    printf("\nAll hosts are now secure against cyber attacks!\n");
    return 0;
}