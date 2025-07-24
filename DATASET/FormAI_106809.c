//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber, int* binaryArray, int numOfBits) {
    for (int i = numOfBits - 1; i >= 0; i--) {
        int quotient = decimalNumber / (int)pow(2, i);
        binaryArray[numOfBits - 1 - i] = quotient;
        decimalNumber = decimalNumber - (quotient * (int)pow(2, i));
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int* binaryArray, int numOfBits) {
    int decimalNumber = 0;
    for (int i = 0; i < numOfBits; i++) {
        decimalNumber += binaryArray[numOfBits - 1 - i] * (int)pow(2, i);
    }
    return decimalNumber;
}

int main() {
    int configNumOfBits; // Number of bits to convert
    int choice; // User choice for converting decimal to binary or binary to decimal
    printf("Enter the number of bits to convert: ");
    scanf("%d", &configNumOfBits);

    // Allocate memory for binary and decimal arrays
    int* binaryArray = (int*)malloc(configNumOfBits * sizeof(int));
    int* decimalArray = (int*)malloc(configNumOfBits * sizeof(int));

    while(1) {
        printf("\n1. Convert Decimal to Binary \n2. Convert Binary to Decimal \n3. Quit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int decimalNum;
                printf("Enter the decimal number to convert: ");
                scanf("%d", &decimalNum);

                decimalToBinary(decimalNum, binaryArray, configNumOfBits);

                printf("Binary conversion of %d: ", decimalNum);
                for (int i = 0; i < configNumOfBits; i++) {
                    printf("%d", binaryArray[i]);
                }
                printf("\n");
                break;
            }
            case 2: {
                printf("Enter the binary number to convert: ");
                for (int i = 0; i < configNumOfBits; i++) {
                    scanf("%d", &binaryArray[i]);
                }

                int decimalNum = binaryToDecimal(binaryArray, configNumOfBits);

                printf("Decimal conversion of ");
                for (int i = 0; i < configNumOfBits; i++) {
                    printf("%d", binaryArray[i]);
                }
                printf(": %d\n", decimalNum);
                break;
            }
            case 3: {
                // Free allocated memory before quitting
                free(binaryArray);
                free(decimalArray);
                printf("Quitting program.\n");
                exit(0);
            }
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}