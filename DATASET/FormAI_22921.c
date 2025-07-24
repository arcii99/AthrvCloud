//FormAI DATASET v1.0 Category: Checkers Game ; Style: cheerful
/* Welcome to the C Checkers Game!
 * In this game, you get to play Checkers with the computer and see who will come out on top.
 * Let's get started!
 */

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

/* This function initializes the board to the starting position of the game */
void initialize_board(){
    int row, col;
    for(row=0; row<BOARD_SIZE; ++row){
        for(col=0; col<BOARD_SIZE; ++col){
            if((row+col)%2==1){
                if(row<=2){ board[row][col] = 'r'; }
                else if(row>=5){ board[row][col] = 'b'; }
                else{ board[row][col] = ' '; }
            } else {
                board[row][col] = ' ';
            }
        }
    }
}

/* This function prints out the current state of the board */
void print_board(){
    int row, col;
    // print column letters
    printf("  ");
    for(col=0; col<BOARD_SIZE; ++col){
        printf(" %c ", 'a' + col);
    }
    printf("\n");

    // print rows
    for(row=0; row<BOARD_SIZE; ++row){
        printf("%d ", row+1);
        for(col=0; col<BOARD_SIZE; ++col){
            printf("[%c]", board[row][col] );
        }
        printf("%d", row+1);
        printf("\n");
    }

    // print column letters again
    printf("  ");
    for(col=0; col<BOARD_SIZE; ++col){
        printf(" %c ", 'a' + col);
    }
    printf("\n");
}

/* This function is called when a player makes a move */
void make_move(int row1, int col1, int row2, int col2){
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = ' ';
}

/* This function checks if a move is valid */
int is_valid_move(int row1, int col1, int row2, int col2){
    int piece, jump_row, jump_col, delta_row, delta_col;
    piece = board[row1][col1];
    if(piece==' '){ return 0; }  // no piece there to move
    delta_row = row2 - row1;
    if(piece=='r' && delta_row<0){ return 0; }  // red can only move up
    if(piece=='b' && delta_row>0){ return 0; }  // black can only move down
    if(abs(delta_row)==1 && abs(col2-col1)==1){  // normal move
        if(board[row2][col2]==' '){ return 1; }  // destination is empty
    } else if(abs(delta_row)==2 && abs(col2-col1)==2){  // jump move
        jump_row = row1 + delta_row/2;  // row with jumped piece
        jump_col = col1 + (col2-col1)/2;  // column with jumped piece
        if(board[row2][col2]==' ' && board[jump_row][jump_col]!=piece && board[jump_row][jump_col]!=' '){
            return 1;  // destination is empty and jump piece is opponent
        }
    }
    return 0;  // did not pass any of the above checks
}

/* This function checks if a player has won the game */
int has_won(char player){
    int row, col;
    for(row=0; row<BOARD_SIZE; ++row){
        for(col=0; col<BOARD_SIZE; ++col){
            if(board[row][col]==player || board[row][col]==toupper(player)){  // player has at least one piece left
                if(board[row][col]==player && row<BOARD_SIZE-1){ return 0; }  // player has piece that can still move forward
                if(board[row][col]==toupper(player)){
                    if((row>0 && col>0 && board[row-1][col-1]==' ') ||
                       (row>0 && col<BOARD_SIZE-1 && board[row-1][col+1]==' ') ||
                       (row<BOARD_SIZE-1 && col>0 && board[row+1][col-1]==' ') ||
                       (row<BOARD_SIZE-1 && col<BOARD_SIZE-1 && board[row+1][col+1]==' ')){
                        return 0;  // player has king that can still move in any direction
                    }
                }
            }
        }
    }
    printf("Congratulations, %c has won the game!\n", player);
    return 1;  // player has no piece left or all pieces are blocked
}

/* This function gets the user's move */
void get_user_move(int* row1, int* col1, int* row2, int* col2){
    char input[6];
    do{
        printf("Enter your move (e.g. a4 b5): ");
        gets(input);
        *col1 = input[0] - 'a';
        *row1 = input[1] - '1';
        *col2 = input[3] - 'a';
        *row2 = input[4] - '1';
        if(!is_valid_move(*row1, *col1, *row2, *col2)){
            printf("Not a valid move! ");
        }
    } while(!is_valid_move(*row1, *col1, *row2, *col2));
}

