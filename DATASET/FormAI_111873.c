//FormAI DATASET v1.0 Category: Memory Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_GUESSES 5

int main() {

    srand(time(NULL)); // initializing random seed

    int target_num = rand() % MAX_NUM + 1; // generates the random target number
    int num_guesses = 0; // keep track of number of guesses made
    int guess; // variable to store the guess made by user

    printf("Welcome to the Memory Game! The target number is between 1 and %d\n", MAX_NUM);

    while (num_guesses < MAX_GUESSES) {

        printf("Enter your guess: ");
        scanf("%d", &guess); // get the guess from user

        if (guess < target_num) {
            printf("Your guess is too low.\n");
        } else if (guess > target_num) {
            printf("Your guess is too high.\n");
        } else {
            printf("Congratulations! You got the number in %d guesses.\n", num_guesses+1);
            return 0; // end the program
        }

        num_guesses++;

    }

    printf("Sorry, you couldn't guess the number. The target number was %d.\n", target_num);

    return 0;

}