//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define OBSTACLE_PERCENTAGE 20

// function to print the game board
void print_board(char board[][BOARD_SIZE]){
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%3c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to randomly place obstacles in the game board
void set_obstacles(char board[][BOARD_SIZE]){
    int num_obstacles = (int)(OBSTACLE_PERCENTAGE/100.0 * BOARD_SIZE*BOARD_SIZE);
    srand(time(NULL)); // use current time as seed for random generator
    for(int n=0; n<num_obstacles; n++){
        int i = rand() % BOARD_SIZE;
        int j = rand() % BOARD_SIZE;
        board[i][j] = 'X';
    }
}

int main(){
    // initialize the game board with spaces
    char board[BOARD_SIZE][BOARD_SIZE];
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            board[i][j] = ' ';
        }
    }

    // set obstacles randomly in the game board
    set_obstacles(board);

    // print the initial game board
    printf("Start the game!\n");
    print_board(board);

    // initialize the player's position
    int player_row = BOARD_SIZE-1;
    int player_col = 0;
    board[player_row][player_col] = 'P';

    // main game loop
    int game_over = 0;
    while(!game_over){
        // ask the player to enter a move
        printf("Enter a move (U/D/L/R): ");
        char move;
        scanf("%c", &move);
        getchar(); // flush the input buffer

        // update the player's position based on the move
        board[player_row][player_col] = ' '; // clear the current position
        switch(move){
            case 'U':
                if(player_row > 0){
                    player_row--;
                }
                break;
            case 'D':
                if(player_row < BOARD_SIZE-1){
                    player_row++;
                }
                break;
            case 'L':
                if(player_col > 0){
                    player_col--;
                }
                break;
            case 'R':
                if(player_col < BOARD_SIZE-1){
                    player_col++;
                }
                break;
            default:
                printf("Invalid move! Try again.\n");
                continue; // go back to the start of the loop
        }

        // check if the player has reached the end of the board
        if(player_row == 0 && player_col == BOARD_SIZE-1){
            printf("Congratulations! You finished the game.\n");
            game_over = 1;
        }else{
            // set the new player position on the board and print it
            board[player_row][player_col] = 'P';
            print_board(board);
        }
    }

    // end of game
    printf("Game over.\n");

    return 0;
}