//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSubnet(int n, int bits) {
    int i, j;
    int mask = 0;

    for(i = 0; i < bits; ++i) {
        mask |= (1 << (31 - i));
    }

    for(i = 0; i < n; ++i) {
        printf("Subnet %d: ", i+1);
        for(j = 0; j < 4; ++j) {
            if(j > 0) printf(".");
            printf("%d", (i << bits) + ((mask >> (8*j)) & 0xff));
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    int subnetBits;
    if(argc < 2) {
        printf("Usage: %s <number of subnets>\n", argv[0]);
        return 1;
    }

    int nSubnets = atoi(argv[1]);
    if(nSubnets <= 0) {
        printf("Please enter a positive integer\n");
        return 1;
    }

    int nBits = 0;
    while((1 << nBits) < nSubnets) ++nBits;
    printf("Number of bits to be borrowed: %d\n", nBits);

    printSubnet(nSubnets, nBits);

    return 0;
}