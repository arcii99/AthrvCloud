//FormAI DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>
#include <string.h>

// Function to convert decimal value to binary
void decToBinary(int n)
{
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // Storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // Printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    int decimal_num;
    printf("Please input a decimal number: ");
    scanf("%d", &decimal_num);
    printf("\nDecimal Number %d is: ", decimal_num);
    decToBinary(decimal_num);
    printf(" in binary.");
    return 0;
}