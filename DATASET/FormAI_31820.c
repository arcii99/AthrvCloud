//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rooms[5][5]; //2D array to store the rooms in the haunted house
    int player_x = 0; //starting x-coordinate of the player
    int player_y = 0; //starting y-coordinate of the player
    int player_health = 100; //starting health of the player
    int ghost_x = 0; //x-coordinate of the ghost
    int ghost_y = 0; //y-coordinate of the ghost
    int ghost_health = 100; //health of the ghost
    int end_x = 4; //x-coordinate of the exit room
    int end_y = 4; //y-coordinate of the exit room 
    int num_moves = 0; //number of moves made by the player
    char move; //the move selected by the player
    char play_again; //if the player wants to play again

    srand(time(NULL)); //initialize random number generator with current time

    //initialize all rooms as unvisited
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            rooms[i][j] = 0;
        }
    }

    //randomly place the ghost in a room
    ghost_x = rand() % 5;
    ghost_y = rand() % 5;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have %d health points and there is a ghost with %d health points somewhere in the house.\n", player_health, ghost_health);
    printf("Type 'x' to exit the game at any time.\n");
    printf("Good luck!\n");

    while(1) {
        //display the current room and options
        printf("\nYou are in room %d,%d with %d health points.\n", player_x, player_y, player_health);
        if(player_x == ghost_x && player_y == ghost_y) {
            printf("You hear ghostly whispers in the darkness...\n");
        } else {
            printf("You hear eerie sounds in the distance...\n");
        }
        printf("Select your move: [n]orth, [s]outh, [e]ast, [w]est, [q]uit: ");
        scanf(" %c", &move);

        //check if player input a valid move
        if(move == 'n' && player_y > 0) {
            player_y--;
            num_moves++;
        } else if(move == 's' && player_y < 4) {
            player_y++;
            num_moves++;
        } else if(move == 'e' && player_x < 4) {
            player_x++;
            num_moves++;
        } else if(move == 'w' && player_x > 0) {
            player_x--;
            num_moves++;
        } else if(move == 'q' || move == 'x') {
            printf("Thanks for playing!\n");
            return 0;
        } else {
            printf("Invalid move. Try again.\n");
            continue;
        }

        //check if player ran into ghost
        if(player_x == ghost_x && player_y == ghost_y) {
            printf("You run into the ghost!\n");

            //fight sequence
            while(player_health > 0 && ghost_health > 0) {
                int player_dmg = rand() % 10 + 1;
                int ghost_dmg = rand() % 10 + 1;

                ghost_health -= player_dmg;
                player_health -= ghost_dmg;

                printf("You deal %d damage to the ghost and take %d damage in return.\n", player_dmg, ghost_dmg);
                
                if(player_health <= 0) {
                    printf("You have died!\n");
                    break;
                } else if(ghost_health <= 0) {
                    printf("You have defeated the ghost with %d health points remaining!\n", player_health);
                    break;
                }
            }
        }

        //mark the room as visited
        rooms[player_x][player_y] = 1;

        //check if player reached exit
        if(player_x == end_x && player_y == end_y) {
            printf("You have reached the exit in %d moves!\n", num_moves);
            break;
        }
    }

    //ask player if they want to play again
    printf("Play again? [y]es or [n]o: ");
    scanf(" %c", &play_again);

    if(play_again == 'y') {
        main();
    } else {
        printf("Thanks for playing!\n");
    }

    return 0;
}