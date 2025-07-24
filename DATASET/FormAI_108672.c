//FormAI DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess;
    int chances = 5;
    int count = 0;
    srand(time(0));
    number = rand() % 50 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("You have %d chances to guess the number between 1 and 50\n", chances);
    
    do {
        printf("Guess the number: ");
        scanf("%d", &guess);
        count++;
        
        if (guess > number) {
            printf("Too high! You have %d chances left\n", chances-count+1);
        }
        if (guess < number) {
            printf("Too low! You have %d chances left\n", chances-count+1);
        }
    } while (guess != number && count < 5);

    if (guess == number) {
        printf("Congratulations! You guessed the number in %d tries\n", count);
    } else {
        printf("Sorry! You did not guess the number. The number was %d\n", number);
    }
    
    return 0;
}