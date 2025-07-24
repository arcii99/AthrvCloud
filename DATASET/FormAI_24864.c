//FormAI DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>

int main() {
    int num, dig, base, i, j;
    int bin[100];
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    // Convert decimal to binary
    base = 2;
    i = 0;
    
    while(num > 0) {
        dig = num % base;
        bin[i] = dig;
        num /= base;
        i++;
    }
    
    // Print binary number
    printf("Binary number: ");
    for(j=i-1; j>=0; j--) {
        printf("%d", bin[j]);
    }
    printf("\n");
    
    return 0;
}