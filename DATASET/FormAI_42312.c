//FormAI DATASET v1.0 Category: Checkers Game ; Style: multivariable
#include<stdio.h>

// function to print the board
void printboard(int board[][8]) {
    printf("\n     1  2  3  4  5  6  7  8\n\n");
    for(int i=0; i<8; i++) {
        printf("%d    ", i+1);
        for(int j=0; j<8; j++) {
            printf("%c  ", board[i][j]);
        }
        printf("\n");
    }
}

// function to get the current player input
void getCurrentPlayerInput(int player, int* x, int* y) {
    printf("\nPlayer %d, enter your move: ", player);
    scanf("%d,%d", x, y);
    while(*x < 1 || *x > 8 || *y < 1 || *y > 8) {
        printf("\nInvalid move! Player %d, enter your move: ", player);
        scanf("%d,%d", x, y);
    }
}

// function to check if move is valid
int isMoveValid(int board[][8], int player, int x1, int y1, int x2, int y2) {
    // check if destination is not occupied
    if(board[x2][y2] != 32) {
        return 0;
    }
    
    // check if player is not trying to move the opponent's piece
    int opponent = player == 1 ? 2 : 1;
    if(board[x1][y1] == 'b' && player == 1) {
        return 0;
    } else if(board[x1][y1] == 'w' && player == 2) {
        return 0;
    }
    
    // check if the move is diagonal and only one square away
    if((x1-x2)*(x1-x2) == 1 && (y1-y2)*(y1-y2) == 1) {
        // for normal pieces
        if(board[x1][y1] == 'b' || board[x1][y1] == 'w') {
            // check if move is forward
            if(board[x1][y1] == 'b' && x2 > x1) {
                return 0;
            } else if(board[x1][y1] == 'w' && x2 < x1) {
                return 0;
            }
        }
        // for kings
        else if(board[x1][y1] == 'B' || board[x1][y1] == 'W') {
            // kings can move in any direction
        }
        return 1;
    }
    // check if the move is diagonal and two squares away (jump move)
    else if((x1-x2)*(x1-x2) == 4 && (y1-y2)*(y1-y2) == 4) {
        int xm = (x1+x2)/2;
        int ym = (y1+y2)/2;
        // check if the middle square has opponent's piece
        if(board[xm][ym] == opponent || board[xm][ym] == opponent-32) {
            // for normal pieces
            if(board[x1][y1] == 'b' || board[x1][y1] == 'w') {
                // check if move is forward
                if(board[x1][y1] == 'b' && x2 > x1) {
                    return 0;
                } else if(board[x1][y1] == 'w' && x2 < x1) {
                    return 0;
                }
                
                // check if player is jumping over his own piece
                if(board[xm][ym] == player || board[xm][ym] == player-32) {
                    return 0;
                }
            }
            // for kings
            else if(board[x1][y1] == 'B' || board[x1][y1] == 'W') {
                // kings can move in any direction
                
                // check if player is jumping over his own piece
                if(board[xm][ym] == player || board[xm][ym] == player-32) {
                    return 0;
                }
            }
            return 1;
        }
    }
    return 0;
}

