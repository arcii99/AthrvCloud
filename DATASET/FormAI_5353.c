//FormAI DATASET v1.0 Category: Data validation ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int number;

    printf("Enter a number between 1 and 10: ");
    scanf("%d", &number);

    while (number < 1 || number > 10) {
        printf("Invalid input. Please enter a number between 1 and 10: ");
        scanf("%d", &number);
    }

    printf("You entered: %d\n", number);

    return 0;
}