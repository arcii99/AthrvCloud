//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

// Define game constants
#define ROWS 10
#define COLS 10
#define NUM_MINES 15

// Define the game board
int board[ROWS][COLS];

// Define a struct to hold the user's position
typedef struct {
    int row;
    int col;
} Position;

// Define a struct to hold the thread arguments
typedef struct {
    int id;
    Position pos;
} ThreadArgs;

// Define a function to initialize the game board with mines and numbers
void init_board() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Clear the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
    
    // Add mines to the board
    int num_mines = 0;
    while (num_mines < NUM_MINES) {
        int i = rand() % ROWS;
        int j = rand() % COLS;
        if (board[i][j] == 0) {
            board[i][j] = -1;
            num_mines++;
        }
    }
    
    // Add numbers to the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                // This is a mine, so skip it
                continue;
            }
            int count = 0;
            // Check the 8 surrounding squares
            for (int ii = -1; ii <= 1; ii++) {
                for (int jj = -1; jj <= 1; jj++) {
                    if (i+ii < 0 || i+ii >= ROWS || j+jj < 0 || j+jj >= COLS) {
                        // This square is off the board, so skip it
                        continue;
                    }
                    if (board[i+ii][j+jj] == -1) {
                        // This is a mine, so count it
                        count++;
                    }
                }
            }
            board[i][j] = count;
        }
    }
}

// Define a function to print the board to the screen
void print_board() {
    printf("  ");
    for (int j = 0; j < COLS; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] > 0 ? (char)(board[i][j]+'0') : (board[i][j] == 0 ? '.' : '*'));
        }
        printf("\n");
    }
}

// Define a function to update the board when a square is clicked
bool update_board(Position pos) {
    if (board[pos.row][pos.col] == -1) {
        // This is a mine, so the game is over
        return false;
    }
    if (board[pos.row][pos.col] > 0) {
        // This is a number, so reveal it
        return true;
    }
    // This is an empty square, so reveal it and all surrounding squares
    board[pos.row][pos.col] = -2;
    for (int ii = -1; ii <= 1; ii++) {
        for (int jj = -1; jj <= 1; jj++) {
            if (pos.row+ii < 0 || pos.row+ii >= ROWS || pos.col+jj < 0 || pos.col+jj >= COLS) {
                // This square is off the board, so skip it
                continue;
            }
            if (board[pos.row+ii][pos.col+jj] == 0) {
                // This is an empty square, so update it recursively
                Position new_pos = {pos.row+ii, pos.col+jj};
                update_board(new_pos);
            } else if (board[pos.row+ii][pos.col+jj] > 0) {
                // This is a number, so reveal it
                board[pos.row+ii][pos.col+jj] *= -1;
            }
        }
    }
    return true;
}

// Define the thread function
void* thread_func(void* args) {
    ThreadArgs* thread_args = (ThreadArgs*)args;
    printf("Thread %d started.\n", thread_args->id);
    while (true) {
        // Get user input
        printf("Thread %d, enter row: ", thread_args->id);
        int row;
        scanf("%d", &row);
        printf("Thread %d, enter col: ", thread_args->id);
        int col;
        scanf("%d", &col);
        Position pos = {row, col};
        
        // Update the board
        bool success = update_board(pos);
        if (!success) {
            // This thread hit a mine, so end the game
            printf("Game over! Thread %d hit a mine.\n", thread_args->id);
            pthread_exit(NULL);
        }
        
        // Print the updated board
        print_board();
    }
}

int main() {
    // Initialize the game board
    init_board();
    
    // Print the board to the screen
    print_board();
    
    // Create the threads
    pthread_t thread1, thread2;
    ThreadArgs args1 = {1, {0, 0}};
    ThreadArgs args2 = {2, {ROWS-1, COLS-1}};
    pthread_create(&thread1, NULL, thread_func, (void*)&args1);
    pthread_create(&thread2, NULL, thread_func, (void*)&args2);
    
    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}