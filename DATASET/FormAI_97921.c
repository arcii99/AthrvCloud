//FormAI DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int board[ROWS][COLS];
int prev_board[ROWS][COLS];

void init_board(){
    int counter = 1;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = counter;
            prev_board[i][j] = -1;
            counter++;
        }
    }
}

void shuffle_board(){
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            int rand_row = rand() % ROWS;
            int rand_col = rand() % COLS;
            
            int temp = board[i][j];
            board[i][j] = board[rand_row][rand_col];
            board[rand_row][rand_col] = temp;
        }
    }
}

void print_board(){
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(prev_board[i][j] != -1){
                printf("%d ", prev_board[i][j]);
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void update_board(int row1, int col1, int row2, int col2){
    prev_board[row1][col1] = board[row1][col1];
    prev_board[row2][col2] = board[row2][col2];
}

int check_if_won(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(prev_board[i][j] == -1){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    init_board();
    shuffle_board();
    int player1_score = 0, player2_score = 0;
    int current_player = 1;
    int row1, col1, row2, col2;
    
    printf("Welcome to the Memory Game!\n\n");
    printf("Instructions:\n");
    printf("- Players take turns selecting 2 cards to flip over.\n");
    printf("- If the 2 cards match, the player earns 1 point.\n");
    printf("- The game ends when all cards are matched.\n");
    
    while(!check_if_won()){
        printf("Player %d's turn:\n", current_player);
        print_board();
        printf("Enter the row and column of the first card to flip over: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the row and column of the second card to flip over: ");
        scanf("%d %d", &row2, &col2);
        
        if(board[row1][col1] == board[row2][col2]){
            if(current_player == 1){
                player1_score++;
            } else {
                player2_score++;
            }
            printf("Matching cards found! Player %d earns 1 point.\n", current_player);
        } else {
            printf("No match found.\n");
        }
        
        update_board(row1, col1, row2, col2);
        current_player = (current_player == 1) ? 2 : 1;
    }
    
    printf("Game Over!\n");
    printf("Final Scores:\n");
    printf("Player 1: %d\n", player1_score);
    printf("Player 2: %d\n", player2_score);
    
    return 0;
}