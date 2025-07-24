//FormAI DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_table(int table[], int size);
void roll_dice(int dice[]);
int calculate_score(int dice[]);
void play_game();

int main()
{
    srand(time(NULL));  // seed random number generator

    // Welcome screen
    printf("Welcome to the Futuristic C Table Game!\n\n");
    printf("In this game, you will roll two dice and try to get the highest score possible.\n");
    printf("The table has 10 rows with different scores. Each time you roll the dice, you will\n");
    printf("choose which row to place your score in. You cannot use the same row twice.\n");
    printf("The player with the highest total score at the end wins!\n\n");

    // Game loop
    char play_again = 'y';
    while (play_again == 'y')
    {
        play_game();

        // Ask if the player wants to play again
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &play_again);
    }

    printf("\nThanks for playing!\n");

    return 0;
}

void print_table(int table[], int size)
{
    printf("\n");

    // Print each row of the table
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", table[i]);
    }

    printf("\n");
}

void roll_dice(int dice[])
{
    // Roll two six-sided dice
    dice[0] = rand() % 6 + 1;
    dice[1] = rand() % 6 + 1;
}

int calculate_score(int dice[])
{
    // Calculate the score based on the sum of the dice
    return dice[0] + dice[1];
}

void play_game()
{
    int table[10] = {0};  // Initialize table with zeros
    int dice[2];
    int total_score = 0;

    printf("\nNew game!\n");

    // Loop for 10 rounds
    for (int round = 1; round <= 10; round++)
    {
        // Roll the dice
        roll_dice(dice);

        // Print the dice
        printf("Round %d: You rolled a %d and a %d.\n", round, dice[0], dice[1]);

        // Print the table
        print_table(table, 10);

        // Ask the player where they want to place their score
        int choice = 0;
        while (table[choice] != 0 || choice < 1 || choice > 10)
        {
            printf("Choose which row to place your score (1-10): ");
            scanf("%d", &choice);
        }

        // Calculate the score and add it to the table
        int score = calculate_score(dice);
        printf("You scored %d points.\n", score);
        table[choice - 1] = score;

        // Calculate the total score
        total_score += score;
    }

    // Print the final table and total score
    printf("\nFinal table:\n");
    print_table(table, 10);
    printf("Total score: %d\n", total_score);
}