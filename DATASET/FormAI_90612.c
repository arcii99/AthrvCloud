//FormAI DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* binaryConverter(int decimal) {
    char* binary = (char*) malloc(8 * sizeof(char)); // allocate 8 bytes for binary number
    
    int i = 0;
    while(decimal > 0) {
        binary[i++] = decimal % 2 + '0'; // add the remainder to the binary string
        decimal /= 2;
    }
    
    // pad with zeros if necessary
    while(i < 8) {
        binary[i++] = '0';
    }
    
    // reverse the string and return it
    char* reversed = (char*) malloc(8 * sizeof(char));
    for(int j = 0; j < 8; j++) {
        reversed[j] = binary[7 - j];
    }
    
    free(binary); // free allocated memory
    return reversed;
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    char* binary = binaryConverter(decimal);
    
    printf("Binary equivalent: %s\n", binary);
    
    free(binary); // free allocated memory
    
    return 0;
}