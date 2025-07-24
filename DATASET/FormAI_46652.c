//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 10

enum Player {
    PLAYER_1,
    PLAYER_2,
};

/** board data structure to keep track of player moves **/
typedef struct Board {
    enum Player data[BOARD_SIZE][BOARD_SIZE];
} Board;

/** helper function to clear the console **/
void clear() {
    printf("\e[1;1H\e[2J");
}

/** helper function to draw the board **/
void drawBoard(Board board) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board.data[i][j]) {
                case PLAYER_1:
                    printf("X ");
                    break;
                case PLAYER_2:
                    printf("O ");
                    break;
                default:
                    printf(". ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

/** helper function to check if the given point is in bounds **/
bool isInBounds(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

/** helper function to check if a player has won **/
bool hasWon(Board board, enum Player player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // check horizontal
            if (board.data[i][j] == player && isInBounds(i, j + 1) && isInBounds(i, j + 2) && isInBounds(i, j + 3)
                && board.data[i][j + 1] == player && board.data[i][j + 2] == player && board.data[i][j + 3] == player) {
                return true;
            }

            // check vertical
            if (board.data[i][j] == player && isInBounds(i + 1, j) && isInBounds(i + 2, j) && isInBounds(i + 3, j)
                && board.data[i + 1][j] == player && board.data[i + 2][j] == player && board.data[i + 3][j] == player) {
                return true;
            }

            // check diagonal top-left to bottom-right
            if (board.data[i][j] == player && isInBounds(i + 1, j + 1) && isInBounds(i + 2, j + 2) && isInBounds(i + 3, j + 3)
                && board.data[i + 1][j + 1] == player && board.data[i + 2][j + 2] == player && board.data[i + 3][j + 3] == player) {
                return true;
            }

            // check diagonal bottom-left to top-right
            if (board.data[i][j] == player && isInBounds(i - 1, j + 1) && isInBounds(i - 2, j + 2) && isInBounds(i - 3, j + 3)
                && board.data[i - 1][j + 1] == player && board.data[i - 2][j + 2] == player && board.data[i - 3][j + 3] == player) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    Board board;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board.data[i][j] = -1;
        }
    }

    enum Player currentPlayer = PLAYER_1;
    while (!hasWon(board, currentPlayer)) {
        clear();
        drawBoard(board);

        int x;
        int y;
        printf("Player %d's turn\n", currentPlayer + 1);
        printf("Enter x coordinate: ");
        scanf("%d", &x);
        printf("\nEnter y coordinate: ");
        scanf("%d", &y);

        if (!isInBounds(x, y)) {
            printf("\nInvalid move! Please choose a valid position.\n");
            continue;
        }

        if (board.data[x][y] != -1) {
            printf("\nInvalid move! That position is already taken.\n");
            continue;
        }
    
        board.data[x][y] = currentPlayer;
        currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
    }

    drawBoard(board);
    printf("Player %d has won!", (currentPlayer == PLAYER_1) ? 2 : 1);

    return 0;
}