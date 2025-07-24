//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random number
int randNumber(int n) {
    srand(time(NULL));
    return rand() % n;
}

int main() {
    int n, guess, attempts=1;
    printf("Welcome to the Number Guessing Game!\n\n");
    printf("Enter the maximum range of the random number (between 1 and 1000): ");
    scanf("%d", &n);
    int number = randNumber(n);
    printf("\nGuess the number between 1 and %d\n", n);

    //Game Loop
    do {
        printf("Attempt %d: ", attempts);
        scanf("%d", &guess);

        if(guess > number) {
            printf("Try guessing a smaller number.\n");
        } else if(guess < number) {
            printf("Try guessing a higher number.\n");   
        } else {
            printf("Congratulations! You have guessed the correct number in %d attempts!\n", attempts);
            break;
        }
        attempts++;
    } while(guess != number);

    printf("\nThe correct number was %d\n", number);
    return 0;
}