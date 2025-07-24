//FormAI DATASET v1.0 Category: Chess engine ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[8][8] = {
    {-1, -2, -3, -4, -5, -3, -2, -1},
    {-6, -6, -6, -6, -6, -6, -6, -6},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {6, 6, 6, 6, 6, 6, 6, 6},
    {1, 2, 3, 4, 5, 3, 2, 1}
};

void print_board(){
    int i, j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int white_can_capture(int x, int y){
    int i, j;
    int current, next;

    if(board[x][y] == 1){ // white pawn
        if(board[x-1][y-1] == -6) return 1;
        if(board[x-1][y+1] == -6) return 1;
    }

    return 0;
}

int black_can_capture(int x, int y){
    int i, j;
    int current, next;

    if(board[x][y] == -1){ // black pawn
        if(board[x+1][y-1] == 6) return 1;
        if(board[x+1][y+1] == 6) return 1;
    }

    return 0;
}

int can_capture(int x, int y, int color){
    if(color == 1) return white_can_capture(x, y);
    return black_can_capture(x, y);
}

int can_move(int x, int y, int color){
    int current, next;

    if(color == 1){
        current = board[x][y];
        next = board[x-1][y];

        if(next == 0) return 1;
        
        return 0;
    }else{
        current = board[x][y];
        next = board[x+1][y];

        if(next == 0) return 1;

        return 0;
    }
}

void play_round(){
    int x, y;
    int captures[5][2];
    int capture_count = 0;
    int i, j;

    printf("Enter starting coordinates: (x, y) ");
    scanf("%d %d", &x, &y);

    if(can_capture(x, y, board[x][y]) == 1){
        printf("This piece can capture! Possible moves:\n");
        if(board[x][y] == 1){ // white pawn
            if(board[x-1][y-1] == -6){
                printf("%d %d\n", x-1, y-1);
                captures[capture_count][0] = x-1;
                captures[capture_count][1] = y-1;
                capture_count++;
            }
            if(board[x-1][y+1] == -6){
                printf("%d %d\n", x-1, y+1);
                captures[capture_count][0] = x-1;
                captures[capture_count][1] = y+1;
                capture_count++;
            }
        }
        if(board[x][y] == -1){ // black pawn
            if(board[x+1][y-1] == 6){
                printf("%d %d\n", x+1, y-1);
                captures[capture_count][0] = x+1;
                captures[capture_count][1] = y-1;
                capture_count++;
            }
            if(board[x+1][y+1] == 6){
                printf("%d %d\n", x+1, y+1);
                captures[capture_count][0] = x+1;
                captures[capture_count][1] = y+1;
                capture_count++;
            }
        }
    }else{
        printf("This piece cannot capture. Possible moves:\n");
        if(can_move(x, y, board[x][y]) == 1){
            if(board[x][y] == 1){ // white pawn
                if(board[x-1][y] == 0){
                    printf("%d %d\n", x-1, y);
                }
            }
            if(board[x][y] == -1){ // black pawn
                if(board[x+1][y] == 0){
                    printf("%d %d\n", x+1, y);
                }
            }
        }else{
            printf("This piece is pinned and cannot move.\n");
            return;
        }
    }

    printf("Enter end coordinates: (x, y) ");
    scanf("%d %d", &x, &y);

    int valid_move = 0;

    if(capture_count > 0){
        for(i=0; i<capture_count; i++){
            if(x == captures[i][0] && y == captures[i][1]) valid_move = 1;
        }
    }else{
        if(can_move(x, y, board[x][y])) valid_move = 1;
    }

    if(valid_move){
        board[x][y] = board[x][y-1];
        board[x][y-1] = 0;
    }else{
        printf("Invalid move. Please try again.\n");
    }
}

int main(){
    srand(time(NULL));

    printf("Welcome to Chess Game!\n");
    printf("-----------------------\n");

    while(1){
        print_board();

        play_round();

        printf("-----------------------\n");
    }

    return 0;
}