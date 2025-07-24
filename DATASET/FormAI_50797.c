//FormAI DATASET v1.0 Category: Error handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    printf("Welcome to the error handling program!\n");
    printf("Please enter a number between 1 and 10: ");

    int num;
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Error: Invalid input\n");
        exit(EXIT_FAILURE);
    }

    if (num < 1 || num > 10) {
        errno = EINVAL;
        perror("Error");
        exit(EXIT_FAILURE);
    }

    printf("Congratulations, you entered a valid number: %d\n", num);

    printf("Now, let's divide 10 by your number and see what happens:\n");

    int result;
    if (num == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }
    result = 10 / num;

    printf("The result is: %d\n", result);

    printf("Thanks for using the error handling program!\n");

    return 0;
}