//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    unsigned int ip,subnet_bits,subnet_mask,subnet_hosts;
    //IP address in integer format, number of bits to be used for subnetting and subnet mask in integer format
    printf("Enter IP address in decimal format (eg. 192.168.0.1): ");
    scanf("%d",&ip);
    printf("Enter number of bits to be used for subnetting: ");
    scanf("%d",&subnet_bits);
    printf("\nIP address in binary format: ");
    for(int i=31;i>=0;i--)
        printf("%d",(ip>>i)&1);
    printf("\nSubnet mask in binary format: ");
    //Calculating binary value of subnet mask
    for(int i=31;i>=32-subnet_bits;i--)
        subnet_mask|=(1<<i);
    for(int i=31;i>=0;i--)
        printf("%d",(subnet_mask>>i)&1);
    printf("\nNumber of hosts per subnet: %d",(int)pow(2,32-subnet_bits)-2);
    subnet_hosts=pow(2,32-subnet_bits)-2;
    printf("\nNumber of subnets: %d",(int)pow(2,subnet_bits));
    return 0;
}