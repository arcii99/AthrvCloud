//FormAI DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int answer, guess, count;
    srand(time(NULL));
    answer = rand() % 100 + 1; // generate a random number between 1 and 100
    count = 0;

    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;
        if (guess < answer){
            printf("Too low. Try again.\n");
        } else if (guess > answer){
            printf("Too high. Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries!\n", count);
        }
    } while (guess != answer);

    return 0;
}