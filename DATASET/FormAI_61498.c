//FormAI DATASET v1.0 Category: QR code generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool isHexValid(char c);
char *generateRandomHex(int length);
void generateQRCode(char *data);
void printQRCode(char **qrCode);

/**
 * Check if a given character is a valid hexadecimal value.
 *
 * @param c The character to be checked.
 * @return True if valid, false otherwise.
 */
bool isHexValid(char c) {
    if (('0' <= c && c <= '9') || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F')) {
        return true;
    }
    return false;
}

/**
 * Generate a random hexadecimal string of a given length.
 *
 * @param length The length of the string to be generated.
 * @return The randomly generated hexadecimal string.
 */
char *generateRandomHex(int length) {
    char *hexString = malloc(length + 1);
    if (!hexString) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        int randomValue = rand() % 16;
        sprintf(&hexString[i], "%X", randomValue);
    }
    hexString[length] = '\0';

    return hexString;
}

/**
 * Generate a QR code from a given data string.
 *
 * @param data The data string to be encoded.
 */
void generateQRCode(char *data) {
    int dataLength = strlen(data);

    // Ensure data length is a multiple of 2
    if (dataLength % 2 == 1) {
        dataLength++;
        data = realloc(data, dataLength);
        if (!data) {
            printf("Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        data[dataLength - 1] = '0';
        data[dataLength] = '\0';
    }

    // Calculate number of QR code rows and columns
    int dimension = dataLength / 2;

    // Allocate memory for QR code
    char **qrCode = malloc(dimension * sizeof(char *));
    if (!qrCode) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < dimension; i++) {
        qrCode[i] = malloc(dimension * sizeof(char));
        if (!qrCode[i]) {
            printf("Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Map hexadecimal characters to QR code pattern
    for (int i = 0, row = 0; i < dataLength; i += 2, row++) {
        for (int j = 0, col = 0; j < 2; j++, col++) {
            char hexChar = data[i + j];
            if (isHexValid(hexChar)) {
                int hexValue;
                if ('0' <= hexChar && hexChar <= '9') {
                    hexValue = hexChar - '0';
                } else if ('a' <= hexChar && hexChar <= 'f') {
                    hexValue = hexChar - 'a' + 10;
                } else {
                    hexValue = hexChar - 'A' + 10;
                }

                for (int k = 3; k >= 0; k--) {
                    qrCode[row][col * 4 + k] = (hexValue & 1) ? '#' : ' ';
                    hexValue >>= 1;
                }
            } else {
                printf("Invalid hexadecimal character: %c.\n", hexChar);
                exit(EXIT_FAILURE);
            }
        }
    }

    printQRCode(qrCode);

    // Free memory allocated for QR code
    for (int i = 0; i < dimension; i++) {
        free(qrCode[i]);
    }
    free(qrCode);
}

/**
 * Print a given QR code pattern.
 *
 * @param qrCode The QR code pattern to be printed.
 */
void printQRCode(char **qrCode) {
    for (int i = 0; qrCode[i] != NULL; i++) {
        printf("%s\n", qrCode[i]);
    }
}

// Main function
int main() {
    // Generate random hexadecimal data
    char *data = generateRandomHex(20);
    printf("QR code for data: %s\n\n", data);

    // Generate QR code for data
    generateQRCode(data);

    // Free memory allocated for data
    free(data);
    return 0;
}