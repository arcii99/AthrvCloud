//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int parity = 0;
    while (num) {
        parity ^= num & 1;
        num >>= 1;
    }

    if (parity) {
        printf("The number is odd.\n");
    } else {
        printf("The number is even.\n");
    }

    return 0;
}