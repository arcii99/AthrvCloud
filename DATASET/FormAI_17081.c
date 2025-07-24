//FormAI DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

int binary[32];
int index = 0;

// Function to convert decimal to binary
void decimalToBinary(int num)
{
    int i = 0;
    while(num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
    index = i - 1;
}

// Async function to print binary number
void asyncPrintBinary()
{
    printf("Binary: ");
    while(index >= 0) {
        printf("%d", binary[index]);
        index--;
    }
}

int main()
{
    // Get the decimal number from user
    int decimalNum;
    printf("Enter decimal number: ");
    scanf("%d", &decimalNum);
    
    // Convert decimal to binary
    decimalToBinary(decimalNum);
    
    // Print binary number asynchronously
    asyncPrintBinary();
    
    printf("\n");
    return 0;
}