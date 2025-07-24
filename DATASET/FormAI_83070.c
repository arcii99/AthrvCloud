//FormAI DATASET v1.0 Category: Binary Converter ; Style: Alan Touring
#include <stdio.h>

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    int binary[32];
    int i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    printf("The binary representation of the integer is: ");
    if (i == 0) {
        printf("0");
    } else {
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binary[j]);
        }
    }
    printf("\n");

    return 0;
}