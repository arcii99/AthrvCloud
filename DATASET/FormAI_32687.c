//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int steps = 0; //Number of steps taken by player
    int position = 0; //Current position of player on board
    int finish = 25; //Finish position
    int board[26] = {0}; //Initial board with all values set to 0
    srand(time(NULL)); //Seed for random number generator

    //Add some random traps and ladders to board
    board[3] = 5; board[6] = -3; board[9] = 2; board[10] = -4;
    board[14] = 3; board[18] = -2; board[22] = 4; board[24] = -5;

    printf("Welcome to Snakes and Ladders! Let's get started.\n");

    while (position < finish) { //Loop until player reaches finish position
        steps++; //Increment the number of steps taken by player
        int roll = (rand() % 6) + 1; //Roll the dice
        printf("You rolled a %d!\n", roll);
        position += roll; //Update position of player

        //Check if player has crossed finish position
        if (position > finish) {
            position = finish - (position - finish);
        }

        //Check if player has landed on a trap or ladder
        int change = board[position];
        if (change != 0) {
            position += change;
            if (change > 0) {
                printf("You've landed on a ladder! You move up %d spaces.\n", change);
            } else {
                printf("You've landed on a snake! You move down %d spaces.\n", abs(change));
            }
        }

        printf("You are at position %d.\n", position); //Print current position of player
    }

    printf("Congratulations! You've reached the finish in %d steps.\n", steps);

    return 0; //End program
}