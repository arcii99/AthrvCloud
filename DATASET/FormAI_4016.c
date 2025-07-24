//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    int num;
    int guess;
    int count = 0;
 
    srand(time(NULL)); 
 
    num = rand() % 100 + 1;
 
    printf("             Welcome to the Guessing Game!\n\n");
 
    printf("      I have chosen a number between 1 and 100.\n");
    printf("    You have to guess the number correctly in less than 10 tries.\n\n");
 
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;
 
        if (guess > num) {
            printf("Too high! Guess lower.\n\n");
        }
        else if (guess < num) {
            printf("Too low! Guess higher.\n\n");
        }
        else {
            printf("\nCongratulations! You have guessed the number in %d tries.\n", count);
        }
 
    } while (guess != num && count < 10);
 
    printf("\nThe number I was thinking of was %d.\n", num);
    printf("Thank you for playing the Guessing Game!\n\n");
 
    return 0;
}