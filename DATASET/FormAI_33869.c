//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include<stdio.h>
#include<math.h>
int main(){
    int mask;
    int subnet[4];
    int address[4];
    char ans;
    printf("Please enter the IP address in dotted decimal format: \n");
    scanf("%d.%d.%d.%d", &address[0], &address[1], &address[2], &address[3]);
    printf("Please enter the subnet mask in CIDR notation (e.g. 24): \n");
    scanf("%d", &mask);
    int i;
    for (i = 0; i < 4; i++){
        subnet[i] = (mask >= 8) ? 255 : (mask >= 0 ? (int) (pow(2, mask) - 1) : 0);
        mask -= 8;
    }
    printf("\n\n======================================\n");
    printf("Original IP Address: %d.%d.%d.%d\n", address[0], address[1], address[2], address[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("Network Address: %d.%d.%d.%d\n", address[0] & subnet[0], address[1] & subnet[1], address[2] & subnet[2], address[3] & subnet[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", (address[0] & subnet[0]) + ~(subnet[0]), (address[1] & subnet[1]) + ~(subnet[1]), (address[2] & subnet[2]) + ~(subnet[2]), (address[3] & subnet[3]) + ~(subnet[3]));
    printf("Possible Host Addresses: %d\n", (int) (pow(2, 32 - mask) - 2));
    printf("======================================\n");
    printf("\n\nDo you want to try another IP address (y/n)?\n");
    scanf(" %c", &ans);
    if (ans == 'y' || ans == 'Y') main();
    else {
        printf("Bye!\n");
        return 0;
    }
}