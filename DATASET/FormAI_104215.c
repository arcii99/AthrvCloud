//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int num, int *bin){
    int j=0;
    while(num!=0){
        bin[j]=num%2;
        num/=2;
        j++;
    }
}

void printBinary(int *bin, int size){
    for(int i=size-1; i>=0; i--){
        printf("%d", bin[i]);
    }
}

int calculateTotalSubnets(int cidr){
    int power = 32 - cidr;
    return pow(2, power);
}

int calculateSubnetMask(int cidr, int *bin){
    int power = 8 - (cidr%8);
    int index = (cidr/8) - 1;
    if(power==8){
        return 255;
    } else {
        int val = pow(2, power) - 1;
        bin[index] |= val;
        for(int i=0; i<index; i++){
            bin[i] = 255;
        }
        return bin[index];
    }
}

void calculateNetworkAddress(int *ip, int *bin){
    for(int i=0; i<4; i++){
        ip[i] &= bin[i];
    }
}

void calculateBroadcastAddress(int *ip, int *bin){
    for(int i=0; i<4; i++){
        if(bin[i] == 255){
            continue;
        } else {
            int power = 8 - (i*8)%32;
            int val = pow(2, power) - 1;
            ip[i] |= val;
            break;
        }
    }
}

int main() {
    int ip[4], cidr, bin[32]={0};
    printf("Enter the IP address (in dotted decimal notation): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("Enter the CIDR notation: ");
    scanf("%d", &cidr);
    int totalSubnets = calculateTotalSubnets(cidr);
    int subnetMask = calculateSubnetMask(cidr, bin);
    calculateNetworkAddress(ip, bin);
    calculateBroadcastAddress(ip, bin);
    printf("Network Address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Total number of subnets: %d\n", totalSubnets);
    printf("Subnet mask: %d.%d.%d.%d\n", bin[3], bin[2], bin[1], bin[0]);
    return 0;
}