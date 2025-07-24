//FormAI DATASET v1.0 Category: Binary Converter ; Style: shocked
#include <stdio.h>

void decToBin(int n);

int main() {
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d",&decimalNumber);
    printf("The binary representation of %d is: ", decimalNumber);
    decToBin(decimalNumber);
    printf("\n");
    return 0;
}

void decToBin(int n) {
    int binaryNumber[1000];
    int i = 0;
    while (n > 0) {
        binaryNumber[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i-1; j>=0; j--)
        printf("%d", binaryNumber[j]);
}