//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GHOST 'G'
#define PLAYER 'P'
#define TREASURE 'T'

void populate_board(char board[], int size);
void print_board(char board[], int size);
int move_player(char board[], int size, int player_pos, char move);
int check_collision(char board[], int pos);

int main()
{
    const int board_size = 10;
    char board[board_size * board_size];
    int player_pos, treasure_pos;
    char move;
    int num_moves = 0;

    srand(time(NULL)); // seed random number generator

    populate_board(board, board_size);

    // find initial player position
    for (int i = 0; i < board_size * board_size; i++) {
        if (board[i] == PLAYER) {
            player_pos = i;
            break;
        }
    }

    // find initial treasure position
    for (int i = 0; i < board_size * board_size; i++) {
        if (board[i] == TREASURE) {
            treasure_pos = i;
            break;
        }
    }

    // print initial board
    print_board(board, board_size);

    // game loop
    while (num_moves < 15) {
        printf("Enter move (u/d/l/r): ");
        scanf(" %c", &move); // space before %c to consume newline character

        player_pos = move_player(board, board_size, player_pos, move);
        num_moves++;

        // check for collision with ghost
        if (check_collision(board, player_pos) == 1) {
            printf("You have been caught by the ghost! Game over.\n");
            return 0;
        }

        // check if player has found the treasure
        if (player_pos == treasure_pos) {
            printf("Congratulations! You have found the treasure.\n");
            return 0;
        }

        printf("\n");
        print_board(board, board_size);
    }

    printf("Game over. You have used up all your moves.\n");

    return 0;
}

// populate the board with ghosts, player and treasure
void populate_board(char board[], int size)
{
    int i, j, pos;
    int ghost_count = 0;

    // initialize all spaces as empty
    for (i = 0; i < size * size; i++) {
        board[i] = ' ';
    }

    // place ghosts randomly
    while (ghost_count < 5) {
        pos = rand() % (size * size);
        if (board[pos] == ' ') {
            board[pos] = GHOST;
            ghost_count++;
        }
    }

    // place player randomly
    while (board[pos] != ' ') {
        pos = rand() % (size * size);
    }
    board[pos] = PLAYER;

    // place treasure randomly
    while (board[pos] != ' ') {
        pos = rand() % (size * size);
    }
    board[pos] = TREASURE;
}

// print the board
void print_board(char board[], int size)
{
    int i, j;

    printf("+");
    for (j = 0; j < size; j++) {
        printf("---+");
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        printf("|");
        for (j = 0; j < size; j++) {
            printf(" %c |", board[i * size + j]);
        }
        printf("\n+");

        for (j = 0; j < size; j++) {
            printf("---+");
        }
        printf("\n");
    }
}

// move the player one space in the given direction
// returns new player position
int move_player(char board[], int size, int player_pos, char move)
{
    int new_pos;

    switch (move) {
        case 'u':
            if (player_pos >= size) {
                new_pos = player_pos - size;
                if (board[new_pos] == GHOST) {
                    printf("You have encountered a ghost!\n");
                } else {
                    board[player_pos] = ' ';
                    board[new_pos] = PLAYER;
                    player_pos = new_pos;                    
                }
            }
            break;

        case 'd':
            if (player_pos < (size * size - size)) {
                new_pos = player_pos + size;
                if (board[new_pos] == GHOST) {
                    printf("You have encountered a ghost!\n");
                } else {
                    board[player_pos] = ' ';
                    board[new_pos] = PLAYER;
                    player_pos = new_pos;                    
                }
            }
            break;

        case 'l':
            if (player_pos % size != 0) {
                new_pos = player_pos - 1;
                if (board[new_pos] == GHOST) {
                    printf("You have encountered a ghost!\n");
                } else {
                    board[player_pos] = ' ';
                    board[new_pos] = PLAYER;
                    player_pos = new_pos;                    
                }
            }
            break;

        case 'r':
            if ((player_pos + 1) % size != 0) {
                new_pos = player_pos + 1;
                if (board[new_pos] == GHOST) {
                    printf("You have encountered a ghost!\n");
                } else {
                    board[player_pos] = ' ';
                    board[new_pos] = PLAYER;
                    player_pos = new_pos;                    
                }
            }
            break;

        default:
            printf("Invalid move. Please enter u, d, l or r.\n");
            break;
    }

    return player_pos;
}

// check if player has collided with a ghost
// returns 1 if there is a collision, 0 otherwise
int check_collision(char board[], int pos)
{
    if (board[pos] == GHOST) {
        return 1;
    } else {
        return 0;
    }
}