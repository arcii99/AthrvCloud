//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>

unsigned long int power(int base, int expo) {
    if(expo == 0) {
        return 1;
    } else {
        return base * power(base, expo-1);
    }
}

int main() {
    int CIDR;
    printf("Please enter the CIDR notation:\n");
    scanf("%d", &CIDR);

    int subnet_bits = 32 - CIDR;
    int no_of_subnets = power(2, subnet_bits);
    int no_of_hosts = power(2, CIDR - 24);

    printf("Subnet Mask: 255.255.255.%d\n", 256 - no_of_hosts);
    printf("No. of subnets: %d\n", no_of_subnets);
    printf("No. of hosts per subnet: %d\n", no_of_hosts - 2);
}