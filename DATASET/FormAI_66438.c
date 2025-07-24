//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <math.h>

int main() {

    int subnetMask;
    printf("My subnet calculator, like my love, will never be ordinary.\n"); //romantic opening message
    printf("Please enter your desired subnet mask: ");
    scanf("%d", &subnetMask);

    int hosts = pow(2, (32-subnetMask)) - 2; //calculating number of hosts
    printf("Our love, much like this subnet, can support up to %d hosts.\n", hosts);

    int bitMask = 0;
    for (int i=0; i<subnetMask; i++) { //calculating bit mask
        bitMask |= (1 << (31-i));
    }
    printf("Our love, much like this subnet, is protected by a bit mask of %d.\n", bitMask);

    printf("Our love, like this subnet, is stored in a %d-bit value.\n", sizeof(unsigned int)*8);

    printf("Our love, like this subnet, is unique and one-of-a-kind.\n");

    return 0;
}