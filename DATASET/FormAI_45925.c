//FormAI DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    // Welcome message
    printf("Welcome to the Binary to Decimal Converter!\n\n");
    
    char binary[100];
    int decimal = 0, power = 0;
    
    // Prompt user for binary input
    printf("Please enter a binary number: ");
    scanf("%s", binary);
    
    // Loop through the binary string and convert to decimal
    for(int i=strlen(binary)-1; i>=0; i--) {
        if(binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    
    // Display the decimal value
    printf("\nDecimal: %d", decimal);
    
    return 0;
}