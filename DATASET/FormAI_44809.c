//FormAI DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdbool.h>

#define BOARD_SIZE 8
#define EMPTY_SPACE '_'

typedef struct {
    int row;
    int col;
} Position;

typedef Position Move[2];

char board[BOARD_SIZE][BOARD_SIZE];
bool is_red_turn = true;

void initializeBoard(){
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(i<3 && (i+j)%2==0){
                board[i][j] = 'B';
            } else if(i>4 && (i+j)%2==0){
                board[i][j] = 'R';
            } else {
                board[i][j] = EMPTY_SPACE;
            }
        }
    }
}

bool isValidMove(Position from, Position to){
    if(board[to.row][to.col]!=EMPTY_SPACE){
        return false;
    }

    int row_diff = to.row - from.row;
    int col_diff = to.col - from.col;

    if(is_red_turn && (row_diff>0 || abs(row_diff)!=abs(col_diff))){
        return false;
    } else if(!is_red_turn && (row_diff<0 || abs(row_diff)!=abs(col_diff))){
        return false;
    }

    if(abs(row_diff)==1 && abs(col_diff)==1){
        return true;
    }

    if(abs(row_diff)!=2 || abs(col_diff)!=2){
        return false;
    }

    int jumped_row = from.row + row_diff/2;
    int jumped_col = from.col + col_diff/2;

    if(board[jumped_row][jumped_col] == EMPTY_SPACE || (is_red_turn ^ (board[jumped_row][jumped_col]=='R'))){
        return false;
    }

    return true;
}

void makeMove(Move move){
    Position from = move[0];
    Position to = move[1];
    char piece = board[from.row][from.col];
    board[from.row][from.col] = EMPTY_SPACE;
    board[to.row][to.col] = piece;

    if(abs(to.row-from.row)==2){
        int jumped_row = from.row + (to.row-from.row)/2;
        int jumped_col = from.col + (to.col-from.col)/2;
        board[jumped_row][jumped_col] = EMPTY_SPACE;
    }
}

Position getPosition(char* prompt){
    Position pos;
    printf("%s row: ", prompt);
    scanf("%d", &pos.row);
    printf("%s column: ", prompt);
    scanf("%d", &pos.col);
    pos.row--;
    pos.col--;
    return pos;
}

void printBoard(){
    printf("   ");
    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d ", i+1);
    }
    printf("\n");

    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d ", i+1);
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool hasWon(bool is_red){
    char piece = is_red ? 'R' : 'B';
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(board[i][j] == piece || board[i][j] == toupper(piece)){
                if(isValidMove((Position){i,j},(Position){i+1,j-1})){
                    return false;
                }
                if(isValidMove((Position){i,j},(Position){i+1,j+1})){
                    return false;
                }
                if(isValidMove((Position){i,j},(Position){i+2,j-2})){
                    return false;
                }
                if(isValidMove((Position){i,j},(Position){i+2,j+2})){
                    return false;
                }
                if(board[i][j] == toupper(piece)){
                    if(isValidMove((Position){i,j},(Position){i-1,j-1})){
                        return false;
                    }
                    if(isValidMove((Position){i,j},(Position){i-1,j+1})){
                        return false;
                    }
                    if(isValidMove((Position){i,j},(Position){i-2,j-2})){
                        return false;
                    }
                    if(isValidMove((Position){i,j},(Position){i-2,j+2})){
                        return false;
                    }
                }

            }
        }
    }
    return true;
}

int main(){
    initializeBoard();
    while(true){
        printBoard();
        if(hasWon(true)){
            printf("Red has won\n");
            break;
        }
        if(hasWon(false)){
            printf("Black has won\n");
            break;
        }
        Move move;
        while(true){
            printf("Enter your move. From:\n");
            Position from = getPosition("");
            printf("To:\n");
            Position to = getPosition("");
            move[0] = from;
            move[1] = to;
            if(isValidMove(from, to)){
                break;
            } else {
                printf("Invalid move. Try Again.\n");
            }
        }
        makeMove(move);
        is_red_turn = !is_red_turn;
    }
}