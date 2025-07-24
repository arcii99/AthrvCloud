//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, answer, attempts = 0;
    char choice;
    srand(time(NULL));
    answer = rand() % 100 + 1;
    printf("I'm thinking of a number between 1 and 100...\n");
    do {
        printf("Take a guess: ");
        scanf("%d", &guess);
        attempts++;
        if (guess < answer) {
            printf("Too low! Try again.\n");
        } else if (guess > answer) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                attempts = 0;
                answer = rand() % 100 + 1;
                printf("I'm thinking of a number between 1 and 100...\n");
            }
        }
    } while (guess != answer || (choice == 'y' || choice == 'Y'));
    printf("Thanks for playing!\n");
    return 0;
}