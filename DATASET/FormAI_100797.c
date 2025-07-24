//FormAI DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>

// Function to convert a decimal number to binary
void decimalToBinary(int n)
{
    // Array to store binary number
    int binaryNum[1000];
 
    // Counter for binary array
    int i = 0;
    while (n > 0) {
 
        // Storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // Printing binary array in reverse order
    printf("The binary equivalent is: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main() 
{
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
 
    decimalToBinary(decimalNum);
    return 0;
}