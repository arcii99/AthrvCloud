//FormAI DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 to 6
int rollDice()
{
    return (rand() % 6) + 1;
}

// Main function
int main()
{
    // Seed random number generator
    srand(time(0));

    // Initialize players' positions to 0
    int player1 = 0, player2 = 0;

    while(player1 < 100 && player2 < 100) // Game continues till any player reaches 100
    {
        // Player 1's turn
        int dice1 = rollDice();
        int dice2 = rollDice();
        int sum1 = dice1 + dice2;
        printf("Player 1 rolled %d and %d, total score: %d\n", dice1, dice2, sum1);

        // Check if player 1 got a double
        if(dice1 == dice2)
        {
            printf("Player 1 got a double! Roll the dice again.\n");
            int dice3 = rollDice();
            int dice4 = rollDice();
            int sum2 = dice3 + dice4;
            printf("Player 1 rolled %d and %d, total score: %d\n", dice3, dice4, sum2);
            sum1 += sum2; // Add the sum of both rolls to total score
        }

        player1 += sum1; // Update player 1's position

        // Check if player 1 landed on a ladder
        if(player1 == 8)
        {
            player1 = 15;
            printf("Player 1 landed on a ladder and climbed up to %d\n", player1);
        }
        else if(player1 == 21)
        {
            player1 = 42;
            printf("Player 1 landed on a ladder and climbed up to %d\n", player1);
        }
        else if(player1 == 28)
        {
            player1 = 84;
            printf("Player 1 landed on a ladder and climbed up to %d\n", player1);
        }
        else if(player1 == 50)
        {
            player1 = 69;
            printf("Player 1 landed on a ladder and climbed up to %d\n", player1);
        }
        else if(player1 == 71)
        {
            player1 = 91;
            printf("Player 1 landed on a ladder and climbed up to %d\n", player1);
        }
        else if(player1 == 87)
        {
            player1 = 98;
            printf("Player 1 landed on a ladder and climbed up to %d\n", player1);
        }

        // Check if player 1 landed on a snake
        if(player1 == 16)
        {
            player1 = 6;
            printf("Player 1 landed on a snake and slid down to %d\n", player1);
        }
        else if(player1 == 31)
        {
            player1 = 19;
            printf("Player 1 landed on a snake and slid down to %d\n", player1);
        }
        else if(player1 == 48)
        {
            player1 = 26;
            printf("Player 1 landed on a snake and slid down to %d\n", player1);
        }
        else if(player1 == 56)
        {
            player1 = 39;
            printf("Player 1 landed on a snake and slid down to %d\n", player1);
        }
        else if(player1 == 64)
        {
            player1 = 60;
            printf("Player 1 landed on a snake and slid down to %d\n", player1);
        }
        else if(player1 == 93)
        {
            player1 = 73;
            printf("Player 1 landed on a snake and slid down to %d\n", player1);
        }
        else if(player1 == 95)
        {
            player1 = 75;
            printf("Player 1 landed on a snake and slid down to %d\n", player1);
        }
        else if(player1 == 98)
        {
            player1 = 77;
            printf("Player 1 landed on a snake and slid down to %d\n", player1);
        }

        // Display player 1's position after the turn
        printf("Player 1's current position: %d\n", player1);

        // Check if player 1 won the game
        if(player1 >= 100)
        {
            printf("Player 1 won the game!\n");
            break; // End game loop
        }

        // Player 2's turn
        int dice5 = rollDice();
        int dice6 = rollDice();
        int sum3 = dice5 + dice6;
        printf("Player 2 rolled %d and %d, total score: %d\n", dice5, dice6, sum3);

        // Check if player 2 got a double
        if(dice5 == dice6)
        {
            printf("Player 2 got a double! Roll the dice again.\n");
            int dice7 = rollDice();
            int dice8 = rollDice();
            int sum4 = dice7 + dice8;
            printf("Player 2 rolled %d and %d, total score: %d\n", dice7, dice8, sum4);
            sum3 += sum4; // Add the sum of both rolls to total score
        }

        player2 += sum3; // Update player 2's position

        // Check if player 2 landed on a ladder
        if(player2 == 8)
        {
            player2 = 15;
            printf("Player 2 landed on a ladder and climbed up to %d\n", player2);
        }
        else if(player2 == 21)
        {
            player2 = 42;
            printf("Player 2 landed on a ladder and climbed up to %d\n", player2);
        }
        else if(player2 == 28)
        {
            player2 = 84;
            printf("Player 2 landed on a ladder and climbed up to %d\n", player2);
        }
        else if(player2 == 50)
        {
            player2 = 69;
            printf("Player 2 landed on a ladder and climbed up to %d\n", player2);
        }
        else if(player2 == 71)
        {
            player2 = 91;
            printf("Player 2 landed on a ladder and climbed up to %d\n", player2);
        }
        else if(player2 == 87)
        {
            player2 = 98;
            printf("Player 2 landed on a ladder and climbed up to %d\n", player2);
        }

        // Check if player 2 landed on a snake
        if(player2 == 16)
        {
            player2 = 6;
            printf("Player 2 landed on a snake and slid down to %d\n", player2);
        }
        else if(player2 == 31)
        {
            player2 = 19;
            printf("Player 2 landed on a snake and slid down to %d\n", player2);
        }
        else if(player2 == 48)
        {
            player2 = 26;
            printf("Player 2 landed on a snake and slid down to %d\n", player2);
        }
        else if(player2 == 56)
        {
            player2 = 39;
            printf("Player 2 landed on a snake and slid down to %d\n", player2);
        }
        else if(player2 == 64)
        {
            player2 = 60;
            printf("Player 2 landed on a snake and slid down to %d\n", player2);
        }
        else if(player2 == 93)
        {
            player2 = 73;
            printf("Player 2 landed on a snake and slid down to %d\n", player2);
        }
        else if(player2 == 95)
        {
            player2 = 75;
            printf("Player 2 landed on a snake and slid down to %d\n", player2);
        }
        else if(player2 == 98)
        {
            player2 = 77;
            printf("Player 2 landed on a snake and slid down to %d\n", player2);
        }

        // Display player 2's position after the turn
        printf("Player 2's current position: %d\n", player2);

        // Check if player 2 won the game
        if(player2 >= 100)
        {
            printf("Player 2 won the game!\n");
            break; // End game loop
        }
    }

    return 0;
}