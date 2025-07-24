//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Puzzle answer: CALCIUM (symbol Ca)
    char answer[10] = "CALCIUM";
    char guess[10];
    int attempts = 0, maxAttempts = 5;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You have to guess the symbol of an element based on its atomic number.\n");
    printf("You have five attempts to guess.\n");

    // Element 20
    printf("\nAtomic number 20: ");
    printf("This element's name comes from the Latin word for lime.");
    printf("\nClue: C_ _ _ _ _ M\n");
    
    while (attempts < maxAttempts) {
        printf("Enter your guess: ");
        scanf("%s", guess);

        if (strcmp(answer, guess) == 0) {
            printf("\nCongratulations, you have solved the puzzle and won the game!");
            return 0;
        } else {
            attempts++;
            printf("Sorry, that is incorrect. You have %d attempt(s) left.\n", (maxAttempts - attempts));
        }
    }

    printf("\nGame over. The answer was %s.\n", answer);

    return 0;
}