//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <math.h>

int main() {
    int subnet_mask, bits, num_of_subnets, num_of_hosts;
    int a, b, c, d;
    char choice;
    
    printf("Welcome to the C Subnet Calculator!\n");
    
    do {
        printf("\nEnter the IP address in the format A.B.C.D: ");
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        printf("Enter the subnet mask in CIDR notation: ");
        scanf("%d", &bits);
        
        num_of_subnets = pow(2, (bits - 24));
        num_of_hosts = pow(2, (32 - bits)) - 2;
        subnet_mask = pow(2, (32 - bits)) - 1;
        
        printf("\n==================\n");
        printf("Subnet Information:\n");
        printf("==================\n\n");
        printf("IP Address: %d.%d.%d.%d\n", a, b, c, d);
        printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask >> 24 & 0xff, subnet_mask >> 16 & 0xff, subnet_mask >> 8 & 0xff, subnet_mask & 0xff);
        printf("Number of Subnets: %d\n", num_of_subnets);
        printf("Number of Hosts: %d\n", num_of_hosts);
        
        printf("\nDo you want to calculate another subnet? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("\nThank you for using the C Subnet Calculator!\n");
    
    return 0;
}