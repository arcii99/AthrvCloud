//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, tries=0;
    srand(time(NULL));
    secret_number = rand() % 100;
    
    printf("Welcome to the guessing game!\n");
    printf("I have a number between 1 and 100. Can you guess it?\n");
    
    do {
        printf("Guess a number: ");
        scanf("%d", &guess);
        tries++;
        
        if (guess > secret_number) {
            printf("Lower!\n");
        } else if (guess < secret_number) {
            printf("Higher!\n");
        } else {
            printf("Congratulations! You guessed my number in %d tries!\n", tries);
        }
    } while (guess != secret_number);
    
    return 0;
}