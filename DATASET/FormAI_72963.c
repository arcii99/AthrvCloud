//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int octet[4]; // Array to store the octets
    int subnetMask; // Variable to store the subnet mask
    int numBits, numHosts; // Variables to calculate the number of bits and number of hosts

    printf("Enter the four octets of the IP address:\n"); // Prompt user to enter the four octets
    scanf("%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]); // Store the octets in the array

    printf("Enter the subnet mask:\n"); // Prompt user to enter the subnet mask
    scanf("%d", &subnetMask); // Store the subnet mask

    // Convert the subnetMask to binary
    int binarySubnetMask[32]; // Array to store the binary subnet mask
    for (int i = 0; i < 32; i++) {
        binarySubnetMask[i] = i < subnetMask ? 1 : 0;
    }

    // Calculate the number of bits and number of hosts
    numBits = 32 - subnetMask;
    numHosts = numBits == 0 ? 0 : (int) pow(2, numBits) - 2;

    // Print the results
    printf("IP Address: %d.%d.%d.%d\n", octet[0], octet[1], octet[2], octet[3]);
    printf("Subnet Mask: %d\n", subnetMask);
    printf("Binary Subnet Mask: ");
    for (int i = 0; i < 32; i++) {
        printf("%d", binarySubnetMask[i]);
    }
    printf("\n");
    printf("Number of Bits: %d\n", numBits);
    printf("Number of Hosts: %d\n", numHosts);

    return 0;
}