//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, nguesses = 1;
    srand(time(0));
    num = rand() % 100 + 1;

    printf("\nHey there, let's play a C Table Game!\n");
    printf("I have a number between 1 and 100, and you have to guess it.\n");
    printf("You will get 10 chances to guess the correct number.\n");
    printf("So, what's your first guess? ");

    do {
        scanf("%d", &guess);
        if (guess < num) {
            printf("Your guess is too low. Try again: ");
        } 
        else if (guess > num) {
            printf("Your guess is too high. Try again: ");
        }
        else {
            printf("\nCongratulations! You guessed it in %d attempts.\n", nguesses);
            break;
        }
        nguesses++;
    } while (nguesses <= 10);

    if (nguesses > 10) {
        printf("\nSorry, you lost the game. The number was %d.\n", num);
    }

    printf("\nThanks for playing the C Table Game!\n");

    return 0;
}