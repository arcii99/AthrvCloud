//FormAI DATASET v1.0 Category: Game of Life ; Style: romantic
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

// Declare global variables
const int ROWS = 20;
const int COLUMNS = 20;
int current_board[20][20];
int next_board[20][20];

// Function prototypes
void initialize_board();
void generate_board();
void display_board();
int get_live_neighbours(int i, int j);
void update_board();

int main() {
    initialize_board();
    generate_board();
    display_board();

    // Update the board
    while (1) {
        update_board();
        display_board();
        sleep(1);
    }

    return 0;
}

// Initialize the Game of Life board with random values
void initialize_board(){
    srand(time(NULL));
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLUMNS; ++j) {
            current_board[i][j] = rand() % 2;
        }
    }
}

// Generate the next state of the Game of Life board
void generate_board(){
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLUMNS; ++j) {
            const int live_neighbours = get_live_neighbours(i, j);
            if(current_board[i][j] == 1) {
                if (live_neighbours == 2 || live_neighbours == 3) {
                    next_board[i][j] = 1;
                }
                else {
                    next_board[i][j] = 0;
                }
            }
            else if (live_neighbours == 3) {
                next_board[i][j] = 1;
            }
            else {
                next_board[i][j] = 0;
            }
        }
    }

    // Copy the new board into the current board
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLUMNS; ++j) {
            current_board[i][j] = next_board[i][j];
        }
    }
}

// Display the Game of Life board
void display_board(){
    system("clear");
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLUMNS; ++j) {
            printf("%c", current_board[i][j] == 1 ? 'O' : ' ');
        }
        printf("\n");
    }
}

// Get the number of live neighbors for a given cell
int get_live_neighbours(int i, int j){
    int count = 0;
    for(int x = -1; x <= 1; ++x) {
        for(int y = -1; y <= 1; ++y) {
            if (x == 0 && y == 0) {
                continue;
            }
            const int row = (i + x + ROWS) % ROWS;
            const int column = (j + y + COLUMNS) % COLUMNS;
            count += current_board[row][column];
        }
    }
    return count;
}

// Update the Game of Life board with the next state
void update_board(){
    generate_board();
}