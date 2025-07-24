//FormAI DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>

// Function to perform binary conversion
void binaryConverter(int n)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    //Print binary number in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Binary value of %d is: ", num);
    binaryConverter(num);
    printf("\n");
    return 0;
}