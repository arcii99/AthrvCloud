//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include<stdio.h>

int main()
{
    int ipAddress[4], subnetMask[4],networkAddress[4],i;
    printf("Enter the IP Address: ");
    scanf("%d.%d.%d.%d",&ipAddress[0],&ipAddress[1],&ipAddress[2],&ipAddress[3]);
    printf("Enter the Subnet Mask: ");
    scanf("%d.%d.%d.%d",&subnetMask[0],&subnetMask[1],&subnetMask[2],&subnetMask[3]);
    for(i=0;i<4;i++)
    {
        networkAddress[i] = ipAddress[i] & subnetMask[i];
    }
    printf("The Network Address is: %d.%d.%d.%d\n",networkAddress[0],networkAddress[1],networkAddress[2],networkAddress[3]);
    
    return 0;
}