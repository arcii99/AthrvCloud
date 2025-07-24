//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A simple program that generates a random number between 1 and 100 and asks the user to guess the number.
 * The program also keeps track of the number of guesses the user takes to correctly guess the number.
 * This program demonstrates a performance-critical component since it requires the use of a random number generator and user input.
 */

int main() {
    int number, guess, attempt = 1;
    
    srand(time(NULL)); // seed the random number generator with the current time
    
    number = rand() % 100 + 1; // generate a random number between 1 and 100
    
    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n\n");

    do {
        printf("Guess #%d: ", attempt);
        scanf("%d", &guess);
        
        if (guess < number) {
            printf("Too low!\n\n");
            attempt++;
        } 
        else if (guess > number) {
            printf("Too high!\n\n");
            attempt++;
        } 
        else {
            printf("Congratulations! You guessed the number in %d attempts!\n", attempt);
        }
    } while (guess != number);
    
    return 0;
}