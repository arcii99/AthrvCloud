//FormAI DATASET v1.0 Category: Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, num, count = 1;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("\n\t***Number guessing game***\n\n");
    printf("Guess a number between 1 to 100\n");
    do {
        printf("\nGuess %d: ", count++);
        scanf("%d", &guess);
        if (guess > num)
            printf("Too high, try again!");
        else if (guess < num)
            printf("Too low, try again!");
        else {
            printf("\nCongratulations, you guessed it right!");
            break;
        }
    } while (guess != num);
    printf("\nThe number was %d\n", num);
    return 0;
}