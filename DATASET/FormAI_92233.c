//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include<stdio.h>

/**
 * This function calculates the checksum of a string 
 * using the given checksum polynomial number 
 * and returns the calculated checksum.
 * @param str The string for which checksum needs to be calculated.
 * @param polynomialNumber The checksum polynomial number 
 *        that will be used in the calculation.
 * @return The calculated checksum.
*/
unsigned int calculateChecksum(char *str, unsigned int polynomialNumber) {
    size_t strLength = strlen(str);
    unsigned int checksum = 0;

    // loop through each character in the string
    for (size_t i = 0; i < strLength; i++) {
        // XOR the current character with the checksum
        checksum ^= str[i];

        // loop through each bit in the character
        for (size_t j = 0; j < 8; j++) {
            // if the current bit is 1
            if ((checksum >> j) & 0x01) {
                // XOR the polynomialNumber with the checksum
                checksum ^= polynomialNumber << j;
            }
        }
    }

    return checksum;
}

int main() {
    char str[100];
    unsigned int polynomialNumber;

    // get the string and polynomial number from the user
    printf("Enter a string whose checksum needs to be calculated: ");
    fgets(str, 100, stdin);
    printf("Enter a polynomial number for checksum calculation: ");
    scanf("%d", &polynomialNumber);

    // calculate the checksum of the string using the polynomial number
    unsigned int checksum = calculateChecksum(str, polynomialNumber);
    printf("Checksum of the string '%s' using the polynomial number '%d' is '%u'", str, polynomialNumber, checksum);

    return 0;
}