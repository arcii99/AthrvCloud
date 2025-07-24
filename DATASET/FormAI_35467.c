//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include<stdio.h>
#include<math.h>

int main()
{
    int ip_1, ip_2, ip_3, ip_4, subnet_mask, subnet_bits, subnets, hosts;
    int bin_mask_1, bin_mask_2, bin_mask_3, bin_mask_4;
    int i = 0, subnets_possible = 0, mask_sum = 0, new_subnet_bits = 0;

    printf("Enter the IP address (format: xxx.xxx.xxx.xxx): ");
    scanf("%d.%d.%d.%d", &ip_1, &ip_2, &ip_3, &ip_4);
    
    printf("Enter the subnet mask prefix (i.e., number of bits): ");
    scanf("%d", &subnet_bits);

    // Calculating the subnet mask.
    for(i = 0; i < subnet_bits; i++) {
        if(i < 8) {
            bin_mask_1 += pow(2, 7 - i);
        } else if(i < 16) {
            bin_mask_2 += pow(2, 15 - i);
        } else if(i < 24) {
            bin_mask_3 += pow(2, 23 - i);
        } else {
            bin_mask_4 += pow(2, 31 - i);
        }
    }
    
    printf("Binary subnet mask: %d.%d.%d.%d\n", bin_mask_1, bin_mask_2, bin_mask_3, bin_mask_4);

    // Counting the number of subnets using the given subnet mask prefix.   
    subnets_possible = pow(2, (32 - subnet_bits));
    printf("Number of possible subnets: %d\n", subnets_possible);

    // Taking input the number of subnets required.
    printf("Enter the number of subnets required: ");
    scanf("%d", &subnets);
    
    // Calculating the number of bits required to get the specified number of subnets.
    while(1) {
        new_subnet_bits++;
        if(pow(2, new_subnet_bits) >= subnets + subnets_possible) {
            break;
        }
    }
    
    // Calculating the new subnet mask.
    for(i = 0; i < new_subnet_bits; i++) {
        if(i < 8) {
            bin_mask_1 += pow(2, 7 - i);
        } else if(i < 16) {
            bin_mask_2 += pow(2, 15 - i);
        } else if(i < 24) {
            bin_mask_3 += pow(2, 23 - i);
        } else {
            bin_mask_4 += pow(2, 31 - i);
        }
    }
    
    printf("New binary subnet mask: %d.%d.%d.%d\n", bin_mask_1, bin_mask_2, bin_mask_3, bin_mask_4);
    
    // Calculating the number of hosts per subnet.
    hosts = pow(2, (32 - subnet_bits - new_subnet_bits));
    printf("Number of hosts per subnet: %d\n", hosts);
    
    // Calculating the total number of subnets with the new subnet mask prefix.
    for(i = subnet_bits + new_subnet_bits; i < 32; i++) {
        mask_sum += pow(2, 31 - i);
    }
    printf("Total number of subnets: %d\n", subnets_possible + subnets);

    return 0;
}