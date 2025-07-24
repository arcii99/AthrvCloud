//FormAI DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess;
    int attempt = 0;
    int rightAnswer;
    
    srand(time(0)); // Generate different random numbers each time the program runs
    
    rightAnswer = rand() % 100; // Setting the range between 0 and 100
    
    printf("Guess the number between 0 and 100.\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess); // Reading the user's guess input

        if (guess < rightAnswer) {
            printf("Too low! Guess again.\n");
            attempt++;
        }
        else if (guess > rightAnswer) {
            printf("Too high! Guess again.\n");
            attempt++;
        }
        else {
            attempt++;
            printf("Congratulations! You got it right in %d attempts.\n", attempt);
        }

    } while (guess != rightAnswer);
    
    return 0;
}