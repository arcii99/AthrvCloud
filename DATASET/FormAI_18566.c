//FormAI DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Global variables
const int BOARD_SIZE = 4;
int board[4][4];

// Function to print the board
void printBoard() {
    printf("\n");
    for(int i=0; i< BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to generate the board
void generateBoard() {
    int numPairs = (BOARD_SIZE * BOARD_SIZE) / 2;
    int randomNums[numPairs];

    // Generate random numbers for the pairs
    for(int i=0; i<numPairs; i++) {
        randomNums[i] = rand() % 100;
    }
    
    // Place pairs randomly on the board
    for(int numIdx=0; numIdx<numPairs; numIdx++) {
        for(int pairIdx=0; pairIdx<2; pairIdx++) {
            int posx, posy;
            do {
                posx = rand() % BOARD_SIZE;
                posy = rand() % BOARD_SIZE;
            } while(board[posx][posy] != 0);
            board[posx][posy] = randomNums[numIdx];
        }
    }
}

// Function to check if the game is over
int gameOver() {
    for(int i=0; i< BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    printf("Let's play a Memory Game!\n");
    
    generateBoard();
    printBoard();

    while(!gameOver()) {
        printf("\nEnter the x and y positions of the first card you want to flip separated by a space: ");
        int x1, y1;
        scanf("%d %d", &x1, &y1);
        
        printf("Enter the x and y positions of the second card you want to flip separated by a space: ");
        int x2, y2;
        scanf("%d %d", &x2, &y2);

        // Check if the cards match
        if(board[x1-1][y1-1] == board[x2-1][y2-1]) {
            board[x1-1][y1-1] = -1;
            board[x2-1][y2-1] = -1;
            printf("Match!\n");
        } else {
            printf("Not a match.\n");
        }

        printBoard();
    }
    
    printf("Game over! Thanks for playing!");
    return 0;
}