//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

void printBinary(unsigned int n){
    unsigned int i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

int main(){
    unsigned int IP[4] = {0,0,0,0};
    unsigned int subnet, mask;
    printf("Enter IP Address in dotted decimal format (e.g. 192.168.0.1): ");
    scanf("%u.%u.%u.%u",&IP[0],&IP[1],&IP[2],&IP[3]);
    printf("Enter Subnet Mask prefix: ");
    scanf("%u",&subnet);
    mask = (unsigned int)(0xFFFFFFFF << (32 - subnet));
    unsigned int network = ((IP[0] << 24) & 0xFF000000) | ((IP[1] << 16) & 0x00FF0000) | ((IP[2] << 8) & 0x0000FF00) | ((IP[3] << 0) & 0x000000FF);
    printf("IP address in binary: ");
    printBinary(network);
    printf("\n");
    printf("Subnet mask binary:    ");
    printBinary(mask);
    printf("\n");
    unsigned int address = network & mask;
    unsigned int wildcard = ~mask;
    unsigned int broadcast = address | wildcard;
    printf("Subnet Address:        %u.%u.%u.%u\n", (address>>24)&0xFF, (address>>16)&0xFF, (address>>8)&0xFF, (address>>0)&0xFF);
    printf("Wildcard mask binary:  ");
    printBinary(wildcard);
    printf("\n");
    printf("Broadcast Address:     %u.%u.%u.%u\n", (broadcast>>24)&0xFF, (broadcast>>16)&0xFF, (broadcast>>8)&0xFF, (broadcast>>0)&0xFF);
    return 0;
}