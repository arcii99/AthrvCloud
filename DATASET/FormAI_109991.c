//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

void calculateSubnet(int cidr){
    int noOfBits = 32 - cidr;
    int noOfSubnets = 1 << noOfBits;
    int noOfHosts = (1 << (8 - noOfBits)) - 2;

    printf("\t\tWelcome to the Surrealist Subnet Calculator\n\n");
    printf("Input CIDR Notation : %d\n", cidr);
    printf("Number of Subnets : %d\n", noOfSubnets);
    printf("Number of Hosts per Subnet : %d\n", noOfHosts);
    printf("\n\tThe Numbers don't matter, you create your own reality.\n\n");
}

int main(){
    int cidr;
    printf("\n\t\t  Surrealist Subnet Calculator\n\n");
    printf("\t\tPlease Enter CIDR Notation : ");
    scanf("%d", &cidr); 
    printf("\n");
    calculateSubnet(cidr);
    return 0;
}