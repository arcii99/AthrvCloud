//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: real-life
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Function to calculate the Subnet Mask
void calculateSubnetMask(int subnetMaskBit, int* subnetMask) {
    int num = 256 - pow(2, (8 - subnetMaskBit));
    for (int i = 0; i < 4; i++) {
        if (subnetMaskBit >= 8) {
            subnetMask[i] = 255;
            subnetMaskBit -= 8;
        } else {
            subnetMask[i] = num;
            num = 0;
        }
    }
}

// Function to perform bitwise AND on IP addresses
void performBitwiseAND(int* ipAddress, int* subnetMask, int* networkAddress) {
    for (int i = 0; i < 4; i++) {
        networkAddress[i] = ipAddress[i] & subnetMask[i];
    }
}

int main() {
    int ipAddress[4], subnetMaskBit, subnetMask[4], networkAddress[4];
    printf("\nEnter the IP Address (XXX.XXX.XXX.XXX):\n");
    scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);
    printf("\nEnter the Subnet Mask in Bits:\n");
    scanf("%d", &subnetMaskBit);
    calculateSubnetMask(subnetMaskBit, subnetMask);
    performBitwiseAND(ipAddress, subnetMask, networkAddress);
    printf("\nThe Subnet Mask is: %d.%d.%d.%d (/%d)\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3], subnetMaskBit);
    printf("\nThe Network Address is: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    return 0;
}