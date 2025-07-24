//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ip[15], mask[15];
    int ip_arr[4], mask_arr[4], subnet_mask_bits, subnet_mask_int;
    char subnet_mask[15];
    printf("Enter IP address in dot notation: ");
    scanf("%s", ip);
    printf("Enter subnet mask in dot notation: ");
    scanf("%s", mask);
    //parse ip into integer array
    char *token = strtok(ip, ".");
    int i = 0;
    while(token != NULL)
    {
        ip_arr[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
    //parse mask into integer array
    token = strtok(mask, ".");
    i = 0;
    while(token != NULL)
    {
        mask_arr[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
    //calculate subnet mask in bits
    subnet_mask_bits = mask_arr[0] * 256 * 256 * 256 + mask_arr[1] * 256 * 256 + mask_arr[2] * 256 + mask_arr[3];
    //calculate subnet mask in dot notation
    subnet_mask_int = 0xffffffff << (32 - subnet_mask_bits);
    sprintf(subnet_mask, "%d.%d.%d.%d", (subnet_mask_int >> 24) & 0xff, (subnet_mask_int >> 16) & 0xff, (subnet_mask_int >> 8) & 0xff, subnet_mask_int & 0xff);
    //print results
    printf("IP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);
    printf("Subnet mask (bits): %d\n", subnet_mask_bits);
    printf("Subnet mask (dot notation): %s\n", subnet_mask);
    return 0;
}