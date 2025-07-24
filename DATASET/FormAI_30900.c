//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

void displayInstructions();
void displayBoard(char board[][BOARD_SIZE], int missesLeft, int hitsLeft);
void getRandomPosition(int shipLength, int *x, int *y, int *direction);
void initializeBoard(char board[][BOARD_SIZE], int shipLengths[]);
int isGameOver(char board[][BOARD_SIZE]);

int main() {

    srand(time(NULL)); // seed the random method used by getRandomPosition()
    char board[BOARD_SIZE][BOARD_SIZE];
    int shipLengths[4] = { 2, 3, 4, 5 }; // length of each ship in descending order
    int missesLeft = 25;
    int hitsLeft = 17;
    int totalHits = 0;

    displayInstructions();
    initializeBoard(board, shipLengths);

    while (!isGameOver(board) && missesLeft > 0 && hitsLeft > 0) {
        displayBoard(board, missesLeft, hitsLeft);
        int x, y, direction;
        printf("\nEnter co-ordinates to fire (row,col): ");
        scanf("%d,%d", &x, &y);

        if (board[x][y] != '-' && board[x][y] != 'X') {
            printf("\nAlready hit at these coordinates, try again.\n");
            continue;
        }

        if (board[x][y] == '-') { // missed
            printf("\nYou missed!\n");
            board[x][y] = 'O'; // mark as missed shot
            --missesLeft;
        } else { // hit
            printf("\nYou hit a ship!\n");
            int shipLength = board[x][y] - '0';
            board[x][y] = 'X'; // mark as hit
            ++totalHits;
            --hitsLeft;

            if (totalHits >= shipLengths[shipLengths[0] - 2]) {
                --shipLengths[0];
                printf("\nShip of length %d destroyed!\n", shipLength);
                if (hitsLeft == 0) {
                    printf("\nCongratulations, you won!\n");
                }
            }
        }
    }

    if (totalHits < 17) {
        printf("\nSorry, you lost.\n");
    }

    return 0;
}

void displayInstructions() {
    printf("Welcome to Battleship!\n");
    printf("You have 25 missiles to fire to sink 4 ships of lengths: 2, 3, 4 and 5.\n");
    printf("Ships can be positioned horizontally or vertically.\n");
    printf("For example, a ship of length 4 could be positioned at (1,3) to (4,3) or at (5,5) to (5,8).\n");
    printf("Coordinates of the board are numbered from 0 to 9.\n");
    printf("A '-' indicates an empty spot, 'X' indicates a hit and 'O' indicates a miss.\n");
}

void displayBoard(char board[][BOARD_SIZE], int missesLeft, int hitsLeft) {

    system("clear"); // for unix-based systems only, change to "cls" for Windows

    printf("\nMisses left: %d, Hits left: %d\n\n", missesLeft, hitsLeft);
    printf("  ");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }

    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void getRandomPosition(int shipLength, int *x, int *y, int *direction) {

    *direction = rand() % 2; // 0 for horizontal, 1 for vertical
    *x = rand() % BOARD_SIZE;
    *y = rand() % BOARD_SIZE;

    if (*direction == 0) { // horizontal
        while (*y + shipLength >= BOARD_SIZE) {
            *y = rand() % BOARD_SIZE;
        }
    } else { // vertical
        while (*x + shipLength >= BOARD_SIZE) {
            *x = rand() % BOARD_SIZE;
        }
    }
}

void initializeBoard(char board[][BOARD_SIZE], int shipLengths[]) {

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    for (int i = 0; i < 4; i++) { // for each ship
        for (int j = 0; j < i + 1; j++) { // for each ship of same length
            int x, y, direction;
            int shipLength = shipLengths[i];
            getRandomPosition(shipLength, &x, &y, &direction);

            for (int k = 0; k < shipLength; k++) {
                if (direction == 0) { // horizontal
                    board[x][y+k] = shipLength + '0'; // store as char for easier detection of hits
                } else { // vertical
                    board[x+k][y] = shipLength + '0';
                }
            }
        }
    }
}

int isGameOver(char board[][BOARD_SIZE]) {

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] >= '2' && board[i][j] <= '5') { // there is still an unsunk ship
                return 0;
            }
        }
    }

    return 1;
}