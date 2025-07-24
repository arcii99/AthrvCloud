//FormAI DATASET v1.0 Category: Math exercise ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, secretNum;
    int lowerBound = 1, upperBound = 10;
   
    srand(time(0));
    secretNum = rand() % (upperBound - lowerBound + 1) + lowerBound;
    
    printf("I am thinking of a number between %d and %d... Can you guess what it is?\n", lowerBound, upperBound);
    
    do {
        printf("Make your guess: ");
        scanf("%d", &guess);

        if (guess < secretNum) {
            printf("Your guess is too low! Try again!\n");
        } else if (guess > secretNum) {
            printf("Your guess is too high! Try again!\n");
        }
    } while (guess != secretNum);

    printf("Congratulations! You have guessed the correct number - %d!\n", secretNum);

    return 0;
}