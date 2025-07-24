//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert binary string to decimal
int binToDec(char *bin) {
    int dec = 0;
    int len = strlen(bin);
    for (int i = 0; i < len; i++) {
        if (bin[i] == '1') {
            dec += pow(2, len - i - 1);
        }
    }
    return dec;
}

// Function to convert decimal number to binary string
char* decToBin(int dec, int bits) {
    char *bin = malloc(bits+1);
    for (int i = bits-1; i >= 0; i--) {
        if (dec % 2 == 1) {
            bin[i] = '1';
        } else {
            bin[i] = '0';
        }
        dec /= 2;
    }
    bin[bits] = '\0';
    return bin;
}

int main() {
    char ip[16];
    int mask;
    printf("Enter IP address in the format X.X.X.X: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%d", &mask);

    // Parse IP address into four octets
    char *ip1 = strtok(ip, ".");
    char *ip2 = strtok(NULL, ".");
    char *ip3 = strtok(NULL, ".");
    char *ip4 = strtok(NULL, ".");

    // Convert octets from string to int
    int octet1 = atoi(ip1);
    int octet2 = atoi(ip2);
    int octet3 = atoi(ip3);
    int octet4 = atoi(ip4);

    // Convert subnet mask from CIDR notation to binary string
    char *binMask = decToBin(pow(2, mask)-1, 32);

    // Parse binary mask into four octets
    char *binMask1 = strtok(binMask, "");
    char *binMask2 = strtok(NULL, "");
    char *binMask3 = strtok(NULL, "");
    char *binMask4 = strtok(NULL, "");

    // Convert binary mask octets to decimal
    int maskOctet1 = binToDec(binMask1);
    int maskOctet2 = binToDec(binMask2);
    int maskOctet3 = binToDec(binMask3);
    int maskOctet4 = binToDec(binMask4);

    // Calculate network address
    int netOctet1 = octet1 & maskOctet1;
    int netOctet2 = octet2 & maskOctet2;
    int netOctet3 = octet3 & maskOctet3;
    int netOctet4 = octet4 & maskOctet4;

    // Print network address
    printf("\nNetwork address: %d.%d.%d.%d\n", netOctet1, netOctet2, netOctet3, netOctet4);

    // Calculate broadcasting address
    int broadcastOctet1 = netOctet1 | (~maskOctet1 & 0xff);
    int broadcastOctet2 = netOctet2 | (~maskOctet2 & 0xff);
    int broadcastOctet3 = netOctet3 | (~maskOctet3 & 0xff);
    int broadcastOctet4 = netOctet4 | (~maskOctet4 & 0xff);

    // Print broadcasting address
    printf("Broadcasting address: %d.%d.%d.%d\n", broadcastOctet1, broadcastOctet2, broadcastOctet3, broadcastOctet4);

    return 0;
}