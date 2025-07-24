//FormAI DATASET v1.0 Category: Chess AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define BOARD_SIZE 8

//typedef to implement Boolean, true is '1' and false is '0'.
typedef int BOOL;
#define true 1
#define false 0

//Structure to hold a coordinate in the board.
typedef struct{
    int x;
    int y;
}COORDINATE;

//Structure to hold a move.
typedef struct{
    COORDINATE from;
    COORDINATE to;
}MOVE;

//Structure to represent the game board.
typedef struct{
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
}BOARD;

/*
The function creates the initial board for a game of chess.
*/
void InitBoard(BOARD* board){
    
    //Ranks 1 and 8 (black side).
    char rank_1[] = {'r', 'k', 'b', 'q', 'l', 'b', 'k', 'r'};
    char rank_8[] = {'R', 'K', 'B', 'Q', 'L', 'B', 'K', 'R'};
    
    //Place the pieces of both players (black and white).
    for(int i = 0; i < BOARD_SIZE; i++){
        board->board[0][i] = rank_1[i];
        board->board[1][i] = 'p';
        board->board[6][i] = 'P';
        board->board[7][i] = rank_8[i];
    }
    
    //Set the turn to white.
    board->turn = 'w';
}

/*
The function prints the game board on the console.
*/
void PrintBoard(BOARD board){
    
    //Outer loop iterates through ranks (rows).
    for(int i = 0; i < BOARD_SIZE; i++){
        
        //Inner loop iterates through files (columns).
        for(int j = 0; j < BOARD_SIZE; j++){
            printf("%c ", board.board[i][j]);
        }
        
        //Start a new line for each rank.
        printf("\n");
    }
    
    //Print the turn after the board.
    printf("Turn: %c\n", board.turn);
}

/*
The function checks if a coordinate is a valid square on the board.
*/
BOOL IsValidSquare(COORDINATE coord){
    return (coord.x >= 0 && coord.x < BOARD_SIZE && coord.y >= 0 && coord.y < BOARD_SIZE);
}

/*
The function checks if a piece at the specified coordinate belongs to the current player.
*/
BOOL IsOwnPiece(BOARD board, COORDINATE coord){
    return (isupper(board.board[coord.x][coord.y]) && board.turn == 'w') || (islower(board.board[coord.x][coord.y]) && board.turn == 'b');
}

/*
The function checks if a piece can move to the specified square.
*/
BOOL CanMove(BOARD board, COORDINATE from, COORDINATE to){
    
    //Get the piece at the 'from' square.
    char piece = board.board[from.x][from.y];
    
    //Check if the destination square has a piece of the same color.
    if((isupper(piece) && isupper(board.board[to.x][to.y])) || (islower(piece) && islower(board.board[to.x][to.y]))){
        return false;
    }
    
    //Check if the move follows the movement rules for the piece.
    switch(tolower(piece)){
        
        case 'p':{
            int dx = to.x - from.x;
            int dy = to.y - from.y;
            
            if(!dx || !dy){ //Moving forward or sideways.
                
                if(dx == -1 && board.turn == 'b' && !board.board[to.x][to.y]){ //Regular move for black pawns.
                    return true;
                }
                
                else if(dx == 1 && board.turn == 'w' && !board.board[to.x][to.y]){ //Regular move for white pawns.
                    return true;
                }
                
                else if(dx == -1 && dy == -1 && board.turn == 'b' && board.board[to.x][to.y]){ //Capture move for black pawns.
                    return true;
                }
                
                else if(dx == 1 && dy == 1 && board.turn == 'w' && board.board[to.x][to.y]){ //Capture move for white pawns.
                    return true;
                }
            }
            
            break;
        }
        
        case 'r':{
            int dx = to.x - from.x;
            int dy = to.y - from.y;
            
            if(!dx || !dy){ //Moving vertically or horizontally.
                
                if(dx){ //Moving vertically.
                    int step = (dx > 0) ? 1 : -1;
                    for(int i = from.x + step; i != to.x; i += step){
                        if(board.board[i][from.y]){
                            return false;
                        }
                    }
                }
                
                else{ //Moving horizontally.
                    int step = (dy > 0) ? 1 : -1;
                    for(int i = from.y + step; i != to.y; i += step){
                        if(board.board[from.x][i]){
                            return false;
                        }
                    }
                }
                
                return true;
            }
            
            break;
        }
        
        case 'k':{
            int dx = abs(to.x - from.x);
            int dy = abs(to.y - from.y);
            
            if((dx == 1 && dy == 2) || (dx == 2 && dy == 1)){ //Moving in an L shape.
                return true;
            }
            
            break;
        }
        
        case 'b':{
            int dx = to.x - from.x;
            int dy = to.y - from.y;
            
            if(abs(dx) == abs(dy)){ //Moving diagonally.
                int xstep = (dx > 0) ? 1 : -1;
                int ystep = (dy > 0) ? 1 : -1;
                
                for(int i = from.x + xstep, j = from.y + ystep; i != to.x && j != to.y; i += xstep, j += ystep){
                    if(board.board[i][j]){
                        return false;
                    }
                }
                
                return true;
            }
            
            break;
        }
        
        case 'q':{
            if(CanMove(board, from, to)){ //Move follows movement rules for rook or bishop.
                return true;
            }
            
            break;
        }
        
        case 'l':{
            int dx = abs(to.x - from.x);
            int dy = abs(to.y - from.y);
            
            if(dx == 1 && dy == 1){ //Moving diagonally.
                return true;
            }
            
            else if(dx == 1 && dy == 0){ //Moving horizontally.
                return true;
            }
            
            else if(dx == 0 && dy == 1){ //Moving vertically.
                return true;
            }
            
            break;
        }
    }
    
    return false;
}

