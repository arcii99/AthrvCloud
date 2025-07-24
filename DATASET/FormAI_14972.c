//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to our happy error handling program!\n");

    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    if(number < 0) {
        printf("Oops! The number you entered is negative. Let's handle this error.\n");

        // Handling negative number error
        printf("Error Code: %d\n", 100);
        printf("Error Message: Negative number entered. Please enter a positive number.\n");
        exit(100);
    }

    int result = 100 / number;
    printf("The result after dividing 100 by %d is: %d\n", number, result);

    printf("Thanks for using our happy error handling program! No errors were found.\n");

    return 0;
}