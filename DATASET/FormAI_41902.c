//FormAI DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i, j, a[100];

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    /* convert decimal to binary */
    i = 0;
    while(num > 0) {
        a[i] = num % 2;
        num = num / 2;
        i++;
    }

    /* print binary value in reverse order */
    printf("Binary value: ");
    for(j=i-1; j>=0; j--)
        printf("%d", a[j]);
    printf("\n");

    return 0;
}