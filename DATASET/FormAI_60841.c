//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_board(int board[ROWS][COLS], int show_ships) {
    printf("\n\n");
    printf("   "); 
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i+1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%c |", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0 || (board[i][j] == 1 && show_ships)) {
                printf("  ");
            } else if (board[i][j] == 1 && !show_ships) {
                printf(". ");
            } else if (board[i][j] == 2) {
                printf("X ");
            }
        }
        printf("\n");
    }
}

int valid_coordinate(int x, int y) {
    if (x >= ROWS || x < 0 || y >= COLS || y < 0) {
        printf("Invalid coordinate.\n");
        return 0;
    }
    return 1;
}

int main() {
    int board[ROWS][COLS] = {0};
    int ship_count = 0;
    srand(time(NULL));

    while (ship_count < 10) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        if (board[x][y] == 0) {
            board[x][y] = 1;
            ship_count++;
        }
    }
  
    printf("Welcome to Battleship game!\n");
    printf("You have 20 chances to sink all 10 ships.\n");
  
    int guesses = 0;
    while (guesses < 20) {
        print_board(board, 0);
      
        int x, y;
        printf("\nGuess a coordinate: ");
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if (!valid_coordinate(x, y)) continue;
        if (board[x][y] == 1) {
            printf("Hit!\n");
            board[x][y] = 2;
        } else {
            printf("Miss.\n");
        }
        guesses++;
      
        int sunk = 1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 1) {
                    sunk = 0;
                }
            }
        }
        if (sunk) {
            printf("Congratulations! You sunk all the ships!\n");
            break;
        }
    }
    
    printf("Game over!\n");
    print_board(board, 1);
    
    return 0;
}