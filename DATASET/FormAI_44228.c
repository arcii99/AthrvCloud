//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

void display(char arr[][COLS], int rows, int cols);
void shuffle(char arr[][COLS], int rows, int cols);
int checkWin(char arr[][COLS], int rows, int cols);

int main() {
    char gameBoard[ROWS][COLS] = { {'1', '2', '3', '4', '5'},
                                   {'6', '7', '8', '9', 'A'},
                                   {'B', 'C', 'D', 'E', 'F'},
                                   {'G', 'H', 'I', 'J', 'K'},
                                   {'L', 'M', 'N', 'O', ' '} }; // Initialize game board
    
    int moves = 0;
    int row = ROWS - 1, col = COLS - 1; // Position of empty space

    shuffle(gameBoard, ROWS, COLS); // Shuffle game board
    display(gameBoard, ROWS, COLS); // Display game board

    while (1) { // Keep playing until win condition met
        char input = ' ';
        printf("\nEnter move (W/A/S/D): ");
        scanf(" %c", &input);

        int newRow = row, newCol = col; // Possible new position of empty space
        switch (input) { // Change new position based on input
            case 'W': newRow--; break;
            case 'A': newCol--; break;
            case 'S': newRow++; break;
            case 'D': newCol++; break;
            default: printf("Invalid move.\n"); continue; // Invalid input
        }

        if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS) { // Out of bounds
            printf("Out of bounds.\n");
            continue;
        }

        // Swap positions of empty space and selected piece
        gameBoard[row][col] = gameBoard[newRow][newCol];
        gameBoard[newRow][newCol] = ' ';
        row = newRow;
        col = newCol;
        moves++;

        display(gameBoard, ROWS, COLS); // Display updated game board
        if (checkWin(gameBoard, ROWS, COLS)) { // Check for win condition
            printf("You win!\n");
            printf("Total moves: %d\n", moves);
            break;
        }
    }
    return 0;
}

void display(char arr[][COLS], int rows, int cols) {
    system("clear"); // Clear terminal window
    printf("Moves: W/A/S/D\n\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("|%c", arr[i][j]);
        }
        printf("|\n"); // End row with a border
    }
}

void shuffle(char arr[][COLS], int rows, int cols) {
    srand(time(NULL)); // Seed random number generator with current time
    for (int i = rows * cols - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Generate random index to swap with
        int temp = arr[i / cols][i % cols];
        arr[i / cols][i % cols] = arr[j / cols][j % cols];
        arr[j / cols][j % cols] = temp;
    }
}

int checkWin(char arr[][COLS], int rows, int cols) {
    int currVal = '1';
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] != currVal && !(i == rows - 1 && j == cols - 1))
                return 0; // Game board not in order
            currVal++;
        }
    }
    return 1; // Game board in order
}