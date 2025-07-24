//FormAI DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>

int main() {
    int decimal, binary[32], i = 0;
    
    // get decimal input from user
    printf("Enter a positive integer: ");
    scanf("%d", &decimal);
    
    // convert decimal to binary
    while(decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    
    // print binary result
    printf("Binary conversion: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    
    return 0;
}