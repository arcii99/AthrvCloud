//FormAI DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/* Define the maximum number of IP addresses */
#define MAX_IP_ADDRESSES 100

int main()
{
    int i, j;
    char ip_address[50];
    char allowed_ips[][50] = {"192.168.0.1", "10.0.0.1", "172.16.3.4", "192.168.1.100"};

    printf("Enter IP address to check against firewall: ");
    scanf("%s", ip_address);

    /* Loop through all allowed IP addresses and check if the entered IP is valid */
    for(i = 0; i < MAX_IP_ADDRESSES; i++)
    {
        if(strcmp(ip_address, allowed_ips[i]) == 0)
        {
            printf("IP address %s is allowed.\n", ip_address);
            return 0;
        }
    }

    /* If the IP address is not allowed, print an error message */
    printf("IP address %s is not allowed.\n", ip_address);

    return 0;
}