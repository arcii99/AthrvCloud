//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ip[4], subnetMask[4], maskBits, numOfSubnets, numOfHosts;
    char class;

    printf("Greetings, noble traveler! Please enter the IP Address and its Subnet Mask: \n");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    scanf("%d.%d.%d.%d", &subnetMask[0], &subnetMask[1], &subnetMask[2], &subnetMask[3]);

    //Calculate Class of IP Address
    if(ip[0] >= 1 && ip[0] <= 126) {
        class = 'A';
        maskBits = 8;
    }
    else if(ip[0] >= 128 && ip[0] <= 191) {
        class = 'B';
        maskBits = 16;
    }
    else if(ip[0] >= 192 && ip[0] <= 223) {
        class = 'C';
        maskBits = 24;
    }
    else {
        printf("I'm sorry, our village doesn't deal with IP Addresses of that class!\n");
        return 0;
    }

    //Calculate Number of Subnets and Hosts
    numOfSubnets = 1;
    numOfHosts = 1;

    for(int i = maskBits; i < 32; i++) {
        numOfSubnets *= 2;
    }

    for(int i = maskBits; i < 31; i++) {
        numOfHosts *= 2;
    }

    printf("Salutations, traveler! Thou hast presented us with an IP Address of class %c.\n", class);
    printf("The Subnet Mask is %d.%d.%d.%d, and it hath %d bit(s) set to one.\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3], maskBits);
    printf("This IP Address can be divided into %d subnets, and each subnet can contain up to %d hosts.\n", numOfSubnets, numOfHosts);
    printf("Fare thee well on thy journey!\n");

    return 0;
}