//FormAI DATASET v1.0 Category: Funny ; Style: active
#include <stdio.h>

int main() {
    int num1, num2, num3, sum;

    printf("Enter three integers:\n\t");
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("\nCalculating...\n");
    sum = num1 + num2 + num3;

    printf("\n******************\n");
    printf("You entered:\n");
    printf("\t%d\n\t%d\n\t%d\n", num1, num2, num3);
    printf("The sum of the three numbers is %d\n", sum);
    printf("******************\n");

    printf("\nDo you want to play a game?\n");
    printf("Enter 1 for yes or 0 for no:\n");
    int gameChoice;
    scanf("%d", &gameChoice);

    if (gameChoice == 1) {
        printf("Great! Guess my favourite number between 1 to 10:\n");
        int favouriteNumber = 7;
        int playerGuess;
        int attempts = 0;
        scanf("%d", &playerGuess);

        while (playerGuess != favouriteNumber && attempts < 3) {
            printf("Wrong! Guess again:\n");
            scanf("%d", &playerGuess);
            attempts++;
        }

        if (playerGuess == favouriteNumber) {
            printf("You guessed it right! Congrats!\n");
        } else {
            printf("Better luck next time!\n");
        }
    } else {
        printf("Aww, maybe some other time.\n");
    }

    printf("\nThanks for playing!\n");

    return 0;
}