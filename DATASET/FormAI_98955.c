//FormAI DATASET v1.0 Category: Checkers Game ; Style: standalone
#include <stdio.h>

int main() {
    //initialize board
    int board[8][8] = {
        {0, 2, 0, 2, 0, 2, 0, 2},
        {2, 0, 2, 0, 2, 0, 2, 0},
        {0, 2, 0, 2, 0, 2, 0, 2},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {3, 0, 3, 0, 3, 0, 3, 0},
        {0, 3, 0, 3, 0, 3, 0, 3},
        {3, 0, 3, 0, 3, 0, 3, 0}
    };
    
    //initialize players
    int player1 = 1; //1 for red, 2 for black
    int player2 = 2;
    
    //initialize turn
    int turn = player1;
    
    //initialize game loop
    int gameover = 0;
    
    while (!gameover) {
        //print board
        printf("    0 1 2 3 4 5 6 7\n");
        for (int i = 0; i < 8; i++) {
            printf("%d  ", i);
            for (int j = 0; j < 8; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        
        //get input
        int startx, starty, endx, endy;
        printf("Player %d, enter starting coordinates (x y): ", turn);
        scanf("%d %d", &startx, &starty);
        printf("Player %d, enter ending coordinates (x y): ", turn);
        scanf("%d %d", &endx, &endy);
        
        //validate input
        if (startx < 0 || startx > 7 || starty < 0 || starty > 7 ||
            endx < 0 || endx > 7 || endy < 0 || endy > 7) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }
        if (board[startx][starty] != turn && board[startx][starty] != turn+1) {
            printf("You don't have a piece there. Try again.\n");
            continue;
        }
        if (board[endx][endy] != 0) {
            printf("There's already a piece there. Try again.\n");
            continue;
        }
        if (abs(endx-startx) != 1 || abs(endy-starty) != 1) {
            printf("You can only move one space diagonally. Try again.\n");
            continue;
        }
        
        //make move
        board[endx][endy] = board[startx][starty];
        board[startx][starty] = 0;
        
        //check for gameover
        int redpieces = 0;
        int blackpieces = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 1 || board[i][j] == 3) {
                    redpieces++;
                } else if (board[i][j] == 2 || board[i][j] == 4) {
                    blackpieces++;
                }
            }
        }
        
        if (redpieces == 0 || blackpieces == 0) {
            gameover = 1;
            printf("Player %d wins!\n", turn);
        }
        
        //switch turn
        if (turn == player1) {
            turn = player2;
        } else {
            turn = player1;
        }
    }
    
    return 0;
}