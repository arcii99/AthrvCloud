//FormAI DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number;
    printf("Enter a number between 1 and 10: ");
    if (scanf("%d", &number) != 1 || number < 1 || number > 10) {
        fprintf(stderr, "Invalid number entered. Please enter a number between 1 and 10.\n");
        exit(1);
    }

    int result = 10 / number;
    printf("The result of 10 divided by %d is %d.\n", number, result);

    return 0;
}