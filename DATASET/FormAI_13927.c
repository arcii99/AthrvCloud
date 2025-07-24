//FormAI DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>

// Function to convert decimal to binary
void decToBinary(int num)
{
    int binaryNum[32]; // array to store binary number
    int i = 0;
    while (num > 0) {
        // decimal to binary conversion logic
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }

    // print binary number
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main() {
    int decimal_num;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    printf("Binary representation of %d is ", decimal_num);
    decToBinary(decimal_num);
    printf("\n");

    return 0;
}