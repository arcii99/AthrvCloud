//FormAI DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVES 30
#define MAX_ROUNDS 3

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]);
void print_board(int board[BOARD_SIZE][BOARD_SIZE], int moves);
int check_win(int board[BOARD_SIZE][BOARD_SIZE]);
void shuffle_board(int board[BOARD_SIZE][BOARD_SIZE]);
void swap(int* a, int* b);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int moves = 0, round = 0, result = 0;
    
    srand(time(0));  // seed random number generator
    
    while (round < MAX_ROUNDS) {
        initialize_board(board);
        shuffle_board(board);
        
        while (moves < MAX_MOVES) {
            print_board(board, moves);
            
            int row1, col1, row2, col2;
            printf("Enter two coordinates to reveal the numbers (e.g. 2 3 1 4): ");
            scanf("%d %d %d %d", &row1, &col1, &row2, &col2);
            
            // check that the coordinates are on the board
            if (row1 < 1 || row1 > BOARD_SIZE || col1 < 1 || col1 > BOARD_SIZE ||
                row2 < 1 || row2 > BOARD_SIZE || col2 < 1 || col2 > BOARD_SIZE) {
                  
                printf("Invalid coordinates. Try again.\n");
                continue;
            }
            
            // flip the tiles over
            int num1 = board[row1-1][col1-1], num2 = board[row2-1][col2-1];
            printf("Revealing numbers: %d %d\n", num1, num2);
            board[row1-1][col1-1] = num1 < 0 ? num1 : -num1;
            board[row2-1][col2-1] = num2 < 0 ? num2 : -num2;
            
            // check if the tiles match
            if (num1 == num2) {
                printf("Match found!\n");
                moves++;
            } else {
                printf("No match found.\n");
                // flip the tiles back over
                board[row1-1][col1-1] = num1 < 0 ? num1 : -num1;
                board[row2-1][col2-1] = num2 < 0 ? num2 : -num2;
                moves++;
            }
            
            // check if the game is won
            if (check_win(board)) {
                printf("Congratulations, you won in %d moves!\n", moves);
                result++;
                break;
            }
        }
        
        round++;
    }
    
    printf("Game over. You won %d out of %d rounds.\n", result, MAX_ROUNDS);
    
    return 0;
}

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    // set up the board with random numbers
    int nums[BOARD_SIZE*BOARD_SIZE/2];
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE/2; i++) {
        nums[i] = i+1;
    }
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = -nums[(i*BOARD_SIZE+j)/2];
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE], int moves) {
    printf("Moves: %d\n", moves);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int num = board[i][j];
            printf("%c ", num < 0 ? '-' : num + '0');
        }
        printf("\n");
    }
}

int check_win(int board[BOARD_SIZE][BOARD_SIZE]) {
    // check if all tiles are flipped over
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] < 0) {
                return 0;
            }
        }
    }
    
    return 1;
}

void shuffle_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    // randomly shuffle the board
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
        int row1 = rand() % BOARD_SIZE;
        int col1 = rand() % BOARD_SIZE;
        int row2 = rand() % BOARD_SIZE;
        int col2 = rand() % BOARD_SIZE;
        swap(&board[row1][col1], &board[row2][col2]);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}