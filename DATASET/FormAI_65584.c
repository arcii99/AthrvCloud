//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void convertToBinary(int n, int binaryArray[]) {
    int i;
    for (i = 0; n > 0; i++) {
        binaryArray[i] = n % 2;
        n /= 2;
    }
}

void calculateSubnetMask(int cidr, int subnetMask[]) {
    int i, binaryArray[32] = {0};
    convertToBinary(cidr, binaryArray);
    for (i = 0; i < 32; i++) {
        if (i < cidr) {
            subnetMask[i] = binaryArray[i];
        } else {
            subnetMask[i] = 0;
        }
    }
}

void calculateNetworkAddress(int ipAddress[], int subnetMask[], int networkAddress[]) {
    int i;
    for (i = 0; i < 32; i++) {
        networkAddress[i] = ipAddress[i] & subnetMask[i];
    }
}

void printBinaryArray(int binaryArray[]) {
    int i;
    for (i = 31; i >= 0; i--) {
        printf("%d", binaryArray[i]);
        if (i % 8 == 0) printf(".");
    }
}

void calculateMaxHosts(int cidr, int *maxHosts) {
    *maxHosts = pow(2, 32 - cidr) - 2;
}

void calculateBroadcastAddress(int networkAddress[], int subnetMask[], int broadcastAddress[]) {
    int i;
    for (i = 0; i < 32; i++) {
        if (subnetMask[i] == 0) {
            broadcastAddress[i] = 1;
        } else {
            broadcastAddress[i] = networkAddress[i];
        }
    }
}

void printSubnetInformation(int cidr, int subnetMask[], int networkAddress[], int maxHosts, int broadcastAddress[]) {
    printf("Subnet mask:\t");
    printBinaryArray(subnetMask);
    printf("\n");
    printf("Network address:\t");
    printBinaryArray(networkAddress);
    printf("\n");
    printf("Max hosts:\t\t%d\n", maxHosts);
    printf("Broadcast address:\t");
    printBinaryArray(broadcastAddress);
    printf("\n");
}

int main() {
    int ipAddress[32] = {0};
    int cidr, subnetMask[32] = {0}, networkAddress[32] = {0}, maxHosts, broadcastAddress[32] = {0};

    printf("Enter the IP address in binary:\n");
    int i;
    for (i = 31; i >= 0; i--) {
        scanf("%1d", &ipAddress[i]);
    }

    printf("Enter the CIDR value:\n");
    scanf("%d", &cidr);

    calculateSubnetMask(cidr, subnetMask);
    calculateNetworkAddress(ipAddress, subnetMask, networkAddress);
    calculateMaxHosts(cidr, &maxHosts);
    calculateBroadcastAddress(networkAddress, subnetMask, broadcastAddress);
    printSubnetInformation(cidr, subnetMask, networkAddress, maxHosts, broadcastAddress);

    return 0;
}