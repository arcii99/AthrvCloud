//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int subnet_bits;
    printf("Enter the number of subnet bits: ");
    scanf("%d",&subnet_bits);

    if(subnet_bits < 1 || subnet_bits > 30)
    {
        printf("Error: Invalid input, number of subnet bits should be between 1 to 30\n");
        exit(0);
    }

    int host_bits = 32 - subnet_bits;

    unsigned long long ip_address;
    printf("Enter the IP address in decimal format (e.g., 192168110): ");
    scanf("%llu",&ip_address);

    unsigned long long subnet_mask = pow(2,32 - subnet_bits) - 1;

    printf("\nSubnet Calculator Results:\n");
    printf("----------------------------------------------------------\n");
    printf("| IP Address:         %llu |\n",ip_address);
    printf("| Subnet Mask:        %llu |\n",subnet_mask << host_bits);
    printf("| Subnet ID:          %llu |\n",ip_address & (subnet_mask << host_bits));
    printf("| Broadcast Address:  %llu |\n",(ip_address & (subnet_mask << host_bits)) | ~((subnet_mask << host_bits)));
    printf("| Total Hosts:        %llu |\n",pow(2,host_bits) - 2);
    printf("----------------------------------------------------------\n");

    return 0;
}