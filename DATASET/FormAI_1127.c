//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
int play_game(void);

int main(void)
{
    char ch;

    srand((unsigned) time(NULL)); // seed random number generator

    printf("Welcome to the C Table Game!\n");
    printf("Press 'enter' to start, or 'q' to quit.\n");

    while ((ch = getchar()) != 'q')
    {
        if (ch == '\n')
        {
            int result = play_game();
            if (result)
                printf("You win!\n");
            else
                printf("You lose!\n");

            printf("\nPress 'enter' to play again, or 'q' to quit.\n");
        }
    }

    printf("\nThanks for playing!\n");

    return 0;
}

int roll_dice(void)
{
    return (rand() % 6) + 1;
}

int play_game(void)
{
    int roll1, roll2, sum;

    roll1 = roll_dice();
    roll2 = roll_dice();
    sum = roll1 + roll2;

    printf("You rolled: %d + %d = %d\n", roll1, roll2, sum);

    if (sum == 7 || sum == 11)
        return 1;
    else if (sum == 2 || sum == 3 || sum == 12)
        return 0;

    int point = sum;
    printf("Your point is %d\n", point);

    while (1)
    {
        roll1 = roll_dice();
        roll2 = roll_dice();
        sum = roll1 + roll2;

        printf("You rolled: %d + %d = %d\n", roll1, roll2, sum);

        if (sum == point)
            return 1;
        else if (sum == 7)
            return 0;
    }
}