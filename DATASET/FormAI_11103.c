//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ip[16];
    int subnet, oct[4], bit[32], i;
    
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet prefix length: ");
    scanf("%d", &subnet);
    
    sscanf(ip, "%d.%d.%d.%d", &oct[0], &oct[1], &oct[2], &oct[3]);
    
    // calculate subnet mask
    for(i = 0; i < subnet; i++)
    {
        bit[i] = 1;
    }
    
    for(i = subnet; i < 32; i++)
    {
        bit[i] = 0;
    }
    
    printf("\nSubnet mask: %d.%d.%d.%d\n", bit[0]*128 + bit[1]*64 + bit[2]*32 + bit[3]*16 + bit[4]*8 + bit[5]*4 + bit[6]*2 + bit[7],
                                           bit[8]*128 + bit[9]*64 + bit[10]*32 + bit[11]*16 + bit[12]*8 + bit[13]*4 + bit[14]*2 + bit[15],
                                           bit[16]*128 + bit[17]*64 + bit[18]*32 + bit[19]*16 + bit[20]*8 + bit[21]*4 + bit[22]*2 + bit[23],
                                           bit[24]*128 + bit[25]*64 + bit[26]*32 + bit[27]*16 + bit[28]*8 + bit[29]*4 + bit[30]*2 + bit[31]);
    
    // calculate network address
    printf("Network Address: %d.%d.%d.%d\n", oct[0] & bit[0]*128 + bit[1]*64 + bit[2]*32 + bit[3]*16 + bit[4]*8 + bit[5]*4 + bit[6]*2 + bit[7],
                                              oct[1] & bit[8]*128 + bit[9]*64 + bit[10]*32 + bit[11]*16 + bit[12]*8 + bit[13]*4 + bit[14]*2 + bit[15],
                                              oct[2] & bit[16]*128 + bit[17]*64 + bit[18]*32 + bit[19]*16 + bit[20]*8 + bit[21]*4 + bit[22]*2 + bit[23],
                                              oct[3] & bit[24]*128 + bit[25]*64 + bit[26]*32 + bit[27]*16 + bit[28]*8 + bit[29]*4 + bit[30]*2 + bit[31]);
    
    return 0;
}