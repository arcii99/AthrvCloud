//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
This is a game where the player rolls a dice and moves on a board.
The player starts at position 0 and wins when they reach position 100.
If the player lands on a ladder the player moves to a higher position 
and if the player lands on a snake the player moves to a lower position.
*/

int main() {
    //seed the random number generator with current time
    srand(time(0));
    int player_position = 0;

    while(player_position < 100) {
        //roll dice to determine how many positions to move
        int roll = rand() % 6 + 1;

        //move player to new position 
        player_position += roll;

        // check if player position is more than 100 
        if(player_position > 100) {
            player_position = 100 - (player_position - 100);
        }

        //check if player lands on a ladder or a snake
        switch(player_position) {
            case 4:
                printf("You landed on a ladder and moved to position 14\n");
                player_position = 14;
                break;

            case 9:
                printf("You landed on a ladder and moved to position 31\n");
                player_position = 31;
                break;

            case 17:
                printf("You landed on a ladder and moved to position 7\n");
                player_position = 7;
                break;

            case 20:
                printf("You landed on a snake and moved to position 38\n");
                player_position = 38;
                break;

            case 28:
                printf("You landed on a ladder and moved to position 84\n");
                player_position = 84;
                break;

            case 40:
                printf("You landed on a snake and moved to position 59\n");
                player_position = 59;
                break;

            case 51:
                printf("You landed on a ladder and moved to position 67\n");
                player_position = 67;
                break;

            case 54:
                printf("You landed on a snake and moved to position 34\n");
                player_position = 34;
                break;

            case 62:
                printf("You landed on a snake and moved to position 19\n");
                player_position = 19;
                break;

            case 63:
                printf("You landed on a ladder and moved to position 81\n");
                player_position = 81;
                break;

            case 64:
                printf("You landed on a ladder and moved to position 60\n");
                player_position = 60;
                break;

            case 71:
                printf("You landed on a snake and moved to position 91\n");
                player_position = 91;
                break;

            case 87:
                printf("You landed on a snake and moved to position 24\n");
                player_position = 24;
                break;

            case 93:
                printf("You landed on a snake and moved to position 73\n");
                player_position = 73;
                break;

            case 95:
                printf("You landed on a ladder and moved to position 75\n");
                player_position = 75;
                break;

            case 99:
                printf("You landed on a snake and moved to position 78\n");
                player_position = 78;
                break;

            default:
                // do nothing 
                break;
        }

        printf("You rolled a %d and moved to position %d\n", roll, player_position);
    }

    //player has reached position 100 and won the game 
    printf("Congratulations! You won.\n");
    return 0;
}