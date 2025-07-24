//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void clearScreen();
void printTiles(int tiles[]);
void swap(int tiles[], int a, int b);
int checkWin(int tiles[]);

int main() {

    // seed the random number generator
    srand(time(NULL));

    // initialize the game board (tiles 1-15 in random order,
    // with the empty space represented by 0)
    int tiles[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    for (int i = 0; i < 1000; i++) {
        swap(tiles, rand() % 16, rand() % 16);
    }

    // print the initial game board
    clearScreen();
    printTiles(tiles);

    // repeat until the game is won
    while (!checkWin(tiles)) {

        // get user input
        char c = getchar();

        // find the empty space
        int emptyIndex = 0;
        while (emptyIndex < 16 && tiles[emptyIndex] != 0) {
            emptyIndex++;
        }

        // process the input
        switch (c) {
            case 'w': // move up
                if (emptyIndex / 4 < 3) {
                    swap(tiles, emptyIndex, emptyIndex + 4);
                }
                break;
            case 'a': // move left
                if (emptyIndex % 4 < 3) {
                    swap(tiles, emptyIndex, emptyIndex + 1);
                }
                break;
            case 's': // move down
                if (emptyIndex / 4 > 0) {
                    swap(tiles, emptyIndex, emptyIndex - 4);
                }
                break;
            case 'd': // move right
                if (emptyIndex % 4 > 0) {
                    swap(tiles, emptyIndex, emptyIndex - 1);
                }
                break;
            case 'q': // quit the game
                printf("Quitting game...\n");
                exit(0);
            default: // invalid input
                printf("Invalid input. Use 'w', 'a', 's', 'd' to move or 'q' to quit.\n");
                break;
        }

        // reprint the game board
        clearScreen();
        printTiles(tiles);
    }

    // end of game message
    printf("Congratulations, you won the game!\n");

    return 0;
}

// function definitions

// clears the terminal screen
void clearScreen() {
    printf("\033[2J\033[1;1H");
}

// prints the current game board
void printTiles(int tiles[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", tiles[i * 4 + j]);
        }
        printf("\n");
    }
}

// swaps two tiles on the game board
void swap(int tiles[], int a, int b) {
    int temp = tiles[a];
    tiles[a] = tiles[b];
    tiles[b] = temp;
}

// checks if the game has been won
int checkWin(int tiles[]) {
    for (int i = 0; i < 15; i++) {
        if (tiles[i] != i + 1) {
            return 0;
        }
    }
    return 1;
}