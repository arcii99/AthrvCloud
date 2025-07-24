//FormAI DATASET v1.0 Category: Random ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int rand_num = rand() % 100 + 1;
    printf("I have a secret number, can you guess what it is?\n");
    int guess;
    int tries = 0;
    
    do {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        tries++;

        if (guess < rand_num) {
            printf("Too low, try again!\n");
        } else if (guess > rand_num) {
            printf("Too high, try again!\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != rand_num);

    return 0;
}