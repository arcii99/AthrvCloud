//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, count = 0;
    int randomNumber;

    srand(time(0));
    randomNumber = rand() % 100 + 1;

    printf("Guess the number: ");

    do {
        scanf("%d", &guess);
        count++;
        if(guess > randomNumber) {
            printf("Too high! Guess again: ");
        } else if(guess < randomNumber) {
            printf("Too low! Guess again: ");
        } else {
            printf("Congratulations! You guessed the number in %d tries!\n", count);
        }
    } while(guess != randomNumber);
    
    return 0;
}