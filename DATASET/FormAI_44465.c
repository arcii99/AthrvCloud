//FormAI DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 6

void print_board(int board[ROWS][COLS], int guess_board[ROWS][COLS]);
int make_guess(int board[ROWS][COLS], int guess_board[ROWS][COLS], int row, int col);
int get_random_num(int min, int max);
void initialize_board(int board[ROWS][COLS], int guess_board[ROWS][COLS]);

int main() {
    int board[ROWS][COLS];
    int guess_board[ROWS][COLS];
    int count = 0;
    int row = 0;
    int col = 0;
    int num_mines = 0;
    
    srand(time(0)); 
    
    // initialize board
    initialize_board(board, guess_board);
    
    // get user input      
    printf("How many mines do you want in the game? (maximum %d): ", ROWS * COLS);
    scanf("%d", &num_mines);
    while(num_mines > ROWS * COLS) {
        printf("You cannot have more than %d mines. Please try again. ", ROWS * COLS);
        scanf("%d", &num_mines);
    }

    // randomly place mines on board
    while(count < num_mines) {
        row = get_random_num(0, ROWS);
        col = get_random_num(0, COLS);
        
        if(board[row][col] != -1) {
            board[row][col] = -1;
            count++;
        }
    }
    
    // print blank guess board
    printf("\n");
    print_board(board, guess_board);
    
    // let user make guesses until they win or lose
    while(1) {
        printf("Please enter row and column to guess: ");
        scanf("%d %d", &row, &col);
        
        if(make_guess(board, guess_board, row, col) == -1) {
            printf("Game Over! You hit a mine.\n");
            print_board(board, guess_board);
            break;
        } else if( guess_board[row][col] != 0) {
            printf("You already guessed that spot. Try again.\n");
        } else if(guess_board[row][col] == 0) { 
            print_board(board, guess_board);
        }
        
        // check to see if user has won
        int win = 1;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(guess_board[i][j] == 0 && board[i][j] != -1) {
                    win = 0;
                    break;
                }
            }
        }
        if(win) {
            printf("Congratulations! You won the game!\n");
            print_board(board, guess_board);
            break;
        }
    }       
                 
    return 0;
}

// prints the guess board with X's for unknown spots
void print_board(int board[ROWS][COLS], int guess_board[ROWS][COLS]) {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(guess_board[i][j] == 1) {
                printf("%d ", board[i][j]);
            } else if(guess_board[i][j] == -1) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// user makes a guess
int make_guess(int board[ROWS][COLS], int guess_board[ROWS][COLS], int row, int col) {
    if(board[row][col] == -1) {
        guess_board[row][col] = -1;
        return -1;
    } else {
        guess_board[row][col] = 1;
        // check for adjacent mines
        int count = 0;
        if(row > 0 && board[row-1][col] == -1) { // top
            count++;
        } 
        if(row < ROWS - 1 && board[row+1][col] == -1) { // bottom
            count++;
        }
        if(col > 0 && board[row][col-1] == -1) { // left
            count++;
        }
        if(col < COLS - 1 && board[row][col+1] == -1) { // right
            count++;
        }
        guess_board[row][col] = count;
        
        return 0;
    }
}

// generates random number within min and max range
int get_random_num(int min, int max) {
    return (rand() % (max - min)) + min;
}

// initializes the board with all zeros
void initialize_board(int board[ROWS][COLS], int guess_board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = 0;
            guess_board[i][j] = 0;
        }
    }
}