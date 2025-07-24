//FormAI DATASET v1.0 Category: Chess engine ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLS 8

int board[ROWS][COLS];
int kings[2][2];
char whitePieces[] = {'P', 'R', 'N', 'B', 'Q', 'K'};
char blackPieces[] = {'p', 'r', 'n', 'b', 'q', 'k'};
int moveCount = 0;

void initBoard(){
    //Set up the board with starting pieces
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(i == 1){
                board[i][j] = 'P';
            }else if(i == 6){
                board[i][j] = 'p';
            }else{
                board[i][j] = ' ';
            }
        }
    }
    board[0][0] = 'R'; board[0][7] = 'R';
    board[7][0] = 'r'; board[7][7] = 'r';
    board[0][1] = 'N'; board[0][6] = 'N';
    board[7][1] = 'n'; board[7][6] = 'n';
    board[0][2] = 'B'; board[0][5] = 'B';
    board[7][2] = 'b'; board[7][5] = 'b';
    board[0][3] = 'Q'; board[7][3] = 'q';
    board[0][4] = 'K'; board[7][4] = 'k';
    kings[0][0] = 0; kings[0][1] = 4;
    kings[1][0] = 7; kings[1][1] = 4;
}

void printBoard(){
    int i, j;
    printf("   A B C D E F G H   \n");
    printf("  +-----------------+\n");
    for(i=0;i<ROWS;i++){
        printf("%d |", 8-i);
        for(j=0;j<COLS;j++){
            printf("%c|", board[i][j]);
        }
        printf(" %d\n", 8-i);
    }
    printf("  +-----------------+\n");
    printf("   A B C D E F G H   \n");
}

int isValidMove(char piece, int row, int col, int newRow, int newCol){
    //Check if move is valid for the given piece
    int i, j;
    int newRowDiff = newRow-row;
    int newColDiff = newCol-col;
    if(piece == 'P' || piece == 'p'){
        //Pawn moves
        if((piece == 'P' && newRowDiff < 0) || (piece == 'p' && newRowDiff > 0)){
            return 0;
        }
        if(abs(newRowDiff) > 2){
            return 0;
        }
        if(newColDiff == 0){
            if(abs(newRowDiff) == 2 && ((piece == 'P' && row != 6) || (piece == 'p' && row != 1))){
                return 0;
            }
            if(board[newRow][newCol] != ' '){
                return 0;
            }
        }else if(abs(newColDiff) == 1 && abs(newRowDiff) == 1){
            if(board[newRow][newCol] == ' '){
                return 0;
            }
        }else{
            return 0;
        }
    }else if(piece == 'R' || piece == 'r'){
        //Rook moves
        if(newRowDiff != 0 && newColDiff != 0){
            return 0;
        }
        if(newRowDiff == 0){
            for(j=col+1;j<newCol;j++){
                if(board[row][j] != ' '){
                    return 0;
                }
            }
            for(j=col-1;j>newCol;j--){
                if(board[row][j] != ' '){
                    return 0;
                }
            }
        }else{
            for(i=row+1;i<newRow;i++){
                if(board[i][col] != ' '){
                    return 0;
                }
            }
            for(i=row-1;i>newRow;i--){
                if(board[i][col] != ' '){
                    return 0;
                }
            }
        }
    }else if(piece == 'N' || piece == 'n'){
        //Knight moves
        if(abs(newRowDiff) == 2 && abs(newColDiff) == 1){
            if(board[newRow][newCol] == ' '){
                return 1;
            }else{
                return 0;
            }
        }else if(abs(newRowDiff) == 1 && abs(newColDiff) == 2){
            if(board[newRow][newCol] == ' '){
                return 1;
            }else{
                return 0;
            }
        }else{
            return 0;
        }
    }else if(piece == 'B' || piece == 'b'){
        //Bishop moves
        if(abs(newRowDiff) != abs(newColDiff)){
            return 0;
        }
        if(newRow > row && newCol > col){
            for(i=row+1, j=col+1;i<newRow;i++, j++){
                if(board[i][j] != ' '){
                    return 0;
                }
            }
        }else if(newRow > row && newCol < col){
            for(i=row+1, j=col-1;i<newRow;i++, j--){
                if(board[i][j] != ' '){
                    return 0;
                }
            }
        }else if(newRow < row && newCol > col){
            for(i=row-1, j=col+1;i>newRow;i--, j++){
                if(board[i][j] != ' '){
                    return 0;
                }
            }
        }else if(newRow < row && newCol < col){
            for(i=row-1, j=col-1;i>newRow;i--, j--){
                if(board[i][j] != ' '){
                    return 0;
                }
            }
        }
    }else if(piece == 'Q' || piece == 'q'){
        //Queen moves
        if(newRowDiff == 0 || newColDiff == 0){
            //Rook-like moves
            if(newRowDiff == 0){
                for(j=col+1;j<newCol;j++){
                    if(board[row][j] != ' '){
                        return 0;
                    }
                }
                for(j=col-1;j>newCol;j--){
                    if(board[row][j] != ' '){
                        return 0;
                    }
                }
            }else{
                for(i=row+1;i<newRow;i++){
                    if(board[i][col] != ' '){
                        return 0;
                    }
                }
                for(i=row-1;i>newRow;i--){
                    if(board[i][col] != ' '){
                        return 0;
                    }
                }
            }
        }else if(abs(newRowDiff) == abs(newColDiff)){
            //Bishop-like moves
            if(newRow > row && newCol > col){
                for(i=row+1, j=col+1;i<newRow;i++, j++){
                    if(board[i][j] != ' '){
                        return 0;
                    }
                }
            }else if(newRow > row && newCol < col){
                for(i=row+1, j=col-1;i<newRow;i++, j--){
                    if(board[i][j] != ' '){
                        return 0;
                    }
                }
            }else if(newRow < row && newCol > col){
                for(i=row-1, j=col+1;i>newRow;i--, j++){
                    if(board[i][j] != ' '){
                        return 0;
                    }
                }
            }else if(newRow < row && newCol < col){
                for(i=row-1, j=col-1;i>newRow;i--, j--){
                    if(board[i][j] != ' '){
                        return 0;
                    }
                }
            }
        }else{
            return 0;
        }
    }else if(piece == 'K' || piece == 'k'){
        //King moves
        if(abs(newRowDiff) <= 1 && abs(newColDiff) <= 1){
            return 1;
        }else{
            return 0;
        }
    }else{
        //Unknown piece
        return 0;
    }
    return 1;
}

