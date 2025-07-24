//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    char ipAddress[16];
    char subnetMask[16];
    char *ptr;
    int subnetBits, hostBits;
    int i, j, k, n, m, addressValue, subnetValue, maskValue, inputValid;

    do {
        inputValid = 1;

        printf("Enter IP address (IPv4): ");
        fgets(ipAddress, 16, stdin);

        ptr = strtok(ipAddress, ".");
        for (i = 0; i < 4; i++) {
            if (ptr != NULL) {
                addressValue = atoi(ptr);
                if (addressValue >= 0 && addressValue <= 255) {
                    ptr = strtok(NULL, ".");
                }
                else {
                    printf("Invalid IP address.\n");
                    inputValid = 0;
                    break;
                }
            }
            else {
                printf("Invalid IP address.\n");
                inputValid = 0;
                break;
            }
        }

        if (inputValid) {
            printf("Enter subnet mask (IPv4): ");
            fgets(subnetMask, 16, stdin);

            ptr = strtok(subnetMask, ".");
            subnetBits = 0;
            for (i = 0; i < 4; i++) {
                if (ptr != NULL) {
                    maskValue = atoi(ptr);
                    if ((maskValue & (maskValue - 1)) == 0 && maskValue != 0) {
                        subnetBits += (int)log2(maskValue);
                        ptr = strtok(NULL, ".");
                    }
                    else {
                        printf("Invalid subnet mask.\n");
                        inputValid = 0;
                        break;
                    }
                }
                else {
                    printf("Invalid subnet mask.\n");
                    inputValid = 0;
                    break;
                }
            }

            if (inputValid) {
                hostBits = 32 - subnetBits;

                int networkAddress = (addressValue >> (8 - subnetBits)) << (8 - subnetBits);

                printf("\n%-20s: %s\n", "IP address", ipAddress);
                printf("%-20s: %s\n", "Subnet mask", subnetMask);
                printf("%-20s: %d\n", "Subnet bits", subnetBits);
                printf("%-20s: %d\n", "Host bits", hostBits);
                printf("%-20s: %d.%d.%d.%d\n", "Network address", networkAddress >> 24, (networkAddress >> 16) & 0xFF, (networkAddress >> 8) & 0xFF, networkAddress & 0xFF);
                printf("\n");

                // Generate IP range for the current network
                int hostRange = (int)pow(2, hostBits) - 2;
                int startAddress = networkAddress + 1;
                int endAddress = networkAddress + hostRange;

                printf("IP range for the current network:\n");
                printf("%-20s: %d.%d.%d.%d\n", "Start address", startAddress >> 24, (startAddress >> 16) & 0xFF, (startAddress >> 8) & 0xFF, startAddress & 0xFF);
                printf("%-20s: %d.%d.%d.%d\n", "End address", endAddress >> 24, (endAddress >> 16) & 0xFF, (endAddress >> 8) & 0xFF, endAddress & 0xFF);
                printf("\n");
            }
        }
    } while (!inputValid);

    return 0;
}