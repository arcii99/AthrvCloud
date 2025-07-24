//FormAI DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_BINARY_LENGTH 32

int main(){

    char binary[MAX_BINARY_LENGTH + 1];
    int decimal = 0;
    int power = 1;

    printf("Enter a binary number: ");
    fgets(binary, sizeof(binary), stdin);

    // Remove newline character from input
    binary[strcspn(binary, "\n")] = '\0';

    // Convert binary string to decimal
    for(int i = strlen(binary) - 1; i >= 0; i--){
        if(binary[i] == '1'){
            decimal += power;
        }
        power *= 2;
    }

    printf("Decimal: %d\n", decimal);

    return 0;
}