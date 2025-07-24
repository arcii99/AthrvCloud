//FormAI DATASET v1.0 Category: Checkers Game ; Style: interoperable
#include <stdio.h>

// define the size of the board
#define ROW 8
#define COL 8

// define the checker types
#define EMPTY 0
#define BLACK 1
#define WHITE 2

// initialize the board
int board[ROW][COL] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0}
};

// display the board
void display_board(){
    printf("\n  1 2 3 4 5 6 7 8\n\n");
    for(int i = 0; i < ROW; i++){
        printf("%d ", i+1);
        for(int j = 0; j < COL; j++){
            switch(board[i][j]){
                case EMPTY:
                    printf("- ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
                case WHITE:
                    printf("W ");
                    break;
            }
        }
        printf("%d\n", i+1);
    }
    printf("\n  1 2 3 4 5 6 7 8\n\n");
}

// move a checker
void move_checker(int row1, int col1, int row2, int col2){
    int temp = board[row1][col1];
    board[row1][col1] = EMPTY;
    board[row2][col2] = temp;
}

// check if a move is valid
int valid_move(int row1, int col1, int row2, int col2, int turn){
    // check if the target location is empty
    if(board[row2][col2] != EMPTY){
        return 0;
    }
    // check if the checker is moving in the right direction
    if(turn == BLACK){
        if(row2 >= row1){
            return 0;
        }
    }
    else{
        if(row2 <= row1){
            return 0;
        }
    }
    // check if the move is diagonal
    if((row1 - row2) != (col1 - col2) && (row1 - row2) != -(col1 - col2)){
        return 0;
    }
    // check if the move is single or double diagonal
    int dr = row2 - row1;
    int dc = col2 - col1;
    if(dr*dr == 1 && dc*dc == 1){
        return 1;
    }
    else if(dr*dr == 4 && dc*dc == 4){
        if(board[(row1+row2)/2][(col1+col2)/2] == 3-turn){
            return 1;
        }
    }
    return 0;
}

// check if there is a move available for the given turn
int move_available(int turn){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(board[i][j] == turn){
                if(i > 0 && j > 0 && valid_move(i,j,i-1,j-1,turn)){
                    return 1;
                }
                if(i > 0 && j < COL-1 && valid_move(i,j,i-1,j+1,turn)){
                    return 1;
                }
                if(i < ROW-1 && j > 0 && valid_move(i,j,i+1,j-1,turn)){
                    return 1;
                }
                if(i < ROW-1 && j < COL-1 && valid_move(i,j,i+1,j+1,turn)){
                    return 1;
                }
                if(board[i][j] == BLACK){
                    if(i > 1 && j > 1 && board[i-1][j-1] == WHITE &&
                        board[i-2][j-2] == EMPTY){
                        return 1;
                    }
                    if(i > 1 && j < COL-2 && board[i-1][j+1] == WHITE &&
                        board[i-2][j+2] == EMPTY){
                        return 1;
                    }
                }
                else{
                    if(i < ROW-2 && j > 1 && board[i+1][j-1] == BLACK &&
                        board[i+2][j-2] == EMPTY){
                        return 1;
                    }
                    if(i < ROW-2 && j < COL-2 && board[i+1][j+1] == BLACK &&
                        board[i+2][j+2] == EMPTY){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// play the game
void play_game(){
    int turn = BLACK;
    int row1, col1, row2, col2;
    display_board();
    while(move_available(turn)){
        int valid_input = 0;
        printf("%s's turn:\n", turn==BLACK ? "Black" : "White");
        while(!valid_input){
            printf("Enter the row and column of the checker you want to move: ");
            scanf("%d %d", &row1, &col1);
            printf("Enter the row and column of the square you want to move to: ");
            scanf("%d %d", &row2, &col2);
            if(valid_move(row1-1, col1-1, row2-1, col2-1, turn)){
                valid_input = 1;
            }
            else{
                printf("Invalid move. Please try again.\n");
            }
        }
        move_checker(row1-1, col1-1, row2-1, col2-1);
        display_board();
        turn = 3-turn;
    }
    printf("Game over. %s wins!\n", turn==BLACK ? "Black" : "White");
}

// main function
int main(){
    play_game();
    return 0;
}