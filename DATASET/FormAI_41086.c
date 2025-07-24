//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdint.h>

// function to convert decimal to binary
void decimalToBinary(uint8_t decimal, uint8_t binary[]) {
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
}

// function to calculate subnet mask based on CIDR notation
void calculateSubnet(uint8_t cidr, uint8_t subnet[]) {
    int i;
    for (i = 0; i < 32; i++) {
        if (i < cidr) {
            subnet[i] = 1;
        } else {
            subnet[i] = 0;
        }
    }
}

int main() {
    uint8_t ipAddress[4] = {192, 168, 1, 100}; // example IP address
    uint8_t cidr = 24; // example CIDR notation
    uint8_t subnet[32];
    uint8_t binaryOctets[4][8];

    calculateSubnet(cidr, subnet);

    //ip address to binaryConversion
    for (int i = 0; i < 4; i++) {
        decimalToBinary(ipAddress[i], binaryOctets[i]);
    }

    printf("\nIP Address: %d.%d.%d.%d/%d\n\n", ipAddress[0], ipAddress[1], ipAddress[2], ipAddress[3], cidr);
    printf("Subnet Mask: %d.%d.%d.%d\n\n", subnet[0] * 128 + subnet[1] * 64 + subnet[2] * 32 + subnet[3] * 16 + subnet[4] * 8 + subnet[5] * 4 + subnet[6] * 2 + subnet[7],
           subnet[8] * 128 + subnet[9] * 64 + subnet[10] * 32 + subnet[11] * 16 + subnet[12] * 8 + subnet[13] * 4 + subnet[14] * 2 + subnet[15],
           subnet[16] * 128 + subnet[17] * 64 + subnet[18] * 32 + subnet[19] * 16 + subnet[20] * 8 + subnet[21] * 4 + subnet[22] * 2 + subnet[23],
           subnet[24] * 128 + subnet[25] * 64 + subnet[26] * 32 + subnet[27] * 16 + subnet[28] * 8 + subnet[29] * 4 + subnet[30] * 2 + subnet[31]);

    printf("Binary IP Address: ");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d", binaryOctets[i][j]);
        }
        printf(" ");
    }

    printf("\nBinary Subnet Mask: ");
    for (int i = 0; i < 32; i++) {
        printf("%d", subnet[i]);
        if ((i + 1) % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n\n");

    return 0;
}