//FormAI DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int decimal, binary[1000], count = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    while(decimal > 0) {
        binary[count] = decimal % 2; // get remainder
        decimal /= 2; // divide by 2
        count++;
    }

    printf("Binary equivalent is: ");

    for(int i = count - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    return 0;
}