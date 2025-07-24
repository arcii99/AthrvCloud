//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 5

// Initialize the bingo board
void init_board(int board[BOARD_SIZE][BOARD_SIZE]){
    int num = 1;
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            board[i][j] = num++;
        }
    }
}

// Print the bingo board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]){
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

// Shuffle the numbers on the board
void shuffle_board(int board[BOARD_SIZE][BOARD_SIZE]){
    srand(time(NULL));
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            int rand_i = rand() % BOARD_SIZE;
            int rand_j = rand() % BOARD_SIZE;
            int temp = board[i][j];
            board[i][j] = board[rand_i][rand_j];
            board[rand_i][rand_j] = temp;
        }
    }
}

// Check if there is a winning combination on the board
int check_win(int board[BOARD_SIZE][BOARD_SIZE]){
    // Check all rows
    for(int i=0; i<BOARD_SIZE; i++){
        int row_sum = 0;
        for(int j=0; j<BOARD_SIZE; j++){
            row_sum += board[i][j];
        }
        if(row_sum == 0){
            return 1;
        }
    }
    // Check all columns
    for(int i=0; i<BOARD_SIZE; i++){
        int col_sum = 0;
        for(int j=0; j<BOARD_SIZE; j++){
            col_sum += board[j][i];
        }
        if(col_sum == 0){
            return 1;
        }
    }
    // Check diagonal from top left to bottom right
    int diag_sum1 = 0;
    for(int i=0; i<BOARD_SIZE; i++){
        diag_sum1 += board[i][i];
    }
    if(diag_sum1 == 0){
        return 1;
    }
    // Check diagonal from top right to bottom left
    int diag_sum2 = 0;
    for(int i=0, j=BOARD_SIZE-1; i<BOARD_SIZE; i++, j--){
        diag_sum2 += board[i][j];
    }
    if(diag_sum2 == 0){
        return 1;
    }
    return 0;
}

int main(){
    int board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    shuffle_board(board);
    print_board(board);
    int player_count;
    printf("How many players? (max %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    if(player_count > MAX_PLAYERS){
        printf("Too many players. Setting to maximum of %d\n", MAX_PLAYERS);
        player_count = MAX_PLAYERS;
    }
    int players[player_count][BOARD_SIZE][BOARD_SIZE];
    for(int i=0; i<player_count; i++){
        printf("Player %d, enter your board:\n", i+1);
        for(int j=0; j<BOARD_SIZE; j++){
            for(int k=0; k<BOARD_SIZE; k++){
                scanf("%d", &players[i][j][k]);
            }
        }
    }
    int winner = 0;
    while(!winner){
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        int found = 0;
        for(int i=0; i<player_count; i++){
            for(int j=0; j<BOARD_SIZE; j++){
                for(int k=0; k<BOARD_SIZE; k++){
                    if(players[i][j][k] == num){
                        players[i][j][k] = 0;
                        found = 1;
                        if(check_win(players[i])){
                            printf("Player %d wins!\n", i+1);
                            winner = 1;
                            break;
                        }
                    }
                }
                if(found == 1){
                    break;
                }
            }
            if(winner == 1){
                break;
            }
        }
        if(found == 0){
            printf("Number not found on any board.\n");
        }
    }
    return 0;
}