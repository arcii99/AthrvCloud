//FormAI DATASET v1.0 Category: Chess AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {0};
int turn = 0;

void print_board(){
    int row, col;
    printf("\n    ");
    for(col=0; col<BOARD_SIZE; col++){
        printf("%d ", col);
    }
    printf("\n   ");
    for(col=0; col<=BOARD_SIZE; col++){
        printf("--");
    }
    printf("\n");
    for(row=0; row<BOARD_SIZE; row++){
        printf("%d | ", row);
        for(col=0; col<BOARD_SIZE; col++){
            if(board[row][col] == 0){
                printf("  ");
            }
            else{
                printf("%c ", (board[row][col] == 1) ? 'P' : 'C');
            }
        }
        printf("|\n");
    }
    printf("   ");
    for(col=0; col<=BOARD_SIZE; col++){
        printf("--");
    }
    printf("\n");
}

int is_valid_move(int row, int col, int new_row, int new_col){
    if(board[row][col] == 0) return 0;
    if(new_row >= BOARD_SIZE || new_col >= BOARD_SIZE) return 0;
    if(new_row < 0 || new_col < 0) return 0;
    if(board[new_row][new_col] == 1) return 0;
    if(turn == 0 && new_row <= row) return 0;
    if(turn == 1 && new_row >= row) return 0;
    if(abs(new_row - row) > 2) return 0;
    if(abs(new_col - col) > 2) return 0;
    if(abs(new_row - row) != abs(new_col - col)) return 0;
    if(abs(new_row - row) == 2 && abs(new_col - col) == 2){
        int middle_row = (new_row + row) / 2;
        int middle_col = (new_col + col) / 2;
        if(board[middle_row][middle_col] != 1) return 0;
    }
    return 1;
}

int make_move(int row, int col, int new_row, int new_col){
    if(!is_valid_move(row, col, new_row, new_col)){
        printf("Invalid Move!\n");
        return 0;
    }

    board[row][col] = 0;
    board[new_row][new_col] = 1;

    if(abs(new_row - row) == 2 && abs(new_col - col) == 2){
        int middle_row = (new_row + row) / 2;
        int middle_col = (new_col + col) / 2;
        board[middle_row][middle_col] = 0;
    }

    turn = !turn;
    return 1;
}

int ai_make_move(){
    printf("AI is thinking...\n");

    int row, col, new_row, new_col;
    do{
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
        new_row = row + (rand() % 3) - 1;
        new_col = col + (rand() % 3) - 1;
    }while(!is_valid_move(row, col, new_row, new_col));

    return make_move(row, col, new_row, new_col);
}

int main(){
    srand(time(0));

    printf("Welcome to C Chess!\n");
    printf("Player 1, you are 'P', you move up\n");
    printf("Player 2, you are 'C', you move down\n\n");

    // initialize board
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(i%2 == 0 && j%2 == 1) board[i][j] = 1;
            if(i%2 == 1 && j%2 == 0) board[i][j] = 1;
        }
    }
    for(i=5; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(i%2 == 0 && j%2 == 1) board[i][j] = 2;
            if(i%2 == 1 && j%2 == 0) board[i][j] = 2;
        }
    }

    print_board();

    int game_over = 0;
    do{
        int row, col, new_row, new_col;
        printf("Player %d's turn.\n", turn+1);
        if(turn == 0){
            printf("Enter move as 'row col new_row new_col': ");
            scanf("%d %d %d %d", &row, &col, &new_row, &new_col);
            make_move(row, col, new_row, new_col);
        }
        else{
            ai_make_move();
        }

        print_board();

        // check for game over
        int num_pawns = 0, num_computers = 0;
        for(i=0; i<BOARD_SIZE; i++){
            for(j=0; j<BOARD_SIZE; j++){
                if(board[i][j] == 1) num_pawns++;
                if(board[i][j] == 2) num_computers++;
            }
        }
        if(num_pawns == 0){
            printf("Player 2 wins!\n");
            game_over = 1;
        }
        if(num_computers == 0){
            printf("Player 1 wins!\n");
            game_over = 1;
        }
    }while(!game_over);

    return 0;
}