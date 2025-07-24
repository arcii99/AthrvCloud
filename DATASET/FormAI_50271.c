//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int octet1, octet2, octet3, octet4;
    int mask_octet1, mask_octet2, mask_octet3, mask_octet4;
    int network_octet1, network_octet2, network_octet3, network_octet4;
    int host_octet1, host_octet2, host_octet3, host_octet4;
    int subnet_bits, subnet_mask;
    
    printf("Welcome to the C Subnet Calculator!\n\n");
    
    //Read in the IP address from the user
    printf("Please enter the IP address (in the format x.x.x.x): ");
    scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
    
    //Read in the subnet mask from the user
    printf("Please enter the subnet mask (in the format x.x.x.x): ");
    scanf("%d.%d.%d.%d", &mask_octet1, &mask_octet2, &mask_octet3, &mask_octet4);
    
    //Calculate the subnet mask in bits
    subnet_mask = mask_octet1 * 256 * 256 * 256 + mask_octet2 * 256 * 256 + mask_octet3 * 256 + mask_octet4;
    subnet_bits = 0;
    while(subnet_mask > 0) {
        subnet_bits++;
        subnet_mask = subnet_mask >> 1;
    }
    
    //Calculate the network and host portions of the IP address
    network_octet1 = octet1 & mask_octet1;
    network_octet2 = octet2 & mask_octet2;
    network_octet3 = octet3 & mask_octet3;
    network_octet4 = octet4 & mask_octet4;
    
    host_octet1 = octet1 & (~mask_octet1);
    host_octet2 = octet2 & (~mask_octet2);
    host_octet3 = octet3 & (~mask_octet3);
    host_octet4 = octet4 & (~mask_octet4);
    
    //Print the results
    printf("\nNetwork Address: %d.%d.%d.%d\n", network_octet1, network_octet2, network_octet3, network_octet4);
    printf("Host Address Range: %d.%d.%d.%d - %d.%d.%d.%d\n", network_octet1, network_octet2, network_octet3, network_octet4 + 1, network_octet1 + (~mask_octet1), network_octet2 + (~mask_octet2), network_octet3 + (~mask_octet3), network_octet4 + (~mask_octet4));
    printf("Subnet Mask: %d.%d.%d.%d\n", mask_octet1, mask_octet2, mask_octet3, mask_octet4);
    printf("Subnet Bits: /%d\n", subnet_bits);
    
    return 0;
}