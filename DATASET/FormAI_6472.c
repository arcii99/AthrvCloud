//FormAI DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>

void binary(int n)
{
    int binary_num[32];
    int i = 0;

    while (n > 0) {
        binary_num[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("\nThe binary representation is: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary_num[j]);
}

int main()
{
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Binary representation is not possible for negative numbers.");
    else if (num == 0)
        printf("Binary representation of 0 is 0.");
    else {
        printf("Binary conversion of %d is:\n", num);
        binary(num);
    }

    return 0;
}