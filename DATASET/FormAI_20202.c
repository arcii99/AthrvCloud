//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, num, count=0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("\n\t***WELCOME TO GUESSING GAME***\n\n");
    printf("Guess a number between 1 to 100:");
    do {
        scanf("%d", &guess);
        count++;
        if (guess > num) {
            printf("Sorry, try again! Your guess is too high.\n");
        }
        else if (guess < num) {
            printf("Sorry, try again! Your guess is too low.\n");
        }
        else {
            printf("\n\n\t***CONGRATULATIONS! You have guessed the number correctly.***\n");
            printf("\t\t\tyou have guessed in %d attempts\n", count);
        }
    } while (guess != num);
    return 0;
}