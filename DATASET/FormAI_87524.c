//FormAI DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>

// Function to convert decimal to binary
void decToBin(int num)
{
    int binary_num[32];
    int index = 0;

    // Extract each digit of binary number and store it in array
    while (num > 0) {
        binary_num[index++] = num % 2;
        num = num / 2;
    }

    // Print the binary number in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary_num[i]);
    }
}

int main()
{
    int dec_num;
    printf("Enter decimal number: ");
    scanf("%d", &dec_num);

    printf("Binary number: ");
    decToBin(dec_num);

    return 0;
}