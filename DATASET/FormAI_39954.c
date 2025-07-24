//FormAI DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    unsigned int num, binary[32], i = 0;

    printf("Enter an integer number: ");
    scanf("%u", &num);

    while (num) {
        binary[i++] = num % 2;
        num /= 2;
    }

    printf("Binary representation of %u is: ", num);
    if(i == 0)
        printf("0");
    else
        for (int j = i - 1; j >= 0; j--)
            printf("%u", binary[j]);

    printf("\n");

    return EXIT_SUCCESS;
}