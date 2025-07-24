//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int random_num, input_num, guess_count = 0;
    srand(time(0)); //seeding the random number generator

    printf("\nWelcome to the Guessing Game!\n");
    printf("I am thinking of a number between 1 to 100\n");
    printf("Can you guess it?\n");

    random_num = (rand() % 100) + 1; //generating a random number between 1 to 100

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &input_num);
        guess_count++;

        if(input_num < random_num)
            printf("Your guess is too low! Try again.\n");
        else if(input_num > random_num)
            printf("Your guess is too high! Try again.\n");
        else
            printf("\nCongratulations! You guessed the number in %d attempts!\n", guess_count);

    } while(input_num != random_num);

    printf("\nThank you for playing the Guessing Game!\n");

       return 0;
}