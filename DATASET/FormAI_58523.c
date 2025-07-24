//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <math.h>
 
// Function to convert decimal to binary
void decToBinary(int n, int binary[]) {
    int i = 0;
    while (n > 0) {
          binary[i++] = n%2;
        n = n/2;
    }
}
 
// Function to calculate the subnet
void calcSubnet(int CIDR, int subnet[]) {
    int i;
    for (i = 0; i < 4; i++) {
        int sub = 0;
        int j;
        for (j = 0; j < 8; j++) {
            if (CIDR > 0) {
                sub = sub + pow(2, 7-j);
                CIDR--;
            }
        }
        subnet[i] = sub;
    }
}
 
// Function to print subnet and netmask
void printSubnet(int subnet[], int netmask[]) {
    int i;
    for (i = 0; i < 4; i++) {
        printf("%d", subnet[i]);
        if (i != 3)
            printf(".");
    }
    printf("\n");
    for (i = 0; i < 4; i++) {
        printf("%d", netmask[i]);
        if (i != 3)
            printf(".");
    }
}
 
int main() {
    int IP[4] = {192, 168, 1, 1};  // Sample IP
    int CIDR = 24;  // Sample CIDR
    int binary[8] = {0};  // Array to store binary equivalent of octets
    int subnet[4] = {0};  // Array to store subnet
    int netmask[4] = {0};  // Array to store netmask
    int i;
 
    decToBinary(IP[0], binary);   // Convert first octet to binary
    for (i = 0; i < 8; i++) {
        if (i < CIDR) {
            netmask[0] = netmask[0] + pow(2, 7-i);
        }
        else {
            binary[i] = 0;
        }
    }
    subnet[0] = IP[0] & netmask[0];  // Calculate subnet
 
    decToBinary(IP[1], binary);  // Convert second octet to binary
    for (i = 0; i < 8; i++) {
        if (CIDR > 8) {
            if (i < CIDR-8) {
                netmask[1] = netmask[1] + pow(2, 7-i);
            }
            else {
                binary[i] = 0;
            }
        }
        else {
            binary[i] = 0;
        }
    }
    subnet[1] = IP[1] & netmask[1];  // Calculate subnet
 
    decToBinary(IP[2], binary);  // Convert third octet to binary
    for (i = 0; i < 8; i++) {
        if (CIDR > 16) {
            if (i < CIDR-16) {
                netmask[2] = netmask[2] + pow(2, 7-i);
            }
            else {
                binary[i] = 0;
            }
        }
        else {
            binary[i] = 0;
        }
    }
    subnet[2] = IP[2] & netmask[2];  // Calculate subnet
 
    decToBinary(IP[3], binary);  // Convert fourth octet to binary
    for (i = 0; i < 8; i++) {
        if (CIDR > 24) {
            if (i < CIDR-24) {
                netmask[3] = netmask[3] + pow(2, 7-i);
            }
            else {
                binary[i] = 0;
            }
        }
        else {
            binary[i] = 0;
        }
    }
    subnet[3] = IP[3] & netmask[3];  // Calculate subnet
 
    printf("Subnet: ");
    printSubnet(subnet, netmask);
    return 0;
}