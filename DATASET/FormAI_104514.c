//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

int main() {
    int num;

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the number is a power of two
    if ((num != 0) && ((num & (num - 1)) == 0)) {
        printf("%d is a power of two\n", num);
    }
    else {
        printf("%d is not a power of two\n", num);
    }

    return 0;
}