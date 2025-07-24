//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>

void calculateNetworkAddress(unsigned char ipAddress[], int subnetMask[], unsigned char networkAddress[]){
    int i;
    for(i = 0; i < 4; i++){
        networkAddress[i] = ipAddress[i] & subnetMask[i];
    }
}

int calculateHosts(int subnetMask[]){
    int i, bits = 0;
    for(i = 0; i < 4; i++){
        unsigned char mask = subnetMask[i];
        while(mask){
            bits += mask & 1;
            mask >>= 1;
        }
    }
    return pow(2, 32 - bits) - 2;
}

int main(){
    unsigned char ipAddress[4];
    int subnetMask[4];

    printf("Welcome to the Subnet Calculator!\n\n");
    printf("Enter the IP Address (in the format x.x.x.x): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);
    printf("Enter the Subnet Mask (in the format x.x.x.x): ");
    scanf("%d.%d.%d.%d", &subnetMask[0], &subnetMask[1], &subnetMask[2], &subnetMask[3]);

    // Calculating Network Address
    unsigned char networkAddress[4];
    calculateNetworkAddress(ipAddress, subnetMask, networkAddress);

    printf("\nDetails:\n\n");
    printf("IP Address:\t\t%hhu.%hhu.%hhu.%hhu\n", ipAddress[0], ipAddress[1], ipAddress[2], ipAddress[3]);
    printf("Subnet Mask:\t\t%d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    printf("Network Address:\t%hhu.%hhu.%hhu.%hhu\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("Number of Hosts:\t%d\n", calculateHosts(subnetMask));

    return 0;
}