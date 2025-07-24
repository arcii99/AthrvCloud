//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ()
{
    char inputIP[20], mask[20], command[20];
    int ipOctets[4], subnetMask, subnetBits, subnetOctet, subnetShift, hostBits, hostCount;

    do {
        printf("Enter a valid IP address (e.g. 192.168.1.1): ");
        fgets(inputIP, 20, stdin);

        printf("Enter subnet mask (e.g. 255.255.255.0): ");
        fgets(mask, 20, stdin);

        // Split IP address into octets
        char *token = strtok(inputIP, ".");
        int octetCount = 0;
        while (token != NULL) {
            ipOctets[octetCount++] = atoi(token);
            token = strtok(NULL, ".");
        }

        // Calculate subnet mask and number of host bits
        int maskOctets[4], maskCount = 0, totalHostBits = 0;
        token = strtok(mask, ".");
        while (token != NULL) {
            maskOctets[maskCount] = atoi(token);
            totalHostBits += 8 - (int)log2(maskOctets[maskCount++]);
            token = strtok(NULL, ".");
        }
        subnetMask = (maskOctets[0] << 24) + (maskOctets[1] << 16) + (maskOctets[2] << 8) + maskOctets[3];
        subnetBits = (int)log2(subnetMask ^ 0xffffffff) + 1;

        // Calculate subnet prefix and number of host bits
        subnetOctet = ipOctets[(int)floor(subnetBits / 8.0)];
        subnetShift = subnetBits % 8;
        hostBits = 32 - subnetBits;
        hostCount = (int)pow(2, hostBits) - 2;

        // Print results
        printf("\nIP: %d.%d.%d.%d\n", ipOctets[0], ipOctets[1], ipOctets[2], ipOctets[3]);
        printf("Subnet Mask: %d.%d.%d.%d\n", maskOctets[0], maskOctets[1], maskOctets[2], maskOctets[3]);
        printf("Subnet Prefix: %d.%d.%d.%d/%d\n", ipOctets[0], ipOctets[1], ipOctets[2], subnetOctet, subnetBits);
        printf("Number of Hosts: %d\n", hostCount);

        // Prompt user to run program again or exit
        printf("\nWould you like to calculate another IP? (Y/N): ");
        fgets(command, 20, stdin);
    } while (command[0] == 'Y' || command[0] == 'y');

    return 0;
}