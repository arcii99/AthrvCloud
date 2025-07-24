//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lower, upper, num, attempts = 0, guess;
    printf("Enter the lower limit of the range: ");
    scanf("%d", &lower);
    printf("Enter the upper limit of the range: ");
    scanf("%d", &upper);
    printf("Enter a number between %d and %d for the computer to guess: ", lower, upper);
    scanf("%d", &num);
    srand(time(0));
    guess = (rand() % (upper - lower + 1)) + lower;
    while (guess != num) {
        attempts++;
        if (guess < num) {
            printf("The computer's guess is too low, try again!\n");
            lower = guess + 1;
        }
        else if (guess > num) {
            printf("The computer's guess is too high, try again!\n");
            upper = guess - 1;
        }
        guess = (rand() % (upper - lower + 1)) + lower;
    }
    printf("Congratulations! The computer guessed the number %d in %d attempts.\n", num, attempts);
    return 0;
}