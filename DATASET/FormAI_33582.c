//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_IP_OCTETS 4
#define BITS_IN_OCTET 8

int determine_subnet_mask(unsigned int num_hosts){
    int log_of_hosts = ceil(log2(num_hosts+2)); //calculate log base 2
    int num_bits_to_mask = BITS_IN_OCTET - log_of_hosts;
    return 255 - pow(2, num_bits_to_mask) + 1; //create subnet mask
}

int main(){
    unsigned int num_hosts;
    unsigned int ip_octets[MAX_IP_OCTETS];
    char c;

    //input IP address
    printf("Enter IP address in the format x.x.x.x: ");
    scanf("%u%c%u%c%u%c%u",&ip_octets[0], &c, &ip_octets[1], &c, &ip_octets[2], &c, &ip_octets[3]);
    
    //input number of hosts
    printf("Enter number of hosts needed: ");
    scanf("%u", &num_hosts);

    //calculate subnet mask
    int subnet_mask = determine_subnet_mask(num_hosts);
    
    //output calculated subnet mask
    printf("Calculated Subnet Mask: 255.255.255.%d\n", subnet_mask);

    return 0;
}