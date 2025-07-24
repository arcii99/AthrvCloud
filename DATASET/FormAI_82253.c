//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score = 0; //initial score
    srand(time(0)); //to generate random numbers
    int rand_num = rand() % 10 + 1; //random number between 1 to 10
    
    printf("Welcome to the Terminal Game!\n");
    printf("The objective of the game is to guess a number between 1 to 10.\n");
    printf("You will have 3 attempts.\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Attempt %d: ", i + 1);
        int guess;
        scanf("%d", &guess);
        
        if (guess == rand_num)
        {
            printf("Congratulations! You guessed the number correctly and earned 5 points.\n");
            score += 5;
            printf("Your total score is %d.\n", score);
            break;
        }
        else if (guess > rand_num)
        {
            printf("Your guess is too high. Try again.\n");
        }
        else
        {
            printf("Your guess is too low. Try again.\n");
        }
    }

    if (score == 0)
    {
        printf("Sorry, you couldn't guess the number. The correct answer was %d.\n", rand_num);
    }
    else
    {
        printf("Thanks for playing the game. Your final score is %d.\n", score);
    }

    return 0;
}