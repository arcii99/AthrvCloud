//FormAI DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include<stdio.h>

// Function to convert decimal to binary
void decToBin(int decimalNum)
{
    // Array to store binary number
    int binaryNum[32];
    
    // Counter for binary array
    int i = 0;
    while (decimalNum > 0) 
    {
        // Storing remainder in binary array
        binaryNum[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        i++;
    }
    
    // Printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main() 
{
    int decNum;
    printf("Enter decimal number: ");
    scanf("%d", &decNum);
    printf("Binary equivalent: ");
    decToBin(decNum);
    return 0;
}