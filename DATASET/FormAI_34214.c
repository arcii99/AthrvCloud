//FormAI DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[4][4] = {0};
    int score = 0;
    srand(time(NULL));

    printf("\n\n\t\tWelcome to C Table Game!\n\n");
    printf("\t- Move the numbers in the board to join them\n");
    printf("\t- The game ends when the board is full or no more possible move\n\n");
    printf("\t\t Press any key to start...\n");
    getchar();

    printf("\033c");
    while (1) {
        int empty = 0;  // number of empty cell
        int move = 0;  // check if there is any possible move

        // loop through the board and check for empty cell and possible move
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == 0) {
                    empty++;
                }
                if (i <= 2 && board[i][j] == board[i+1][j]) {
                    move = 1;
                }
                if (j <= 2 && board[i][j] == board[i][j+1]) {
                    move = 1;
                }
            }
        }

        // if the board is full or no more possible move, end the game
        if (empty == 0 || move == 0) {
            printf("GAME OVER\n");
            printf("Score: %d\n", score);
            break;
        }

        // else continue the game
        // generate a random position for a new number
        int x, y;
        do {
            x = rand() % 4;
            y = rand() % 4;
        } while (board[x][y] != 0);

        // generate a random number for the new position
        int num = rand() % 2 + 1;
        board[x][y] = num * 2;

        // print the board and the score
        printf("\033c");
        printf("\n");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("\t%4d", board[i][j]);
            }
            printf("\n\n");
        }
        printf("Score: %d\n", score);

        // get user input for direction
        char dir[10];
        printf("Enter direction (up, down, left, right): ");
        scanf("%s", dir);

        int moved = 0;  // check if there was any move

        // move the numbers in the board according to the direction
        // and add the same numbers together
        if (strcmp(dir, "up") == 0) {
            for (int j = 0; j < 4; j++) {
                int temp[4] = {0};
                int k = 0;
                for (int i = 0; i < 4; i++) {
                    if (board[i][j] != 0) {
                        temp[k] = board[i][j];
                        k++;
                    }
                }
                for (int i = 0; i < 3; i++) {
                    if (temp[i] == temp[i+1]) {
                        temp[i] *= 2;
                        score += temp[i];
                        temp[i+1] = 0;
                        moved = 1;
                    }
                }
                k = 0;
                for (int i = 0; i < 4; i++) {
                    board[i][j] = temp[k];
                    k++;
                }
            }
        } else if (strcmp(dir, "down") == 0) {
            for (int j = 0; j < 4; j++) {
                int temp[4] = {0};
                int k = 0;
                for (int i = 3; i >= 0; i--) {
                    if (board[i][j] != 0) {
                        temp[k] = board[i][j];
                        k++;
                    }
                }
                for (int i = 3; i > 0; i--) {
                    if (temp[i] == temp[i-1]) {
                        temp[i] *= 2;
                        score += temp[i];
                        temp[i-1] = 0;
                        moved = 1;
                    }
                }
                k = 0;
                for (int i = 3; i >= 0; i--) {
                    board[i][j] = temp[k];
                    k++;
                }
            }
        } else if (strcmp(dir, "left") == 0) {
            for (int i = 0; i < 4; i++) {
                int temp[4] = {0};
                int k = 0;
                for (int j = 0; j < 4; j++) {
                    if (board[i][j] != 0) {
                        temp[k] = board[i][j];
                        k++;
                    }
                }
                for (int j = 0; j < 3; j++) {
                    if (temp[j] == temp[j+1]) {
                        temp[j] *= 2;
                        score += temp[j];
                        temp[j+1] = 0;
                        moved = 1;
                    }
                }
                k = 0;
                for (int j = 0; j < 4; j++) {
                    board[i][j] = temp[k];
                    k++;
                }
            }
        } else if (strcmp(dir, "right") == 0) {
            for (int i = 0; i < 4; i++) {
                int temp[4] = {0};
                int k = 0;
                for (int j = 3; j >= 0; j--) {
                    if (board[i][j] != 0) {
                        temp[k] = board[i][j];
                        k++;
                    }
                }
                for (int j = 3; j > 0; j--) {
                    if (temp[j] == temp[j-1]) {
                        temp[j] *= 2;
                        score += temp[j];
                        temp[j-1] = 0;
                        moved = 1;
                    }
                }
                k = 0;
                for (int j = 3; j >= 0; j--) {
                    board[i][j] = temp[k];
                    k++;
                }
            }
        }

        // if there was no move in the chosen direction, ask the user to choose again
        if (moved == 0) {
            printf("Invalid move, try again.\n");
            getchar();
            continue;
        }

    }

    return 0;
}