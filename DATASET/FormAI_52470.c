//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

int recursiveFunction(int number) {
    if (number == 0) {
        printf("You've reached the end of the recursion. Congratulations!\n");
        return 0;
    }
    else {
        printf("Current number: %d\n", number);
        printf("Just keep going, you're doing great!\n");
        recursiveFunction(number - 1);
    }
}

int main() {
    printf("Welcome to the recursive function!\n");
    printf("Enter a number to start the recursion: ");

    int input;
    scanf("%d", &input);

    printf("Starting recursion with number %d...\n", input);

    recursiveFunction(input);

    printf("Thanks for using the recursive function! Have a great day!\n");
    return 0;
}