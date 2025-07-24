//FormAI DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    int numTry = 0, guess, num;
    srand(time(0)); 

    printf("Welcome to C Math Exercise Example Program!\n");
    printf("How many tries do you want?\n");
    scanf("%d", &numTry);
    printf("I'm thinking of a number between 1 and 100. Can you guess it in %d tries?\n", numTry);

    num = rand() % 100 + 1;

    for(int i = 1; i <= numTry; i++) {
        printf("Guess %d: ", i);
        scanf("%d", &guess);

        if(guess == num) {
            printf("Amazing! You guessed it right in %d tries!\n", i);
            break;
        } 
        else if(guess < num) {
            printf("That's too low. Try again.\n");
        }
        else {
            printf("That's too high. Try again.\n");
        }

        if(i == numTry) {
            printf("Sorry, you didn't guess it in %d tries. The answer was %d.\n", numTry, num);
        }
    }

    return 0;
}