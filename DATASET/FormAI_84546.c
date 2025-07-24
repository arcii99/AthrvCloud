//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>

int main(){
    printf("Welcome to the energetic C Subnet Calculator!\n\n");
    int address[4];
    printf("Please enter the IP address in the format xxx.xxx.xxx.xxx:\n");
    scanf("%d.%d.%d.%d", &address[0], &address[1], &address[2], &address[3]);
    int mask;
    printf("\nPlease enter the subnet mask in CIDR notation (e.g. 24):\n");
    scanf("%d", &mask);
    printf("\nCalculating...\n\n");

    //calculate the subnet address
    unsigned long subnetMask = 0xFFFFFFFF << (32 - mask);
    unsigned long subnetAddress = ((address[0] << 24) + (address[1] << 16) + (address[2] << 8) + (address[3])) & subnetMask;

    //print the subnet address in decimal
    printf("The subnet address is: %d.%d.%d.%d\n", (subnetAddress >> 24) & 0xFF, (subnetAddress >> 16) & 0xFF, (subnetAddress >> 8) & 0xFF, (subnetAddress) & 0xFF);

    //calculate the number of hosts per subnet
    int hosts = 0xFFFFFFFF >> mask;
    printf("The number of hosts per subnet is: %d\n", hosts - 1);

    //calculate the broadcast address
    unsigned long broadcastAddress = subnetAddress | (~subnetMask);
    printf("The broadcast address is: %d.%d.%d.%d\n", (broadcastAddress >> 24) & 0xFF, (broadcastAddress >> 16) & 0xFF, (broadcastAddress >> 8) & 0xFF, (broadcastAddress) & 0xFF);

    //calculate the range of usable IP addresses
    unsigned long firstIP = (subnetAddress + 1) & 0xFFFFFFFF;
    unsigned long lastIP = (broadcastAddress - 1) & 0xFFFFFFFF;
    printf("The usable IP range is: %d.%d.%d.%d to %d.%d.%d.%d\n\n", (firstIP >> 24) & 0xFF, (firstIP >> 16) & 0xFF, (firstIP >> 8) & 0xFF, (firstIP) & 0xFF, (lastIP >> 24) & 0xFF, (lastIP >> 16) & 0xFF, (lastIP >> 8) & 0xFF, (lastIP) & 0xFF);

    printf("Thank you for using the energetic C Subnet Calculator!\n");

    return 0;
}