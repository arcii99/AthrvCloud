//FormAI DATASET v1.0 Category: Chess engine ; Style: curious
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char board[8][8];  //game board
char move_set[30000];  //array for storing all the moves made by the engine
int move_count = 0;  //keeps track of the number of moves made

void print_board(){  //function to print the current state of the board
    printf("\n");
    for(int row=0;row<8;row++){
        for(int col=0;col<8;col++){
            printf("%c ",board[row][col]);
        }
        printf("\n");
    }
}

void init_board(){  //function to initialize the board at the beginning of the game
    for(int row=0;row<8;row++){
        for(int col=0;col<8;col++){
            if(row == 0 || row == 7){
                if(col == 0 || col == 7){
                    board[row][col] = 'R';
                }
                else if(col == 1 || col == 6){
                    board[row][col] = 'N';
                }
                else if(col == 2 || col == 5){
                    board[row][col] = 'B';
                }
                else if(col == 3){
                    board[row][col] = 'Q';
                }
                else{
                    board[row][col] = 'K';
                }
            }
            else if(row == 1 || row == 6){
                board[row][col] = 'P';
            }
            else{
                board[row][col] = '-';
            }
        }
    }
}

void make_move(char piece, int from_row, int from_col, int to_row, int to_col){  //function to make a move
    move_set[move_count] = piece;
    move_set[move_count+1] = from_col + 'a';
    move_set[move_count+2] = 8 - from_row + '0';
    move_set[move_count+3] = '-';
    move_set[move_count+4] = to_col + 'a';
    move_set[move_count+5] = 8 - to_row + '0';
    move_set[move_count+6] = ' ';
    
    move_count += 7;
    
    char temp = board[from_row][from_col];
    board[from_row][from_col] = '-';
    board[to_row][to_col] = temp;
}

int main(){
    init_board();
    print_board();
    make_move('P', 1, 4, 3, 4);
    print_board();
    return 0;
}