//FormAI DATASET v1.0 Category: Data validation ; Style: content
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int min = 1;
    int max = 100;

    printf("Enter a number between %d and %d: ", min, max);
    while(scanf("%d", &num) != 1 || num < min || num > max) {
        // if input is not an integer or not within range
        printf("Invalid input. Please enter an integer between %d and %d: ", min, max);

        // flush input buffer to prevent infinite loop
        while(getchar() != '\n');
    }

    // valid input is received
    printf("You entered: %d", num);

    return 0;
}