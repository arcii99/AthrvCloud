//FormAI DATASET v1.0 Category: Funny ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int guess = 0;
    int answer = rand() % 100;
    int attempts = 0;
    printf("I'm thinking of a number between 0 and 100... can you guess what it is?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        if(guess < answer) {
            printf("Higher!\n");
        } else if(guess > answer) {
            printf("Lower!\n");
        }
    } while(guess != answer);

    printf("You got it! It took you %d attempts to guess my number, which was %d.", attempts, answer);

    return 0;
}