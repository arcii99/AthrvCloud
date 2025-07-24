//FormAI DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function for converting decimal to binary
void decToBin(int n)
{
    // Temporary array to store binary number
    int binaryNum[32];

    // Counter for binary array
    int i = 0;
    while (n > 0) {

        // Storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Printing binary array in reverse order
    printf("Binary number is: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    int decimalNumber;

    printf("Please enter a decimal number to convert to binary: ");
    scanf("%d", &decimalNumber);

    if(decimalNumber < 0)
    {
        printf("Sorry, negative numbers cannot be converted to binary!");
    }
    else if(decimalNumber == 0)
    {
        printf("The binary equivalent of 0 is 0.");
    }
    else
    {
        printf("The decimal number is: %d\n", decimalNumber);
        decToBin(decimalNumber);
    }

    return 0;
}