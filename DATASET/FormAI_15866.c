//FormAI DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void convert_dec_to_bin(int n)
{
    if (n == 0) {
        printf("0");
        return;
    }
    int binary[32];
    int i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
}

int main()
{
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Binary equivalent: ");
    convert_dec_to_bin(num);
    printf("\n");
    return 0;
}