//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cryptic
#include <stdio.h>

int main() {
    int board[8][8] = {{0,1,0,1,0,1,0,1},
                       {1,0,1,0,1,0,1,0},
                       {0,1,0,1,0,1,0,1},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {2,0,2,0,2,0,2,0},
                       {0,2,0,2,0,2,0,2},
                       {2,0,2,0,2,0,2,0}};
    int turn = 1, x1, y1, x2, y2, possible_moves = 0, jump = 0, i, j;
    
    printf("***CRYPTIC CHECKERS***\n");
    printf("Player 1 - 1\nPlayer 2 - 2\n");
    
    while(1) {
        //Print board
        printf("\n   0  1  2  3  4  5  6  7\n");
        for(i=0; i<8; i++) {
            printf("%d ", i);
            for(j=0; j<8; j++) {
                printf("[");
                if(board[i][j] == 0) printf(" ");
                else if(board[i][j] == 1) printf("1");
                else if(board[i][j] == 2) printf("2");
                printf("]");
            }
            printf("\n");
        }
        
        //Check if game is over
        int p1_pieces = 0, p2_pieces = 0;
        for(i=0; i<8; i++) {
            for(j=0; j<8; j++) {
                if(board[i][j] == 1) p1_pieces++;
                if(board[i][j] == 2) p2_pieces++;
            }
        }
        if(p1_pieces == 0) {
            printf("Player 2 wins!\n");
            break;
        }
        if(p2_pieces == 0) {
            printf("Player 1 wins!\n");
            break;
        }
        
        //Get player input
        if(turn == 1) printf("Player 1 turn: ");
        else printf("Player 2 turn: ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        //Check if selected piece is valid
        if(board[x1][y1] == turn || board[x1][y1] == turn+2) {
            //Check if move is valid
            if(board[x2][y2] == 0) {
                //Check if regular move or jump
                if(abs(x2-x1) == abs(y2-y1)) {
                    if(!jump) {
                        if(turn == 1 && x2 < x1) {
                            printf("Invalid move!\n");
                            continue;
                        }
                        else if(turn == 2 && x2 > x1) {
                            printf("Invalid move!\n");
                            continue;
                        }
                        if(board[x1][y1] == 1 && abs(x2-x1) > 1) {
                            printf("Invalid move!\n");
                            continue;
                        }
                        else if(board[x1][y1] == 2 && abs(x2-x1) > 1) {
                            printf("Invalid move!\n");
                            continue;
                        }
                        board[x2][y2] = board[x1][y1];
                        board[x1][y1] = 0;
                        turn = (turn == 1) ? 2 : 1;
                    }
                    else {
                        printf("Invalid move!\n");
                        continue;
                    }
                }
                else if(abs(x2-x1) == abs(y2-y1) * 2) {
                    //Check if jump is valid
                    int jump_x = (x2+x1)/2;
                    int jump_y = (y2+y1)/2;
                    if(board[jump_x][jump_y] != (turn == 1 ? 2 : 1) && board[jump_x][jump_y] != (turn == 1 ? 4 : 3)) {
                        printf("Invalid move!\n");
                        continue;
                    }
                    board[x2][y2] = board[x1][y1];
                    board[x1][y1] = 0;
                    board[jump_x][jump_y] = 0;
                    jump = 1;
                }
                //Check for chain jumps
                possible_moves = 0;
                for(i=-2; i<=2; i+=4) {
                    for(j=-2; j<=2; j+=4) {
                        if(x2+i >= 0 && x2+i < 8 && y2+j >= 0 && y2+j < 8) {
                            if(board[x2+i][y2+j] == 0) {
                                if(board[x2+i/2][y2+j/2] == (turn == 1 ? 2 : 1) || board[x2+i/2][y2+j/2] == (turn == 1 ? 4 : 3)) {
                                    possible_moves = 1;
                                }
                            }
                        }
                    }
                }
            }
            else {
                printf("Invalid move!\n");
                continue;
            }
        }
        else {
            printf("Invalid piece selected!\n");
            continue;
        }
        
        //Check for end of jump
        if(!possible_moves && jump) {
            jump = 0;
            turn = (turn == 1) ? 2 : 1;
        }
    }
    
    return 0;
}