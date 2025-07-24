//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Welcome to the Subnet Calculator Program!\n");
    printf("Enter IP Address (x.x.x.x): ");

    char IP_address[16];
    scanf("%s", IP_address);

    printf("\nEnter Subnet Mask (x.x.x.x): ");

    char subnet_mask[16];
    scanf("%s", subnet_mask);

    int first_octet_IP, second_octet_IP, third_octet_IP, fourth_octet_IP;
    int first_octet_subnet, second_octet_subnet, third_octet_subnet, fourth_octet_subnet;

    sscanf(IP_address, "%d.%d.%d.%d", &first_octet_IP, &second_octet_IP, &third_octet_IP, &fourth_octet_IP);
    sscanf(subnet_mask, "%d.%d.%d.%d", &first_octet_subnet, &second_octet_subnet, &third_octet_subnet, &fourth_octet_subnet);

    // Calculate Subnet Address
    int subnet_address[4];
    subnet_address[0] = first_octet_IP & first_octet_subnet;
    subnet_address[1] = second_octet_IP & second_octet_subnet;
    subnet_address[2] = third_octet_IP & third_octet_subnet;
    subnet_address[3] = fourth_octet_IP & fourth_octet_subnet;

    // Calculate Broadcast Address
    int broadcast_address[4];
    broadcast_address[0] = subnet_address[0] | (255 - first_octet_subnet);
    broadcast_address[1] = subnet_address[1] | (255 - second_octet_subnet);
    broadcast_address[2] = subnet_address[2] | (255 - third_octet_subnet);
    broadcast_address[3] = subnet_address[3] | (255 - fourth_octet_subnet);

    printf("\nSubnet Address: %d.%d.%d.%d\n", subnet_address[0], subnet_address[1], subnet_address[2], subnet_address[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);

    return 0;
}