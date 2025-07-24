//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int num, guess, attempts = 0;
    srand(time(0)); // generate rand num based on time
    num = rand() % 100 + 1; // random number between 1-100
    
    printf("Guess the number between 1-100\n");
    
    do {
        scanf("%d", &guess);
        attempts++; // increment attempts
        
        if(guess > num) {
            printf("Lower number please!\n");
        } else if(guess < num) {
            printf("Higher number please!\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while(guess != num);
    
    return 0;
}