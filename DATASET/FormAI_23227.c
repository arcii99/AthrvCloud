//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int no_of_bytes, no_of_bits, subnet_bits, no_of_subnets, hosts_per_subnet;
    printf("Enter number of bytes: ");
    scanf("%d", &no_of_bytes);
    // Maximum possible subnet bits is 30 bits
    subnet_bits = 30;
    no_of_bits = no_of_bytes * 8;
    printf("Maximum Subnet Bits: %d\n", subnet_bits);
    printf("No of Bits: %d\n", no_of_bits);
    
    while(1) {
        printf("\nEnter number of subnet bits: ");
        scanf("%d", &subnet_bits);
        if (subnet_bits <=30 && subnet_bits >=0) break;
        printf("Invalid Input. Try Again.\n");
    }
    no_of_subnets = pow(2, subnet_bits);
    hosts_per_subnet = pow(2, (no_of_bits - subnet_bits)) - 2;
    printf("\nNumber of Subnets: %d\n", no_of_subnets);
    printf("Number of Hosts per Subnet: %d\n", hosts_per_subnet);
    return 0;
}