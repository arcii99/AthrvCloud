//FormAI DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Error Handling program!\n");

    char input_string[10];

    printf("Enter a number between 1 and 10: ");
    fgets(input_string, 10, stdin);
    int num = atoi(input_string);

    if (num < 1 || num > 10) {
        printf("Oops! %d is not between 1 and 10.\n", num);
        printf("But don't worry, I've got this.\n");

        // Error handling
        for (int i = 0; i <= num; i++) {
            if (i == num) {
                printf("Phew! That was a close one, but we made it!\n");
            }
        }

        return 0;
    }

    printf("Great choice! You picked %d.\n", num);
    printf("This number is perfect for our happy little program.\n");

    // More happy code here

    return 0;
}