//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int getSubnetMask(int);

int main(){
    int subnetMaskLength;
    int subnetMask;

    printf("What is the length of the subnet mask? ");
    scanf("%d",&subnetMaskLength);

    if(subnetMaskLength >= 24){ //Class C IP address
        subnetMask = getSubnetMask(subnetMaskLength - 24);
        printf("Subnet mask: 255.255.255.%d\n", subnetMask);

    } else {
        printf("Invalid subnet mask length. Must be greater than or equal to 24.\n");
        exit(0);
    }

    return 0;
}

int getSubnetMask(int bits){
    int sum = 0;
    int i;

    for(i = 0; i < bits; i++){
        sum += 1 << (7-i);
    }

    return sum;
}