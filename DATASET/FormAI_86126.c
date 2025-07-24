//FormAI DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

typedef struct {
    int row;
    int col;
} Position;

/**
 * Returns a random number between start and end (inclusive)
 **/
int random_number(int start, int end) {
    srand(time(NULL));
    return (rand() % (end - start + 1)) + start; 
}

/**
 * Initializes the game board with random numbers
 **/
void initialize_board(int board[][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = random_number(1, SIZE*SIZE/2);
        }
    }
}

/**
 * Prints the game board
 **/
void print_board(int board[][SIZE], Position revealed[]) {
    printf("\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(revealed[i*SIZE+j].row == i && revealed[i*SIZE+j].col == j) {
                printf("%d\t", board[i][j]);
            } else {
                printf("*\t");
            }
        }
        printf("\n");
    }
}

/**
 * Asks the user to input a valid position
 **/
Position get_user_input() {
    Position p;
    printf("Enter row and column (seperated by space): ");
    scanf("%d %d", &p.row, &p.col);
    while(p.row < 1 || p.row > SIZE || p.col < 1 || p.col > SIZE) {
        printf("Invalid input! Enter row and column (seperated by space): ");
        scanf("%d %d", &p.row, &p.col);
    }
    p.row--;
    p.col--;
    return p;
}

/**
 * Returns true if the game is over
 **/
int is_game_over(Position revealed[]) {
    for(int i=0; i<SIZE*SIZE; i++) {
        if(revealed[i].row != i/SIZE || revealed[i].col != i%SIZE) {
            return 0;
        }
    }
    return 1;
}

/**
 * Main function - starts and runs the game
 **/
int main() {
    int board[SIZE][SIZE];
    Position revealed[SIZE*SIZE];
    Position p1, p2;
    int matches = 0;

    initialize_board(board);
    for(int i=0; i<SIZE*SIZE; i++) {
        revealed[i].row = -1;
        revealed[i].col = -1;
    }

    while(!is_game_over(revealed)) {
        print_board(board, revealed);
        printf("Matches: %d\n", matches);
        printf("\n");
        p1 = get_user_input();
        revealed[p1.row*SIZE+p1.col] = p1;
        print_board(board, revealed);
        printf("Matches: %d\n", matches);
        printf("\n");
        p2 = get_user_input();
        revealed[p2.row*SIZE+p2.col] = p2;
        if(board[p1.row][p1.col] == board[p2.row][p2.col]) {
            matches++;
        } else {
            revealed[p1.row*SIZE+p1.col].row = -1;
            revealed[p1.row*SIZE+p1.col].col = -1;
            revealed[p2.row*SIZE+p2.col].row = -1;
            revealed[p2.row*SIZE+p2.col].col = -1;
        }
    }

    printf("Congratulations! You won the game in %d matches.\n", matches);

    return 0;
}