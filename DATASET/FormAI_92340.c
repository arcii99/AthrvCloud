//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int number, guess, attempts=1;
    srand(time(0));
    number = rand()%100 + 1;                  //generating random number between 1 to 100

    printf("\nWelcome to the guessing game!\n");
    printf("Guess the number between 1 to 100.\n");

    do{
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        if(guess<number)
        {
            printf("Higher number please!\n");
        }
        else if(guess>number)
        {
            printf("Lower number please!\n");
        }
        else{
            printf("Congratulations! You have guessed the right number in %d attempts.\n", attempts);
        }
        attempts++;

    }while(guess!=number);

    printf("\nThank you for playing the game!\n");
    return 0;
}