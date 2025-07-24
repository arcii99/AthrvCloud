//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, count = 0;
    char choice;

    do {
        srand(time(NULL));
        num = rand() % 100 + 1;

        printf("Guess the number between 1 and 100: ");
        while (1) {
            scanf("%d", &guess);
            count++;

            if (guess == num) {
                printf("Congratulations! You guessed the number in %d tries.\n", count);
                break;
            } else if (guess < num) {
                printf("Try higher. Guess again: ");
            } else {
                printf("Try lower. Guess again: ");
            }
        }

        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'n') {
            printf("Invalid choice! Exiting the game...\n");
            break;
        }

        count = 0;
    } while (choice == 'y');

    printf("Thank you for playing! Goodbye.\n");

    return 0;
}