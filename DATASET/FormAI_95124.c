//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>

void countdown(int num) {
    if (num == 0) {
        printf("Liftoff!\n");
    } else {
        printf("%d\n", num);
        countdown(num - 1);
    }
}

int main() {
    int startNum;
    printf("Welcome to the countdown program!\n");
    printf("Enter a positive integer to start the countdown: ");
    scanf("%d", &startNum);

    if (startNum <= 0) {
        printf("Invalid input, please enter a positive integer.\n");
        return 1;
    }

    printf("Starting countdown from %d...\n", startNum);
    countdown(startNum);

    return 0;
}