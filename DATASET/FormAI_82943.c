//FormAI DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

/* Function prototype */
void initialize_board(int board[][COLS]);
void shuffle(int board[][COLS]);
void print_board(int board[][COLS], int revealed[][COLS]);
int check_match(int board[][COLS], int revealed[][COLS], int r1, int c1, int r2, int c2);

/* Main function */
int main() {
    int board[ROWS][COLS];  /* Matrix board of size ROWS x COLS */
    int revealed[ROWS][COLS] = {0};  /* Matrix holding whether each tile has been revealed */
    int r1, c1, r2, c2;  /* Variables to hold row and column values of user input */
    int count = 0;  /* Keep track of number of pairs matched */
    
    initialize_board(board);  /* Initialize board with values 1 to (ROWS x COLS) */
    shuffle(board);  /* Shuffle board */
    
    /* Keep playing game until all pairs are matched */
    while (count < (ROWS * COLS) / 2) {
        print_board(board, revealed);  /* Print current state of board */
        
        /* Get input from user for the two tiles to reveal */
        printf("Enter the row and column values of the first tile: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter the row and column values of the second tile: ");
        scanf("%d %d", &r2, &c2);
        
        /* Check if the two tiles form a valid pair */
        if (check_match(board, revealed, r1, c1, r2, c2)) {
            count++;  /* Increment count of matched pairs */
            printf("You have matched %d pairs!\n", count);
        }
        else {
            printf("Sorry, those tiles do not form a valid pair.\n");
        }
    }
    printf("Congratulations! You have matched all pairs!\n");
    
    return 0;
}

/* Function to initialize board with values 1 to (ROWS x COLS) */
void initialize_board(int board[][COLS]) {
    int i, j, count = 1;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = count++;
        }
    }
}

/* Function to shuffle board */
void shuffle(int board[][COLS]) {
    int i, j, temp, r1, c1, r2, c2;
    srand(time(NULL));  /* seed the random number generator with current time */
    
    /* Swap randomly selected pairs of tiles 100 times */
    for (i = 0; i < 100; i++) {
        r1 = rand() % ROWS;  /* Generate random row index */
        c1 = rand() % COLS;  /* Generate random column index */
        r2 = rand() % ROWS;
        c2 = rand() % COLS;
        
        /* Swap values at indices (r1,c1) and (r2,c2) */
        temp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = temp; 
    }
}

/* Function to print current state of board */
void print_board(int board[][COLS], int revealed[][COLS]) {
    int i, j;
    printf("\nCurrent board state:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (revealed[i][j]) {  /* If tile is revealed, print value at index */
                printf("%-4d", board[i][j]);
            }
            else {  /* If tile is not revealed, print "X" */
                printf("X   ");
            }
        }
        printf("\n");
    }
}

/* Function to check if the two tiles form a valid pair */
int check_match(int board[][COLS], int revealed[][COLS], int r1, int c1, int r2, int c2) {
    if (board[r1][c1] == board[r2][c2] &&     /* Check if tiles have the same value */
        revealed[r1][c1] == 0 && revealed[r2][c2] == 0 &&  /* Check if tiles have not yet been revealed */
        (r1 != r2 || c1 != c2)) {  /* Check if tiles are not the same tile */
        revealed[r1][c1] = 1;  /* Set revealed value of both tiles to 1 */
        revealed[r2][c2] = 1;
        return 1;  /* Return 1 to indicate valid pair */
    }
    else {
        return 0;  /* Return 0 to indicate invalid pair */
    }
}