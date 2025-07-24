//FormAI DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>

void binaryConverter(int num) {
    int binaryNum[32] = {0}, i = 0;

    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        ++i;
    }

    printf("The binary equivalent is: ");
    for (int j = i - 1; j >= 0; --j)
        printf("%d", binaryNum[j]);
}

int main() {
    int num;

    printf("Enter a number to convert to binary: ");
    scanf("%d", &num);

    binaryConverter(num);

    return 0;
}