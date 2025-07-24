//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 30

void print_board(char board[][COL]);
void generate_board(char board[][COL]);
void move_player(char board[][COL], int row, int col);
void move_ghosts(char board[][COL]);
int check_win(char board[][COL]);

int main()
{
    char board[ROW][COL];
    int player_row = ROW - 2, player_col = COL / 2;
    int num_ghosts = 5;
    int i, j;

    srand(time(0)); // seed random number generator

    generate_board(board); // generate initial board

    // add ghosts to board
    for (i = 0; i < num_ghosts; i++) {
        int rand_row = rand() % ROW;
        int rand_col = rand() % COL;
        while (board[rand_row][rand_col] != ' ') {
            rand_row = rand() % ROW;
            rand_col = rand() % COL;
        }
        board[rand_row][rand_col] = 'G';
    }

    while (1) {
        system("clear"); // clear terminal
        print_board(board); // print board
        move_player(board, player_row, player_col); // move player
        move_ghosts(board); // move ghosts
        if (check_win(board)) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}

void print_board(char board[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void generate_board(char board[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = ' ';
            if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1) {
                board[i][j] = '#';
            }
        }
    }
    board[ROW - 2][COL / 2] = 'P'; // add player to board
}

void move_player(char board[][COL], int row, int col)
{
    char direction;
    printf("Use WASD to move: ");
    scanf(" %c", &direction);

    // move player
    switch (direction) {
        case 'w': // up
            if (board[row - 1][col] == ' ') {
                board[row - 1][col] = 'P';
                board[row][col] = ' ';
                row--;
            }
            break;
        case 'a': // left
            if (board[row][col - 1] == ' ') {
                board[row][col - 1] = 'P';
                board[row][col] = ' ';
                col--;
            }
            break;
        case 's': // down
            if (board[row + 1][col] == ' ') {
                board[row + 1][col] = 'P';
                board[row][col] = ' ';
                row++;
            }
            break;
        case 'd': // right
            if (board[row][col + 1] == ' ') {
                board[row][col + 1] = 'P';
                board[row][col] = ' ';
                col++;
            }
            break;
    }
}

void move_ghosts(char board[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (board[i][j] == 'G') {
                // move ghost randomly
                int rand_dir = rand() % 4;
                switch (rand_dir) {
                    case 0: // up
                        if (board[i - 1][j] == ' ') {
                            board[i - 1][j] = 'G';
                            board[i][j] = ' ';
                        }
                        break;
                    case 1: // left
                        if (board[i][j - 1] == ' ') {
                            board[i][j - 1] = 'G';
                            board[i][j] = ' ';
                        }
                        break;
                    case 2: // down
                        if (board[i + 1][j] == ' ') {
                            board[i + 1][j] = 'G';
                            board[i][j] = ' ';
                        }
                        break;
                    case 3: // right
                        if (board[i][j + 1] == ' ') {
                            board[i][j + 1] = 'G';
                            board[i][j] = ' ';
                        }
                        break;
                }
            }
        }
    }
}

int check_win(char board[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (board[i][j] == 'G') {
                if (i == ROW - 2 && j == COL / 2) { // ghost caught player
                    printf("You lose!\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}