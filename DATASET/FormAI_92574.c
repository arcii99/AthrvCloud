//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

void display_board(char board[BOARD_SIZE][BOARD_SIZE]){
    printf("Current Board: \n\n");

    printf("   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |\n");
    printf("---|---|---|---|---|---|---|---|---|---|---|\n");

    for(int i = 0; i < BOARD_SIZE; i++){
        printf(" %d | ", i);
        for(int j = 0; j < BOARD_SIZE; j++){
            printf("%c | ", board[i][j]);
        }
        printf("\n");
        printf("---|---|---|---|---|---|---|---|---|---|\n");
    }
}

void place_bombs(char board[BOARD_SIZE][BOARD_SIZE], int num_of_bombs){
    int bombs_placed = 0;

    while(bombs_placed < num_of_bombs){
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;

        if(board[x][y] != '*'){
            board[x][y] = '*';
            bombs_placed++;
        }
    }
}

void place_numbers(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int x = 0; x < BOARD_SIZE; x++){
        for(int y = 0; y < BOARD_SIZE; y++){
            if(board[x][y] != '*'){
                int num_of_bombs = 0;

                for(int i = -1; i <= 1; i++){
                    for(int j = -1; j <= 1; j++){
                        int x_loc = x + i;
                        int y_loc = y + j;

                        if(x_loc >= 0 && x_loc < BOARD_SIZE && 
                           y_loc >= 0 && y_loc < BOARD_SIZE && 
                           board[x_loc][y_loc] == '*'){
                            num_of_bombs++;
                        }
                    }
                }

                if(num_of_bombs > 0){
                    board[x][y] = num_of_bombs + '0';
                }
            }
        }
    }
}

int get_user_input(){
    printf("Enter location (row, column): ");
    int x, y;
    scanf("%d %d", &x, &y);
    return x * 10 + y;
}

int main(){
    srand(time(NULL));

    char board[BOARD_SIZE][BOARD_SIZE];
    for(int x = 0; x < BOARD_SIZE; x++){
        for(int y = 0; y < BOARD_SIZE; y++){
            board[x][y] = '-';
        }
    }

    int num_of_bombs = BOARD_SIZE * BOARD_SIZE / 4;
    place_bombs(board, num_of_bombs);
    place_numbers(board);

    int num_of_moves = BOARD_SIZE * BOARD_SIZE - num_of_bombs;
    int num_of_wins = 0;

    while(num_of_moves > 0 && num_of_wins < num_of_bombs){
        display_board(board);
        int user_input = get_user_input();

        int x = user_input / 10;
        int y = user_input % 10;

        if(board[x][y] == '*'){
            printf("You hit a bomb! Game over!\n");
            return 0;
        }

        if(board[x][y] != '-'){
            printf("You already hit that location! Please try again.\n");
        }

        else{
            board[x][y] = 'X';
            num_of_moves--;
            if(board[x][y] == '*'){
                num_of_wins++;
            }
        }
    }

    if(num_of_wins == num_of_bombs){
        display_board(board);
        printf("Congratulations! You won the game!\n");
    }

    return 0;
}