// function to check if the current player has no more valid moves
int hasNoMoreValidMoves(int board[][8], int player) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == 'b' && player == 1) {
                // check top-left diagonal
                if(i>1 && j>1 && isMoveValid(board, player, i, j, i-2, j-2)) {
                    return 0;
                }
                // check top-right diagonal
                else if(i>1 && j<6 && isMoveValid(board, player, i, j, i-2, j+2)) {
                    return 0;
                }
                // check bottom-left diagonal
                else if(i<6 && j>1 && isMoveValid(board, player, i, j, i+2, j-2)) {
                    return 0;
                }
                // check bottom-right diagonal
                else if(i<6 && j<6 && isMoveValid(board, player, i, j, i+2, j+2)) {
                    return 0;
                }
            } else if(board[i][j] == 'w' && player == 2) {
                // check top-left diagonal
                if(i>1 && j>1 && isMoveValid(board, player, i, j, i-2, j-2)) {
                    return 0;
                }
                // check top-right diagonal
                else if(i>1 && j<6 && isMoveValid(board, player, i, j, i-2, j+2)) {
                    return 0;
                }
                // check bottom-left diagonal
                else if(i<6 && j>1 && isMoveValid(board, player, i, j, i+2, j-2)) {
                    return 0;
                }
                // check bottom-right diagonal
                else if(i<6 && j<6 && isMoveValid(board, player, i, j, i+2, j+2)) {
                    return 0;
                }
            } else if(board[i][j] == 'B' && player == 1) {
                // check top-left diagonal
                if(i>0 && j>0 && isMoveValid(board, player, i, j, i-1, j-1)) {
                    return 0;
                }
                // check top-right diagonal
                else if(i>0 && j<7 && isMoveValid(board, player, i, j, i-1, j+1)) {
                    return 0;
                }
                // check bottom-left diagonal
                else if(i<7 && j>0 && isMoveValid(board, player, i, j, i+1, j-1)) {
                    return 0;
                }
                // check bottom-right diagonal
                else if(i<7 && j<7 && isMoveValid(board, player, i, j, i+1, j+1)) {
                    return 0;
                }
            } else if(board[i][j] == 'W' && player == 2) {
                // check top-left diagonal
                if(i>0 && j>0 && isMoveValid(board, player, i, j, i-1, j-1)) {
                    return 0;
                }
                // check top-right diagonal
                else if(i>0 && j<7 && isMoveValid(board, player, i, j, i-1, j+1)) {
                    return 0;
                }
                // check bottom-left diagonal
                else if(i<7 && j>0 && isMoveValid(board, player, i, j, i+1, j-1)) {
                    return 0;
                }
                // check bottom-right diagonal
                else if(i<7 && j<7 && isMoveValid(board, player, i, j, i+1, j+1)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// function to move a piece and return 1 if the player gets another turn
int movePiece(int board[][8], int player, int x1, int y1, int x2, int y2) {
    // move the piece
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 32;
    
    // check if the player has just made a jump move
    if((x1-x2)*(x1-x2) == 4 && (y1-y2)*(y1-y2) == 4) {
        int xm = (x1+x2)/2;
        int ym = (y1+y2)/2;
        board[xm][ym] = 32;
        // check if the player can make another jump move
        if((isMoveValid(board, player, x2, y2, x2-2, y2-2) == 1)
        || (isMoveValid(board, player, x2, y2, x2-2, y2+2) == 1)
        || (isMoveValid(board, player, x2, y2, x2+2, y2-2) == 1)
        || (isMoveValid(board, player, x2, y2, x2+2, y2+2) == 1)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // initialize the board
    int board[8][8] = {
    {32,'b',32,'b',32,'b',32,'b'},
    {'b',32,'b',32,'b',32,'b',32},
    {32,'b',32,'b',32,'b',32,'b'},
    {32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32},
    {'w',32,'w',32,'w',32,'w',32},
    {32,'w',32,'w',32,'w',32,'w'},
    {'w',32,'w',32,'w',32,'w',32}};
    
    // game loop
    int player = 1;
    while(1) {
        printboard(board);
        int x1, y1, x2, y2;
        getCurrentPlayerInput(player, &x1, &y1);
        if(hasNoMoreValidMoves(board, player)) {
            printf("\nPlayer %d has no more valid moves! Player %d wins!\n", player, player == 1 ? 2 : 1);
            break;
        }
        getCurrentPlayerInput(player, &x2, &y2);
        if(isMoveValid(board, player, x1-1, y1-1, x2-1, y2-1) == 0) {
            printf("\nInvalid move! Please try again.\n");
        } else {
            if(movePiece(board, player, x1-1, y1-1, x2-1, y2-1) == 0) {
                player = player == 1 ? 2 : 1;
            }
        }
    }
    return 0;
}