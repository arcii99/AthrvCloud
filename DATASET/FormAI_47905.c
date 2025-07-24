//FormAI DATASET v1.0 Category: Memory Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COLUMN 4

int board[ROW][COLUMN]; // Defining 4x4 memory board
int revealed[ROW][COLUMN]; // Defining 2D array to keep track of revealed tiles
int tiles_remaining; // Keeping count of revealed tiles

void initialize_board() {
    // Initializing board to all zeros
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COLUMN; j++) {
            board[i][j] = 0;
            revealed[i][j] = 0;
        }
    }
    
    int value = 1;
    srand(time(0)); // Setting seed for random numbers
    
    // Randomly placing pairs of numbers on the board
    for(int k=0; k<2; k++) {
        for(int i=0; i<ROW; i++) {
            for(int j=0; j<COLUMN; j++) {
                if(board[i][j] == 0) { // This spot is empty 
                    int r1 = rand() % ROW;
                    int c1 = rand() % COLUMN;
                    int r2 = rand() % ROW;
                    int c2 = rand() % COLUMN;

                    // If (r1, c1) and (r2, c2) spots are empty and not same
                    if(board[r1][c1] == 0 && board[r2][c2] == 0 && (r1 != r2 || c1 != c2)) {
                        board[r1][c1] = value;
                        board[r2][c2] = value;
                        value++; // Incrementing the values for next pair
                    }
                }
            }
        }
    }
}

void print_board() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COLUMN; j++) {
            if(revealed[i][j] == 1) {
                printf("%d ", board[i][j]);
            }
            else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int game_over() {
    if(tiles_remaining == 0) {
        return 1;
    }
    return 0;
}

void play_game() {
    initialize_board();
    tiles_remaining = ROW*COLUMN;
    
    while(!game_over()) {
        printf("Enter the row: ");
        int r1 = 0;
        scanf("%d", &r1);
        printf("Enter the column: ");
        int c1 = 0;
        scanf("%d", &c1);
        
        // Checking if the tile is not already revealed
        if(revealed[r1][c1] == 1) {
            printf("This tile is already revealed! Pick another one.\n");
            continue;
        }
        
        revealed[r1][c1] = 1;
        print_board();
        
        printf("Enter another row: ");
        int r2 = 0;
        scanf("%d", &r2);
        printf("Enter another column: ");
        int c2 = 0;
        scanf("%d", &c2);
        
        if(revealed[r2][c2] == 1) {
            printf("This tile is already revealed! Pick another one.\n");
            revealed[r1][c1] = 0; // Flip back the previously revealed tile 
            continue;
        }
        
        revealed[r2][c2] = 1;
        print_board();
        
        if(board[r1][c1] == board[r2][c2]) {
            printf("You found a match!\n");
            tiles_remaining -= 2; // Decrementing the tiles remaining
        }
        else {
            printf("Oops, not a match!\n");
            revealed[r1][c1] = 0; // Flip back both the tiles
            revealed[r2][c2] = 0;
        }
    }
    
    printf("Congratulations! You have completed the game.\n");
}

int main() {
    play_game();
    return 0;
}