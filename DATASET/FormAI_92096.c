//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the exciting game of Guess the Number!\n");
    printf("I have a number between 1 and 1000. Can you guess what it is?\n");
    
    srand(time(NULL));
    int number = rand() % 1000 + 1;
    int guess;
    int attempts = 0;
    
    do {
        attempts++;
        printf("Guess #%d: ", attempts);
        scanf("%d", &guess);
        
        if (guess < number) {
            printf("Too low! Guess higher.\n");
        } else if (guess > number) {
            printf("Too high! Guess lower.\n");
        } else {
            printf("Congratulations, you guessed the number in %d attempts!\n", attempts);
        }
    } while(guess != number);
    
    return 0;
}