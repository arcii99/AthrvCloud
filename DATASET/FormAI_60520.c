//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int main() {
    int num, guess, attempt = 0;
    srand(time(0)); 
    num = rand() % 100 + 1; 
    printf("Welcome to the Guessing Game! Guess the number between 1 to 100\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempt++;

        if(guess > num) {
            printf("Wrong answer, too high! Guess again.\n");
        } else if (guess < num) {
            printf("Wrong answer, too low! Guess again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts!\n", attempt);
        }

    } while (guess != num);

    return 0; 
}