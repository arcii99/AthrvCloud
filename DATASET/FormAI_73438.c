//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int choice, subnetBits;
    unsigned int mask, address, subnet, hosts;
    printf("Welcome to the post-apocalyptic subnet calculator!\n");
    while(1)
    {
        printf("Enter your choice: \n1. Calculate subnet mask\n2. Calculate subnet address\n3. Calculate maximum number of hosts per subnet\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the number of bits in the subnet mask: ");
                scanf("%d", &subnetBits);
                if(subnetBits>=32 || subnetBits<=0)
                {
                    printf("Invalid subnet mask length!\n");
                }
                else
                {
                    mask = pow(2, 32-subnetBits)-1;
                    printf("Subnet mask (in decimal) is: %d.%d.%d.%d\n", (mask>>24)&0xff, (mask>>16)&0xff, (mask>>8)&0xff, mask&0xff);
                }
                break;
            case 2:
                printf("Enter the IP address in decimal (example: 192.168.0.1): ");
                scanf("%u", &address);
                printf("Enter the number of bits in the subnet mask: ");
                scanf("%d", &subnetBits);
                if(subnetBits>=32 || subnetBits<=0)
                {
                    printf("Invalid subnet mask length!\n");
                }
                else
                {
                    mask = pow(2, 32-subnetBits)-1;
                    subnet = address & mask;
                    printf("Subnet address is (in decimal): %d.%d.%d.%d\n", (subnet>>24)&0xff, (subnet>>16)&0xff, (subnet>>8)&0xff, subnet&0xff);
                }
                break;
            case 3:
                printf("Enter the number of bits in the subnet mask: ");
                scanf("%d", &subnetBits);
                if(subnetBits>=32 || subnetBits<=0)
                {
                    printf("Invalid subnet mask length!\n");
                }
                else
                {
                    mask = pow(2, 32-subnetBits)-1;
                    hosts = pow(2, 32-subnetBits)-2;
                    printf("Maximum number of hosts per subnet: %u\n", hosts);
                }
                break;
            case 4:
                printf("Goodbye, and good luck surviving the apocalypse!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}