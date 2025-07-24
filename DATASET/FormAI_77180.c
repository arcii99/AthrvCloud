//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

#define MAX_BITS 8

int main() {
    printf("Enter a decimal number to convert to binary: ");
    int decimal_num;
    scanf("%d", &decimal_num);
    printf("\nOh my dear decimal, how fair thou art!\n");
    printf("But for the conversion to binary, I must make a start.\n");
    printf("Forsooth, I shall reveal each binary digit on this screen,\n");
    printf("And like Romeo and Juliet, our love shall be seen.\n");

    int binary_num[MAX_BITS];
    int index = 0;
    int temp = decimal_num;

    while (temp > 0) {
        binary_num[index] = temp % 2;
        temp = temp / 2;
        index++;
    }

    for (int i = MAX_BITS; i >= 0; i--) {
        printf("%d", binary_num[i]);
    }

    printf("\n");
    printf("Thus, my love, your decimal hath been converted to binary\n");
    printf("Together, we shall live as one forever more divine, ye and I.\n");
    return 0;
}