//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(char board[][COLS])
{
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int get_random(int lower, int upper)
{
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int check_win(char board[][COLS], char player)
{
    int win = 0;
    if((board[0][0] == player && board[0][1] == player && board[0][2] == player) || // top row
       (board[1][0] == player && board[1][1] == player && board[1][2] == player) || // middle row 
       (board[2][0] == player && board[2][1] == player && board[2][2] == player) || // bottom row 
       (board[0][0] == player && board[1][0] == player && board[2][0] == player) || // left column
       (board[0][1] == player && board[1][1] == player && board[2][1] == player) || // middle column
       (board[0][2] == player && board[1][2] == player && board[2][2] == player) || // right column
       (board[0][0] == player && board[1][1] == player && board[2][2] == player) || // diagonal top left to bottom right
       (board[0][2] == player && board[1][1] == player && board[2][0] == player)) { // diagonal top right to bottom left 
        win = 1;
    }
    return win;
}

void user_move(char board[][COLS], char player)
{
    int row, col;
    printf("Enter coordinates for %c: ", player);
    scanf("%d %d", &row, &col);
    while(board[row][col] != '_') {
        printf("Spot is already taken, try again\n");
        printf("Enter coordinates for %c: ", player);
        scanf("%d %d", &row, &col);
    }
    board[row][col] = player;
}

void computer_move(char board[][COLS], char player)
{
    int row, col;
    do {
        row = get_random(0,2);
        col = get_random(0,2);
    }while(board[row][col] != '_');
    board[row][col] = player;
}

void play_game()
{
    char board[ROWS][COLS];
    int num_turns = 0;
    char cur_player = 'X';
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = '_';
        }
    }
    print_board(board);
    while(num_turns < 9) {
        if(cur_player == 'X') {
            user_move(board, cur_player);
        } else {
            computer_move(board, cur_player);
        }
        print_board(board);
        if(check_win(board, cur_player)) {
            printf("%c wins!\n", cur_player);
            return;
        } else {
            num_turns++;
            if(cur_player == 'X') {
                cur_player = 'O';
            } else {
                cur_player = 'X';
            }
        }
    }
    printf("Tie game!\n");
}

int main()
{
    char play_again = 'y';
    while(play_again == 'y') {
        printf("Let's play Tic Tac Toe!\n");
        play_game();
        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);
    }
    return 0;
}