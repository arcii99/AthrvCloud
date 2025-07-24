//FormAI DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void binaryConversion(int num);

int main() {
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    printf("\nThe binary conversion of %d is: ", decimalNum);
    binaryConversion(decimalNum);
    printf("\nDone.");
    return 0;
}

void binaryConversion(int num) {
    if(num > 1) {
        binaryConversion(num/2);
    }
    printf("%d", num%2);
}