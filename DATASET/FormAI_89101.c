//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include<stdio.h>
#include<string.h>
#include<math.h>

void calculateSubnetMask(int CIDR, int *subnetOctets) {
    int n = CIDR / 8;
    int remBits = CIDR % 8;
    int subnetMask = 0;
    int i;
    
    for(i = 0; i < n; i++) {
        subnetOctets[i] = 255;
    }
    
    for(i = n; i < 4; i++) {
        subnetOctets[i] = 0;
    }
    
    for(i = 0; i < remBits; i++) {
        subnetMask += pow(2, 7 - i);
    }
    
    subnetOctets[n] = subnetMask;
}

void main() {
    int CIDR;
    int subnetOctets[4];
    char input[20];
    char *ptr;
    int i;
    
    printf("Enter the CIDR notation: ");
    fgets(input, 20, stdin);
    if((ptr = strchr(input, '\n')) != NULL) {
        *ptr = '\0';
    }
    CIDR = atoi(input);
    
    calculateSubnetMask(CIDR, subnetOctets);
    
    printf("The subnet mask is: %d.%d.%d.%d\n", subnetOctets[0], subnetOctets[1], subnetOctets[2], subnetOctets[3]);
    
    return;
}