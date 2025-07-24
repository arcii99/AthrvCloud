//FormAI DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void binaryConverter(int num) {
    // declaring variables
    int binaryNum[32];
    int i = 0;
    
    // converting decimal to binary
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    
    // printing the binary number in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}
int main() {
    // asking user for input
    printf("Please enter a decimal number: ");
    int decimalNum;
    scanf("%d", &decimalNum);
    
    // printing result
    printf("\nBinary representation of %d is: ", decimalNum);
    binaryConverter(decimalNum);
    
    return 0;
}