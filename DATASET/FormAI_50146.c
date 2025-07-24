//FormAI DATASET v1.0 Category: Checkers Game ; Style: automated
#include <stdio.h>

int board[8][8] = { // initialize the board
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
};

void print_board() { // function to print the board

    printf("  0 1 2 3 4 5 6 7\n");
    for(int i = 0; i < 8; i++){
        printf("%d ", i);
        for(int j = 0; j < 8; j++){
            if(board[i][j] == 0){
                printf(". ");
            }
            else if(board[i][j] == 1){
                printf("O ");
            }
            else if(board[i][j] == -1){
                printf("X ");
            }
        }
        printf("\n");
    }
}

void move(int x1, int y1, int x2, int y2) { // function to move a piece

    if (board[x1][y1] == 0) { // check if there is no piece to move
        printf("There is no piece to move\n\n");
        return;
    }
    if (x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) { // check if the new coordinates are within bounds
        printf("Invalid move\n\n");
        return;
    }
    if (board[x2][y2] != 0) { // check if the new position is already occupied
        printf("Invalid move\n\n");
        return;
    }

    int dx = x2 - x1, dy = y2 - y1;
    int dirx = dx / ((dx == 0) ? 1 : abs(dx));
    int diry = dy / ((dy == 0) ? 1 : abs(dy));

    if (abs(dx) != abs(dy)) { // check if the move is diagonal
        printf("Invalid move\n\n");
        return;
    }
    if (abs(dx) == 1) { // if the move is just one step

        if (abs(board[x1][y1]) == 1 || board[x1][y1] == 2) { // if it is a regular piece or a king

            if (board[x1][y1] == 1 && dirx == -1) { // if it is a regular piece and tries to move backwards
                printf("Invalid move\n\n");
                return;
            }
            if (board[x1][y1] == -1 && dirx == 1) { // if it is a regular piece and tries to move backwards
                printf("Invalid move\n\n");
                return; 
            }
            board[x2][y2] = board[x1][y1];
            board[x1][y1] = 0;
        }
        else { // if the move is not diagonal or it's not just one step
            printf("Invalid move\n\n");
            return;
        }
    }
    else { // if the move is more than one step

        int piece = board[x1][y1];
        int x = x1 + dirx, y = y1 + diry;
        int count = 0; // count the number of pieces it jumps over

        while (x >= 0 && x < 8 && y >= 0 && y < 8) {

            if (board[x][y] != 0) { // if there is a piece on the way

                if (board[x][y] * piece < 0 && count == abs(dx) - 1) { // if the piece is an opposite player's piece and it's the last one it jumps over
                    board[x2][y2] = piece;
                    board[x1][y1] = 0;
                    board[x][y] = 0;
                }
                else { // if there's some other problem with the way
                    printf("Invalid move\n\n");
                    return;
                }
                break;
            }
            if (count > abs(dx)) { // if it jumps over too many pieces
                printf("Invalid move\n\n");
                return;
            }
            x += dirx;
            y += diry;
            count++;
        }
    }

    if (board[x2][y2] == 1 && x2 == 0) { // check if a regular piece reaches the opposite edge
        board[x2][y2] = 2;
    }
    if (board[x2][y2] == -1 && x2 == 7) { // check if a regular piece reaches the opposite edge
        board[x2][y2] = -2;
    }

    print_board(); // print the board after the move
}

int main() {

    print_board();
    move(2, 1, 3, 0); // invalid move
    move(2, 1, 3, 2); // valid move
    move(3, 2, 4, 3); // invalid move
    move(3, 2, 2, 1); // invalid move
    move(3, 2, 4, 1); // valid move
    move(5, 0, 3, 2); // valid jump move
    move(2, 1, 0, 3); // valid jump move
    move(2, 3, 4, 1); // invalid jump move
    move(5, 2, 3, 0); // invalid jump move

    return 0;
}