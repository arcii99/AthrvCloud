//FormAI DATASET v1.0 Category: Memory Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // size of the game board 

// function to print the game board
void print_board(int board[][BOARD_SIZE], int is_hidden) {
    printf("  ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
        for(int j=0; j<BOARD_SIZE; j++) {
            if(!is_hidden || board[i][j] == -1) { // if not hidden or is a hidden tile
                printf("%d ", board[i][j]);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// function to check if the game is over
int is_game_over(int board[][BOARD_SIZE], int hidden_tiles) {
    return !hidden_tiles;
}

// function to get a random number within a range
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// main function
int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0}; // initialize board with 0
    int hidden_tiles = BOARD_SIZE * BOARD_SIZE; // count of hidden tiles
    
    // set up random number generator
    srand(time(NULL));
    
    // place numbers randomly on the board
    for(int i=1; i<=hidden_tiles/2; i++) {
        int count = 0;
        while(count < 2) {
            int row = get_random_number(0, BOARD_SIZE-1);
            int col = get_random_number(0, BOARD_SIZE-1);
            if(board[row][col] == 0) { // if the tile is not occupied
                board[row][col] = i;
                count++;
            }
        }
    }
    
    // print instructions
    printf("Welcome to the Memory Game!\n");
    printf("Instructions:\n");
    printf("- You will see a board with hidden tiles\n");
    printf("- Each tile has a number between 1 and %d\n", hidden_tiles/2);
    printf("- Your goal is to match all pairs of tiles with the same number\n");
    printf("- Enter the row and column of the first tile you want to flip\n");
    printf("- Then enter the row and column of the second tile you want to flip\n");
    printf("- If the tiles match, they will be removed from the board\n");
    printf("- If the tiles do not match, they will be hidden again\n\n");
    
    // start game loop
    while(!is_game_over(board, hidden_tiles)) {
        system("clear"); // clear screen (for Unix-like systems)
        print_board(board, 1); // print board with hidden tiles
        
        // get input for first tile
        int row1, col1;
        printf("Enter the row and column of the first tile: ");
        scanf("%d %d", &row1, &col1);
        while(row1 < 0 || row1 >= BOARD_SIZE || col1 < 0 || col1 >= BOARD_SIZE) { // validate input
            printf("Invalid input. Please enter row and column between 0 and %d: ", BOARD_SIZE-1);
            scanf("%d %d", &row1, &col1);
        }
        
        // flip first tile
        board[row1][col1] = -1;
        hidden_tiles--;
        system("clear");
        print_board(board, 0); // print board with revealed tiles
        
        // get input for second tile
        int row2, col2;
        printf("Enter the row and column of the second tile: ");
        scanf("%d %d", &row2, &col2);
        while(row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE) { // validate input
            printf("Invalid input. Please enter row and column between 0 and %d: ", BOARD_SIZE-1);
            scanf("%d %d", &row2, &col2);
        }
        
        // flip second tile
        board[row2][col2] = -1;
        hidden_tiles--;
        system("clear");
        print_board(board, 0); // print board with revealed tiles
        
        // check if tiles match
        if(board[row1][col1] == board[row2][col2]) { // if match
            printf("Tiles match!\n");
            board[row1][col1] = 0;
            board[row2][col2] = 0;
            hidden_tiles += 2;
        } else { // if not match
            printf("Tiles do not match. Try again!\n");
            board[row1][col1] = board[row2][col2] = 0;
            hidden_tiles += 2;
        }
        
        printf("\n");
    }
    
    // end game
    printf("Congratulations! You beat the Memory Game!\n");
    return 0;
}