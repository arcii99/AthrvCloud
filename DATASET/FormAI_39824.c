//FormAI DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 123; // secret number
    int guess;
    int tries = 0;

    printf("Welcome to the guessing game!\n");
    printf("You have three tries to guess the secret number.\n");
    printf("Be careful, too many wrong guesses may trigger alarms...\n");

    while (tries < 3) {
        printf("Please enter your guess: ");
        scanf("%d", &guess);

        if (guess == x) {
            printf("Congratulations! You guessed the secret number.\n");
            break;
        } else {
            printf("Sorry, that's not the right number. Try again.\n");
        }

        tries++;

        if (tries == 2) {
            printf("Warning: You have one guess left. Be careful...\n");
        } else if (tries == 3) {
            printf("ERROR: Too many incorrect guesses. Initiating lockdown protocol...\n");
            printf("Deleting sensitive files... ");
            for (int i = 0; i < 10; i++) {
                printf("%d%% ", i * 10);
                sleep(1);
            }
            printf("\nDone.\n");
            printf("Self-destruct sequence engaged... ");
            for (int i = 0; i < 10; i++) {
                printf("%d ", 10 - i);
                sleep(1);
            }
            printf("\n");
            exit(1);
        }
    }
    return 0;
}