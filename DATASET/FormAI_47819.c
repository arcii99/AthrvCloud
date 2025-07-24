//FormAI DATASET v1.0 Category: Memory Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

void generateBoard(int* board) {
    // Set values from 1 to 8 in random positions
    int values[8];
    for(int i = 0; i < 8; i++) {
        values[i] = i + 1;
    }
    srand(time(NULL));
    for(int i = 0; i < 8; i++) {
        int pos = rand() % BOARD_SIZE;
        while(board[pos] != 0) {
            pos = rand() % BOARD_SIZE;
        }
        board[pos] = values[i];
    }
    // Create matching pairs
    for(int value = 1; value <= 8; value++) {
        int pos1 = -1, pos2 = -1;
        while(pos1 == -1 || pos2 == -1) {
            int pos = rand() % BOARD_SIZE;
            if(board[pos] == value && pos != pos1) {
                if(pos1 == -1)
                    pos1 = pos;
                else
                    pos2 = pos;
            }
        }
        board[pos1] = -value;
        board[pos2] = -value;
    }
}

void printBoard(int* board, int* flipped) {
    printf(" ");
    for(int i = 0; i < 4; i++)
        printf("   %d", i+1);
    printf("\n");
    printf("  -----------------\n");
    for(int i = 0; i < 4; i++) {
        printf("%c |", 'A' + i);
        for(int j = 0; j < 4; j++) {
            if(flipped[i*4+j])
                printf(" %2d ", board[i*4+j]);
            else
                printf("  X ");
        }
        printf("|\n");
    }
    printf("  -----------------\n");
}

void clearScreen() {
    #ifdef _WIN32 // Windows
        system("cls");
    #else // Mac and Linux
        system("clear");
    #endif
}

int main() {
    int board[BOARD_SIZE] = {0}, flipped[BOARD_SIZE] = {0};
    generateBoard(board);

    int moves = 0;
    while(1) {
        clearScreen();
        printf("Moves: %d\n", moves);
        printBoard(board, flipped);
        fflush(stdout);

        // Detect game over
        int won = 1;
        for(int i = 0; i < BOARD_SIZE; i++) {
            if(board[i] > 0 && !flipped[i]) {
                won = 0;
                break;
            }
        }
        if(won) {
            printf("Congratulations! You won in %d moves.\n", moves);
            return 0;
        }

        // Get input
        int row, col;
        printf("Enter row and column (e.g. A1): ");
        fflush(stdout);
        scanf(" %c%d", &row, &col);
        row -= 'A';
        col--;
        if(row < 0 || row > 3 || col < 0 || col > 3) {
            printf("Invalid input.\n");
            continue;
        }
        int pos = row*4 + col;
        if(flipped[pos]) {
            printf("Already flipped.\n");
            continue;
        }

        // Check match
        if(flipped[pos] = (board[pos] < 0)) {
            moves++;
            continue;
        }

        // Flip card
        flipped[pos] = 1;
        printBoard(board, flipped);
        fflush(stdout);

        // Get second input
        printf("Enter second row and column (e.g. B2): ");
        fflush(stdout);
        scanf(" %c%d", &row, &col);
        row -= 'A';
        col--;
        if(row < 0 || row > 3 || col < 0 || col > 3) {
            printf("Invalid input.\n");
            continue;
        }
        int pos2 = row*4 + col;
        if(flipped[pos2]) {
            printf("Already flipped.\n");
            continue;
        }

        // Check match
        moves++;
        if(flipped[pos2] = (board[pos] == board[pos2]))
            continue;

        // Not a match, flip cards back
        flipped[pos] = 0;
        flipped[pos2] = 0;
    }
    return 0;
}