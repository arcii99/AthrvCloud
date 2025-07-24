//FormAI DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 32

void print_binary(unsigned int num) {
    int bits[MAX_BITS];
    int i, j;
    
    // Populate bits array
    for (i = 0; i < MAX_BITS; i++) {
        bits[i] = (num & (1 << i)) ? 1 : 0;
    }
    
    // Find most significant bit
    for (j = MAX_BITS - 1; j >= 0; j--) {
        if (bits[j] == 1) {
            break;
        }
    }
    
    // Print binary representation
    for (i = j; i >= 0; i--) {
        printf("%d", bits[i]);
    }
}

int main() {
    unsigned int num;
    
    printf("Enter a decimal number: ");
    scanf("%u", &num);
    
    printf("Binary representation: ");
    print_binary(num);
    printf("\n");
    
    return 0;
}