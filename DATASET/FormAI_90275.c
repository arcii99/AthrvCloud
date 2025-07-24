//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    unsigned int n1, n2, n3, n4, mask;
    printf("Enter IP Address (in format x.x.x.x): ");
    scanf("%d.%d.%d.%d", &n1, &n2, &n3, &n4);
    printf("Enter Subnet Mask (in format /n): ");
    scanf("%d", &mask);

    unsigned int subnet_octects, host_octects;
    unsigned long num_subnet, num_hosts;
    unsigned long max_subnet_hosts;

    subnet_octects = mask / 8;
    host_octects = 4 - subnet_octects;

    num_subnet = pow(2, mask % 8) - 1;
    max_subnet_hosts = pow(2, 8 - mask % 8) - 2;
    num_hosts = pow(2, 8 * host_octects) - 2;

    printf("Subnet Mask: %d.%d.%d.%d/%d\n", (255 << (8 - (mask % 8))) & 255, (255 << (8 - (mask % 8))) & 255, (255 << (8 - (mask % 8))) & 255, (255 << (8 - (mask % 8))) & 255, mask);
    printf("Number of subnets: %lu\n", num_subnet);
    printf("Number of hosts per subnet: %lu\n", max_subnet_hosts);
    printf("Total number of hosts: %lu\n", num_hosts);
    printf("Range of IP addresses: ");
    printf("%d.%d.%d.%d - ", n1 & (255 << (8 - (mask % 8))), n2, n3, n4);
    printf("%d.%d.%d.%d\n", n1 | (~ (255 << (8 - (mask % 8))) & 255), n2 | (~0 & 255), n3 | (~0 & 255), n4 | (~0 & 255));
  
    return 0;
}