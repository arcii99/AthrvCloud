//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char ip[16];
    int subnet_mask,subnet_bits;
    int octect_1,octect_2,octect_3,octect_4;
    int merge;

    printf("Enter IP Address: ");
    scanf("%s",ip);

    printf("Enter Subnet Mask: ");
    scanf("%d",&subnet_mask);

    octect_1 = atoi(strtok(ip,"."));
    octect_2 = atoi(strtok(NULL,"."));
    octect_3 = atoi(strtok(NULL,"."));
    octect_4 = atoi(strtok(NULL,"."));

    subnet_bits = 32 - subnet_mask;

    merge = octect_4>>(8-subnet_bits);
    merge<<=(8-subnet_bits);

    printf("Network Address: %d.%d.%d.%d\n",octect_1,octect_2,octect_3,merge);
    printf("Broadcast Address: %d.%d.%d.%d\n",octect_1,octect_2,octect_3,((int)pow(2,subnet_bits)-1) | merge);

    return 0;
}