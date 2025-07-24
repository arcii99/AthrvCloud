//FormAI DATASET v1.0 Category: Educational ; Style: happy
#include <stdio.h>

// Function to determine if a number is even or odd
int isEven(int num) {
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int start, end;
    printf("Welcome to the Even-Odd game!\n");
    printf("Please enter a starting number: ");
    scanf("%d", &start);
    printf("Please enter an ending number: ");
    scanf("%d", &end);
    printf("Excellent! Let's go.\n\n");

    int i;
    for (i = start; i <= end; i++) {
        if (isEven(i)) {
            printf("%d is even!\n", i);
        } else {
            printf("%d is odd!\n", i);
        }
    }
    printf("\nThanks for playing!\n");

    return 0;
}