/*
The function checks if the player is in check (i.e. their king is threatened by the opponent's pieces).
*/
BOOL InCheck(BOARD board){
    
    //Find the position of the player's king.
    COORDINATE kingPos = {-1, -1};
    
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(tolower(board.board[i][j]) == 'l' && ((isupper(board.board[i][j]) && board.turn == 'w') || (islower(board.board[i][j]) && board.turn == 'b'))){
                kingPos.x = i;
                kingPos.y = j;
                break;
            }
        }
    }
    
    if(kingPos.x == -1){ //No king found.
        return false;
    }
    
    //Check if any of the opponent's pieces can move to the king's square.
    COORDINATE currPos;
    BOOL canMove;
    
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            currPos.x = i;
            currPos.y = j;
            canMove = false;
            
            if((isupper(board.board[i][j]) && board.turn == 'b') || (islower(board.board[i][j]) && board.turn == 'w')){
                if(CanMove(board, currPos, kingPos)){
                    return true;
                }
            }
        }
    }
    
    return false;
}

/*
The function checks if the player is in checkmate (i.e. their king is in check and there are no valid moves to get out of check).
*/
BOOL InCheckmate(BOARD board){
    
    //Check if the player is in check first.
    if(!InCheck(board)){
        return false;
    }
    
    //Find all the player's pieces and try to make valid moves with them. If none of them can move, the player is checkmated.
    COORDINATE currPos, destPos;
    BOOL canMove;
    BOARD temp;
    
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            currPos.x = i;
            currPos.y = j;
            canMove = false;
            
            if((isupper(board.board[i][j]) && board.turn == 'w') || (islower(board.board[i][j]) && board.turn == 'b')){
                for(int x = 0; x < BOARD_SIZE; x++){
                    for(int y = 0; y < BOARD_SIZE; y++){
                        destPos.x = x;
                        destPos.y = y;
                        
                        if(CanMove(board, currPos, destPos)){
                            //Make the move on a temporary board.
                            temp = board;
                            temp.board[destPos.x][destPos.y] = temp.board[currPos.x][currPos.y];
                            temp.board[currPos.x][currPos.y] = 0;
                            temp.turn = (temp.turn == 'w') ? 'b' : 'w';
                            
                            //Check if the player is still in check.
                            if(!InCheck(temp)){
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return true;
}

/*
The function checks if the game is a stalemate (i.e. the current player has no valid moves, but their king is not in check).
*/
BOOL InStalemate(BOARD board){
    
    //Check if the player is in check.
    if(InCheck(board)){
        return false;
    }
    
    //Find all the player's pieces and try to make valid moves with them. If none of them can move, the game is a stalemate.
    COORDINATE currPos, destPos;
    BOOL canMove;
    
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            currPos.x = i;
            currPos.y = j;
            canMove = false;
            
            if((isupper(board.board[i][j]) && board.turn == 'w') || (islower(board.board[i][j]) && board.turn == 'b')){
                for(int x = 0; x < BOARD_SIZE; x++){
                    for(int y = 0; y < BOARD_SIZE; y++){
                        destPos.x = x;
                        destPos.y = y;
                        
                        if(CanMove(board, currPos, destPos)){
                            return false;
                        }
                    }
                }
            }
        }
    }
    
    return true;
}

/*
The function handles a player's turn.
*/
void TakeTurn(BOARD* board){
    
    //Print the board and get the player's move.
    PrintBoard(*board);
    MOVE move;
    
    printf("Enter move: ");
    scanf("%d%d%d%d", &move.from.x, &move.from.y, &move.to.x, &move.to.y);
    
    //Check if the move is valid.
    if(!IsValidSquare(move.from) || !IsValidSquare(move.to) || !IsOwnPiece(*board, move.from) || !CanMove(*board, move.from, move.to)){
        printf("Invalid move.\n");
        return;
    }
    
    //Make the move.
    board->board[move.to.x][move.to.y] = board->board[move.from.x][move.from.y];
    board->board[move.from.x][move.from.y] = 0;
    board->turn = (board->turn == 'w') ? 'b' : 'w';
    
    //Check if the player is in checkmate or stalemate.
    if(InCheckmate(*board)){
        printf("Checkmate, %c wins!\n", (board->turn == 'w') ? 'b' : 'w');
        exit(0);
    }
    
    else if(InStalemate(*board)){
        printf("Stalemate, game drawn!\n");
        exit(0);
    }
}

int main(){
    BOARD board;
    InitBoard(&board);
    
    while(true){
        TakeTurn(&board);
    }
    
    return 0;
}