//FormAI DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <math.h>

int main()
{
    int decimalNumber;
    printf("Enter decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert decimal to binary
    int binaryNumber[100], i = 0;
    while (decimalNumber > 0)
    {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }

    // Print the binary number in reverse order
    printf("Binary number is: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binaryNumber[j]);
    }

    // Test the binary to decimal conversion
    int binaryTest[] = {1, 0, 1, 0};
    int decimalTest = 0;
    int k = 0;
    int n = sizeof(binaryTest) / sizeof(binaryTest[0]);
    for (int j = n - 1; j >= 0; j--)
    {
        if (binaryTest[j] == 1)
        {
            decimalTest += pow(2, k);
        }
        k++;
    }
    printf("\nDecimal test number is: %d", decimalTest);

    return 0;
}