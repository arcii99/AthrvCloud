//FormAI DATASET v1.0 Category: Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, count = 0;
    srand(time(0));
    num = rand()%100 + 1; //generating random number between 1 and 100
    printf("Welcome to the number guessing game!\n");
    printf("Guess the number between 1 and 100\n");
    do {
        printf("Enter your guess:");
        scanf("%d", &guess);
        count++; //incrementing the count of total guesses
        if(guess > num) {
            printf("Too high! Try again.\n");
        }
        else if(guess < num) {
            printf("Too low! Try again.\n");
        }
        else {
            printf("Congratulations! You have guessed the number in %d attempts.\n", count);
        }
    } while(guess != num);
    return 0;
}