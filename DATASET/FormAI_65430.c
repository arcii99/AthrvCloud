//FormAI DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

void binary_conversion(int num) {

    int binary_num[32];

    int i = 0;
    while (num > 0) {
        binary_num[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Binary representation of the given number is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary_num[j]);
    }

    printf("\n");
}

int main() {

    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    binary_conversion(num);

    return 0;
}