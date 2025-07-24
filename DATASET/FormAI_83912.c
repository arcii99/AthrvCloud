//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h> 

int main() {
    printf("Welcome to my C error handling program!\n");

    int numerator, denominator;

    printf("Enter the numerator: ");
    if(scanf("%d", &numerator) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        return 1; // return error code 1
    }

    printf("Enter the denominator: ");
    if(scanf("%d", &denominator) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        return 1; // return error code 1
    }

    if(denominator == 0) {
        printf("Division by zero error!\n");
        return 2; // return error code 2
    }

    int result = numerator / denominator;

    printf("%d / %d = %d\n", numerator, denominator, result);

    printf("Thanks for trying out my program! Come back soon!\n");

    return 0; // return success code 0
}