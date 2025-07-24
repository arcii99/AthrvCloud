//FormAI DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void binaryConverter(int n);

int main()
{
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    printf("Binary representation of %d is: ", decimalNum);
    binaryConverter(decimalNum);
    printf("\n");
    return 0;
}

void binaryConverter(int n)
{
    int binaryNum[1000]; // array to store binary number
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2; // storing remainder in array
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]); // printing binary number
    return;
}