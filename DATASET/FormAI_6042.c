//FormAI DATASET v1.0 Category: Checkers Game ; Style: puzzling
#include <stdio.h>

int main()
{
    int board[8][8] = {
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,2,0,2,0,2,0,2},
        {2,0,2,0,2,0,2,0},
        {0,2,0,2,0,2,0,2}
    };
    
    int turn = 1;
    int moves[48][4];
    int num_moves = 0;
    
    while (1) {
        
        //Print board
        printf("\n");
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        
        //Get input
        printf("\nPlayer %d move (x1,y1,x2,y2): ", turn);
        int x1, y1, x2, y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        
        //Check move is valid
        if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        if (board[x1][y1] == 0 || board[x2][y2] != 0) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        if (turn == 1 && board[x1][y1] == 2) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        if (turn == 2 && board[x1][y1] == 1) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        //Check if move is a jump
        int is_jump = 0;
        if ((turn == 1 && x2 == x1-2) || (turn == 2 && x2 == x1+2)) {
            if (y2 == y1+2 && board[x1-1][y1+1] == 3-turn) {
                is_jump = 1;
            }
            if (y2 == y1-2 && board[x1-1][y1-1] == 3-turn) {
                is_jump = 1;
            }
        }
        if ((turn == 1 && x2 == x1+2) || (turn == 2 && x2 == x1-2)) {
            if (y2 == y1+2 && board[x1+1][y1+1] == 3-turn) {
                is_jump = 1;
            }
            if (y2 == y1-2 && board[x1+1][y1-1] == 3-turn) {
                is_jump = 1;
            }
        }
        
        if (is_jump == 1) {
            if (turn == 1) {
                board[x1-1][y1+1] = 0;
                board[x1-1][y1-1] = 0;
            }
            if (turn == 2) {
                board[x1+1][y1+1] = 0;
                board[x1+1][y1-1] = 0;
            }
        }
        
        //Update board
        board[x1][y1] = 0;
        board[x2][y2] = turn;
        
        //Check if game over
        int p1_pieces = 0;
        int p2_pieces = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 1) {
                    p1_pieces++;
                }
                if (board[i][j] == 2) {
                    p2_pieces++;
                }
            }
        }
        if (p1_pieces == 0) {
            printf("Player 2 wins!");
            break;
        }
        if (p2_pieces == 0) {
            printf("Player 1 wins!");
            break;
        }
        
        //Switch turn
        if (is_jump == 0) {
            turn = 3-turn;
        }
        
        //Add move to list of moves
        moves[num_moves][0] = x1;
        moves[num_moves][1] = y1;
        moves[num_moves][2] = x2;
        moves[num_moves][3] = y2;
        num_moves++;
    }
    
    //Print all moves made
    printf("\nMoves made:\n");
    for (int i = 0; i < num_moves; i++) {
        printf("%d %d %d %d\n", moves[i][0], moves[i][1], moves[i][2], moves[i][3]);
    }
    
    return 0;
}