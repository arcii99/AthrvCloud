//FormAI DATASET v1.0 Category: Math exercise ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int num = rand()%100; // Generate a random number between 0-99
    int ans, guess;
    int attempt = 1; // Keep track of number of attempts

    // Prompt user for input and check if it's an integer
    do {
        printf("Guess the square root of %d: ", num);
    } while (scanf("%d", &guess) != 1);

    // Calculate the correct answer using math library
    ans = sqrt(num);

    // While loop until correct answer is guessed
    while (guess != ans) {
        attempt++; // Increment number of attempts
        if (guess < ans) {
            printf("Too low, try again!\n");
        } else {
            printf("Too high, try again!\n");
        }
        do {
            printf("Attempt %d. Guess the square root of %d: ", attempt, num);
        } while (scanf("%d", &guess) != 1);
    }

    // If correct answer guessed, print congratulations message
    if (guess == ans) {
        printf("Congratulations! You guessed the square root of %d in %d attempt(s)!\n", num, attempt);
    }

    return 0;
}