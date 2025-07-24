//FormAI DATASET v1.0 Category: Random ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // this line ensures random values everytime the program is executed
    int randomNumber = rand() % 100; // generates a random integer from 0 to 99
    printf("Guess a number between 0 and 99: ");
    int guess;

    do {
        scanf("%d", &guess);
        if(guess > randomNumber) {
            printf("Your guess is too high. Guess again: ");
        } else if(guess < randomNumber) {
            printf("Your guess is too low. Guess again: ");
        }
    } while(guess != randomNumber);

    printf("Congratulations, you guessed the number %d correctly!", randomNumber);
    return 0;
}