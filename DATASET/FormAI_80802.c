//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>

void convertToBinary(int n);

int main()
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Binary equivalent of %d is: ", num);
    convertToBinary(num);

    return 0;
}

void convertToBinary(int n)
{
    // array to store binary number
    int binaryNum[1000];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}