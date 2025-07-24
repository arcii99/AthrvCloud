//FormAI DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int guess;
    int attempts = 0;
    int number;
    srand(time(0));
    number = rand() % 100;
    printf("You need to guess a number between 0 and 100. You have five attempts. Good luck!\n");

    while(attempts < 5) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if(guess == number) {
            printf("Congratulations! You have guessed the number correctly!\n");
            break;
        } else if(guess < number) {
            printf("Your guess is too low. Try again.\n");
        } else if(guess > number) {
            printf("Your guess is too high. Try again.\n");
        }
        attempts++;
    }

    if(attempts == 5) {
        printf("Sorry, you have used up all your attempts. The correct number was %d.\n", number);
    }

    return 0;
}