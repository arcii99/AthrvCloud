//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <math.h>

int main() {
    int subnetMask, octet1, octet2, octet3, octet4;
    int binMask[32], i, j=0, numSubnets, numHosts;
    char class;
    float hostsPerSubnet;

    printf("Enter IP Address in the format xxx.xxx.xxx.xxx: ");
    scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    printf("Enter Subnet Mask in the format xx: ");
    scanf("%d", &subnetMask);

    if(subnetMask<=8) {
        class = 'A';
        numSubnets = pow(2, 8-subnetMask);
        numHosts = pow(2, 24-subnetMask)-2;
    } else if(subnetMask<=16) {
        class = 'B';
        numSubnets = pow(2, 16-subnetMask);
        numHosts = pow(2, 16-subnetMask)-2;
    } else {
        class = 'C';
        numSubnets = pow(2, 24-subnetMask);
        numHosts = pow(2, 8-subnetMask)-2;
    }

    hostsPerSubnet = numHosts/numSubnets;

    printf("\nClass: %c", class);
    printf("\nNumber of subnets: %d", numSubnets);
    printf("\nNumber of hosts per subnet: %.0f", hostsPerSubnet);

    for(i=31; i>=0; i--) {
        if(j==subnetMask) {
            binMask[i] = 0;
        } else {
            binMask[i] = 1;
            j++;
        }
    }

    printf("\nBinary Subnet Mask: ");
    for(i=0; i<32; i+=8) {
        printf("%d.%d.%d.%d ",
            binMask[i]*128+binMask[i+1]*64+binMask[i+2]*32+binMask[i+3]*16+binMask[i+4]*8+binMask[i+5]*4+binMask[i+6]*2+binMask[i+7]*1,
            binMask[i+1]*128+binMask[i+2]*64+binMask[i+3]*32+binMask[i+4]*16+binMask[i+5]*8+binMask[i+6]*4+binMask[i+7]*2+binMask[i+8]*1,
            binMask[i+2]*128+binMask[i+3]*64+binMask[i+4]*32+binMask[i+5]*16+binMask[i+6]*8+binMask[i+7]*4+binMask[i+8]*2+binMask[i+9]*1,
            binMask[i+3]*128+binMask[i+4]*64+binMask[i+5]*32+binMask[i+6]*16+binMask[i+7]*8+binMask[i+8]*4+binMask[i+9]*2+binMask[i+10]*1
            );
    }

    printf("\n\nIP Address: %d.%d.%d.%d", octet1, octet2, octet3, octet4);
    printf("\nNetwork Address: %d.%d.%d.%d", octet1&binMask[24]+octet2&binMask[16]+octet3&binMask[8]+binMask[0]);
    printf("\nBroadcast Address: %d.%d.%d.%d", octet1|~binMask[24]&255, octet2|~binMask[16]&255, octet3|~binMask[8]&255, octet4|~binMask[0]&255);

    return 0;
}