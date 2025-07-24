//FormAI DATASET v1.0 Category: QR code generator ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a unique QR code based on a given input */
void generateQRCode(char *input)
{
    srand(time(NULL)); // Seed the random number generator

    // Define the payload as a combination of the input string and a random integer
    char payload[50];
    sprintf(payload, "%s%d", input, rand() % 10000);

    // Compute the CRC16 checksum of the payload
    uint16_t crc = 0xFFFF;
    for (int i = 0; i < strlen(payload); i++) {
        crc ^= (uint16_t)payload[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc = (crc >> 1) ^ 0x8408;
            } else {
                crc >>= 1;
            }
        }
    }

    // Append the CRC16 checksum to the payload
    sprintf(payload + strlen(payload), "%04X", crc);

    // Generate the QR code as a string of ASCII characters
    char qrCode[200];
    snprintf(qrCode, sizeof(qrCode), "QRCode|%s|", payload);

    // Print the generated QR code
    printf("%s\n", qrCode);
}

/* Main function to test the QR code generator */
int main()
{
    // Generate a QR code for the input string "Hello, world!"
    generateQRCode("Hello, world!");

    return 0;
}