//FormAI DATASET v1.0 Category: Error handling ; Style: Claude Shannon
/* 
    C Error Handling Example Program 
    Claude Shannon Style 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random integer between 1 and 10
    int num = rand() % 10 + 1;
    
    // Prompt the user to guess the number
    printf("Guess a number between 1 and 10: ");
    int guess;
    scanf("%d", &guess);
    
    // Compare the user's guess to the randomly generated number
    if (guess == num) {
        printf("Congratulations! You guessed the number!\n");
    } else {
        // If the guess is incorrect, throw an error
        printf("ERROR: Invalid guess. The number was %d.\n", num);
        exit(EXIT_FAILURE);
    }
    
    return 0;
}