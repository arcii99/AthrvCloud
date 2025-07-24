//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4

// Function to print the array
void printArray(int arr[][COL], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the game board with random numbers
void initBoard(int board[][COL], int row) {
    int num_of_pairs = (row * COL) / 2;  // number of pairs of numbers we need
    int current_num = 1;  // we will start with 1

    srand(time(NULL));  // seed the random number generator with current time

    // Initialize the board with 0's first
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = 0;
        }
    }

    // Set the pairs of random numbers on the board
    for (int i = 0; i < num_of_pairs; i++) {
        int pair_count = 0;
        while (pair_count < 2) {
            int x = rand() % row;  // get a random row index
            int y = rand() % COL;  // get a random column index

            // If the current cell is already filled with a number, skip it
            if (board[x][y] != 0) {
                continue;
            }

            board[x][y] = current_num;  // assign the current number to the current cell
            pair_count++;  // increment the pair count
        }

        current_num++;  // increment the current number
    }
}

// Function to check if the game is over
int isGameOver(int board[][COL], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == 0) {  // if there's still an empty cell
                return 0;  // the game is not over yet
            }
        }
    }

    return 1;  // all cells are filled, so the game is over
}

int main() {
    int board[ROW][COL];  // declare the game board array
    int x1, x2, y1, y2;  // variables to hold user input coordinates

    initBoard(board, ROW);  // initialize the game board with random numbers
    printArray(board, ROW);  // print the initial game board

    while (!isGameOver(board, ROW)) {
        printf("Enter the coordinates of the first cell: ");
        scanf("%d %d", &x1, &y1);

        // If the choice is invalid or if the cell is already revealed, prompt for new input
        while (x1 < 0 || x1 >= ROW || y1 < 0 || y1 >= COL || board[x1][y1] == -1) {
            printf("Invalid choice, try again.\n");
            printf("Enter the coordinates of the first cell: ");
            scanf("%d %d", &x1, &y1);
        }

        board[x1][y1] = -1;  // mark the cell as revealed with -1
        printArray(board, ROW);  // print the updated game board

        printf("Enter the coordinates of the second cell: ");
        scanf("%d %d", &x2, &y2);

        // If the choice is invalid or if the cell is already revealed, prompt for new input
        while (x2 < 0 || x2 >= ROW || y2 < 0 || y2 >= COL || board[x2][y2] == -1) {
            printf("Invalid choice, try again.\n");
            printf("Enter the coordinates of the second cell: ");
            scanf("%d %d", &x2, &y2);
        }

        board[x2][y2] = -1;  // mark the cell as revealed with -1
        printArray(board, ROW);  // print the updated game board

        if (board[x1][y1] == board[x2][y2]) {  // if the cells are a match
            printf("You found a match!\n");
            board[x1][y1] = board[x2][y2] = -2;  // mark the cells as matched with -2
        } else {
            printf("Sorry, try again.\n");
            board[x1][y1] = board[x2][y2] = 0;  // reset the cells to their initial state
        }
    }

    printf("Congratulations, you won!\n");

    return 0;
}