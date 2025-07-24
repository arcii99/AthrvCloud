//FormAI DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(int board[][COLS], int vis[][COLS]) {
    printf("\n");
    printf("  ");
    for(int i=1; i<=COLS; i++)
        printf("%d ", i);
    printf("\n");

    for(int i=0; i<ROWS; i++) {
        printf("%d ", i+1);
        for(int j=0; j<COLS; j++) {
            if(vis[i][j] == 1) {
                printf("%d ", board[i][j]);
            }
            else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS] = {0};
    int vis[ROWS][COLS] = {0};
    int temp_board[ROWS*COLS] = {0};
    int score = 0;

    srand(time(NULL));

    for(int i=0; i<(ROWS*COLS)/2; i++) {
        int val = rand() % 10 + 1;
        int cnt = 0;
        for(int j=0; j<ROWS; j++) {
            for(int k=0; k<COLS; k++) {
                if(board[j][k] == val) {
                    cnt++;
                }
            }
        }
        if(cnt == 2) {
            i--;
        }
        else {
            for(int j=0; j<2; j++) {
                while(1) {
                    int x = rand() % ROWS;
                    int y = rand() % COLS;
                    if(board[x][y] == 0) {
                        board[x][y] = vis[x][y] = val;
                        temp_board[i*2+j] = ROWS*x + y;
                        break;
                    }
                }
            }
        }
    }

    print_board(board, vis);

    while(1) {
        int x1, y1, x2, y2;
        printf("Enter cell co-ordinates to open: ");
        scanf("%d%d", &x1, &y1);
        x1--; y1--;
        if(vis[x1][y1] == 1) {
            printf("cell is already open\n");
            continue;
        }

        vis[x1][y1] = 1;
        print_board(board, vis);

        printf("Enter second cell co-ordinates to open: ");
        scanf("%d%d", &x2, &y2);
        x2--; y2--;
        if(vis[x2][y2] == 1) {
            printf("cell is already open\n");
            vis[x1][y1] = 0;
            continue;
        }

        vis[x2][y2] = 1;
        print_board(board, vis);

        if(board[x1][y1] != board[x2][y2]) {
            vis[x1][y1] = vis[x2][y2] = 0;
        }
        else {
            score++;
            if(score == (ROWS*COLS)/2) {
                printf("you won the game\n");
                return 0;
            }
        }
    }

    return 0;
}