int isCheck(int player){
    //Check if player is currently in check
    int i, j;
    int kingRow = kings[player][0];
    int kingCol = kings[player][1];
    int newRow, newCol;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(board[i][j] != ' ' && (board[i][j] > 'a' && player == 0 || board[i][j] < 'a' && player == 1)){
                if(isValidMove(board[i][j], i, j, kingRow, kingCol)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int makeMove(int player, char move[5]){
    //Make a move for the given player
    int pieceRow = move[1] - '1';
    int pieceCol = move[0] - 'a';
    int newRow = move[3] - '1';
    int newCol = move[2] - 'a';
    char piece = board[pieceRow][pieceCol];
    if(!isValidMove(piece, pieceRow, pieceCol, newRow, newCol)){
        return 0;
    }
    if(board[newRow][newCol] != ' '){
        printf("\n%s takes %s!", move, board[newRow][newCol] < 'a' ? whitePieces[board[newRow][newCol]-'A'] : blackPieces[board[newRow][newCol]-'a']);
        if(board[newRow][newCol] == 'K' || board[newRow][newCol] == 'k'){
            printf("\n\nCHECKMATE! %s wins in %d moves!\n\n", player == 0 ? "Black" : "White", moveCount/2+1);
            return -1;
        }
    }
    board[newRow][newCol] = piece;
    board[pieceRow][pieceCol] = ' ';
    if(piece == 'K' || piece == 'k'){
        kings[piece < 'a'][0] = newRow;
        kings[piece < 'a'][1] = newCol;
    }
    if(isCheck(!player)){
        if(isCheckmate(!player)){
            printf("\n\nCHECKMATE! %s wins in %d moves!\n\n", player == 0 ? "White" : "Black", moveCount/2+1);
            return -1;
        }else{
            printf("\nCHECK!\n");
        }
    }
    moveCount++;
    return 1;
}

int isCheckmate(int player){
    //Check if player is in checkmate
    char piece;
    int pieceRow, pieceCol, i, j, k, l;
    int newRow, newCol;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(board[i][j] != ' ' && (board[i][j] > 'a' && player == 0 || board[i][j] < 'a' && player == 1)){
                piece = board[i][j];
                for(k=0;k<ROWS;k++){
                    for(l=0;l<COLS;l++){
                        if(isValidMove(piece, i, j, k, l)){
                            pieceRow = i;
                            pieceCol = j;
                            newRow = k;
                            newCol = l;
                            if(board[newRow][newCol] != ' '){
                                board[pieceRow][pieceCol] = ' ';
                                board[newRow][newCol] = piece;
                                if(isCheck(player)){
                                    board[newRow][newCol] = board[pieceRow][pieceCol];
                                    board[pieceRow][pieceCol] = piece;
                                    continue;
                                }else{
                                    board[newRow][newCol] = board[pieceRow][pieceCol];
                                    board[pieceRow][pieceCol] = piece;
                                    return 0;
                                }
                            }else{
                                board[newRow][newCol] = piece;
                                board[pieceRow][pieceCol] = ' ';
                                if(isCheck(player)){
                                    board[pieceRow][pieceCol] = piece;
                                    board[newRow][newCol] = ' ';
                                    continue;
                                }else{
                                    board[pieceRow][pieceCol] = piece;
                                    board[newRow][newCol] = ' ';
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

int main(){
    initBoard();
    printBoard();
    int currentPlayer = 0;
    char move[5];
    while(1){
        printf("\n%s to move: ", currentPlayer == 0 ? "White" : "Black");
        scanf("%s", move);
        if(makeMove(currentPlayer, move) == -1){
            break;
        }
        printBoard();
        currentPlayer = !currentPlayer;
    }
    return 0;
}