/* This function gets the computer's move */
void get_computer_move(int* row1, int* col1, int* row2, int* col2){
    int row, col;
    char piece;
    for(row=0; row<BOARD_SIZE; ++row){
        for(col=0; col<BOARD_SIZE; ++col){
            if(board[row][col]=='b' || board[row][col]=='B'){  // look for black pieces to move
                if(row<BOARD_SIZE-1 && col>0 && board[row+1][col-1]==' '){  // try forward and left
                    *row1 = row;
                    *col1 = col;
                    *row2 = row+1;
                    *col2 = col-1;
                    return;
                } else if(row<BOARD_SIZE-1 && col<BOARD_SIZE-1 && board[row+1][col+1]==' '){  // try forward and right
                    *row1 = row;
                    *col1 = col;
                    *row2 = row+1;
                    *col2 = col+1;
                    return;
                } else if(board[row][col]=='B' &&
                      ((row>0 && col>0 && board[row-1][col-1]==' ') ||
                       (row>0 && col<BOARD_SIZE-1 && board[row-1][col+1]==' ') ||
                       (row<BOARD_SIZE-1 && col>0 && board[row+1][col-1]==' ') ||
                       (row<BOARD_SIZE-1 && col<BOARD_SIZE-1 && board[row+1][col+1]==' '))){  // king can move in any direction
                    if(board[row-1][col-1]==' '){  // try up and left
                        *row1 = row;
                        *col1 = col;
                        *row2 = row-1;
                        *col2 = col-1;
                        return;
                    } else if(board[row-1][col+1]==' '){  // try up and right
                        *row1 = row;
                        *col1 = col;
                        *row2 = row-1;
                        *col2 = col+1;
                        return;
                    } else if(board[row+1][col-1]==' '){  // try down and left
                        *row1 = row;
                        *col1 = col;
                        *row2 = row+1;
                        *col2 = col-1;
                        return;
                    } else if(board[row+1][col+1]==' '){  // try down and right
                        *row1 = row;
                        *col1 = col;
                        *row2 = row+1;
                        *col2 = col+1;
                        return;
                    }
                }
            }
        }
    }
    for(row=0; row<BOARD_SIZE; ++row){
        for(col=0; col<BOARD_SIZE; ++col){
            if(board[row][col]=='b' || board[row][col]=='B'){  // look for black pieces to move
                if(row<BOARD_SIZE-1 && col>0 && is_valid_move(row,col,row+1,col-1)){  // try forward and left
                    *row1 = row;
                    *col1 = col;
                    *row2 = row+1;
                    *col2 = col-1;
                    return;
                } else if(row<BOARD_SIZE-1 && col<BOARD_SIZE-1 && is_valid_move(row,col,row+1,col+1)){  // try forward and right
                    *row1 = row;
                    *col1 = col;
                    *row2 = row+1;
                    *col2 = col+1;
                    return;
                } else if(board[row][col]=='B'){
                    if(row>0 && col>0 && is_valid_move(row,col,row-1,col-1)) {  // try up and left
                        *row1 = row;
                        *col1 = col;
                        *row2 = row-1;
                        *col2 = col-1;
                        return;
                    } else if(row>0 && col<BOARD_SIZE-1 && is_valid_move(row,col,row-1,col+1)){  // try up and right
                        *row1 = row;
                        *col1 = col;
                        *row2 = row-1;
                        *col2 = col+1;
                        return;
                    } else if(row<BOARD_SIZE-1 && col>0 && is_valid_move(row,col,row+1,col-1)){  // try down and left
                        *row1 = row;
                        *col1 = col;
                        *row2 = row+1;
                        *col2 = col-1;
                        return;
                    } else if(row<BOARD_SIZE-1 && col<BOARD_SIZE-1 && is_valid_move(row,col,row+1,col+1)){  // try down and right
                        *row1 = row;
                        *col1 = col;
                        *row2 = row+1;
                        *col2 = col+1;
                        return;
                    }
                }
            }
        }
    }
}

int main(){
    int user_row1, user_col1, user_row2, user_col2, computer_row1, computer_col1, computer_row2, computer_col2;
    initialize_board();
    print_board();
    while(1){
        printf("Your turn:\n");
        get_user_move(&user_row1, &user_col1, &user_row2, &user_col2);
        make_move(user_row1, user_col1, user_row2, user_col2);
        print_board();
        if(has_won('r')){ break; }
        printf("Computer's turn:\n");
        get_computer_move(&computer_row1, &computer_col1, &computer_row2, &computer_col2);
        make_move(computer_row1, computer_col1, computer_row2, computer_col2);
        print_board();
        if(has_won('b')){ break; }
    }
    return 0;
}