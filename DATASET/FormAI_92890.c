//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 15

// Function to draw the game board
void draw(char board[][WIDTH], int score)
{
    printf("\nScore: %d\n\n", score);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to update the game board
void update(char board[][WIDTH], int px, int py, int* score)
{
    if (board[py][px] == '.') {
        (*score)++;
    }
    board[py][px] = 'P';
}

// Function to check if the game is over
int is_gameover(char board[][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    char board[HEIGHT][WIDTH];

    // Initialize the board with dots and walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                board[i][j] = '#';
            } else {
                board[i][j] = '.';
            }
        }
    }

    // Add the Pac-Man and the Ghosts to the board
    board[1][1] = 'P';
    board[1][WIDTH - 2] = 'G';
    board[HEIGHT - 2][1] = 'G';
    board[HEIGHT - 2][WIDTH - 2] = 'G';

    // Set the initial position of Pac-Man and the Ghosts
    int px = 1, py = 1;
    int gx1 = 1, gy1 = HEIGHT - 2;
    int gx2 = WIDTH - 2, gy2 = 1;
    int gx3 = WIDTH - 2, gy3 = HEIGHT - 2;

    // Set the initial score
    int score = 0;

    // Loop until the game is over
    while (!is_gameover(board)) {
        // Draw the board
        draw(board, score);

        // Get the user input
        char input;
        printf("\nUse arrow keys to move Pac-Man: ");
        scanf(" %c", &input);

        // Move Pac-Man based on the user input
        switch (input) {
            case 'A':
            case 'a':
                if (board[py][px - 1] != '#') {
                    board[py][px] = '.';
                    px--;
                    update(board, px, py, &score);
                }
                break;
            case 'D':
            case 'd':
                if (board[py][px + 1] != '#') {
                    board[py][px] = '.';
                    px++;
                    update(board, px, py, &score);
                }
                break;
            case 'W':
            case 'w':
                if (board[py - 1][px] != '#') {
                    board[py][px] = '.';
                    py--;
                    update(board, px, py, &score);
                }
                break;
            case 'S':
            case 's':
                if (board[py + 1][px] != '#') {
                    board[py][px] = '.';
                    py++;
                    update(board, px, py, &score);
                }
                break;
        }

        // Move the Ghosts randomly
        srand(time(NULL));
        int distance1 = abs(gx1 - px) + abs(gy1 - py);
        int direction1 = rand() % 4;
        if (direction1 == 0 && board[gy1 - 1][gx1] != '#') {
            if (abs(gx1 - px) + abs(gy1 - 1 - py) < distance1) {
                board[gy1][gx1] = '.';
                gy1--;
            }
        } else if (direction1 == 1 && board[gy1 + 1][gx1] != '#') {
            if (abs(gx1 - px) + abs(gy1 + 1 - py) < distance1) {
                board[gy1][gx1] = '.';
                gy1++;
            }
        } else if (direction1 == 2 && board[gy1][gx1 - 1] != '#') {
            if (abs(gx1 - 1 - px) + abs(gy1 - py) < distance1) {
                board[gy1][gx1] = '.';
                gx1--;
            }
        } else if (direction1 == 3 && board[gy1][gx1 + 1] != '#') {
            if (abs(gx1 + 1 - px) + abs(gy1 - py) < distance1) {
                board[gy1][gx1] = '.';
                gx1++;
            }
        }
        board[gy1][gx1] = 'G';

        int distance2 = abs(gx2 - px) + abs(gy2 - py);
        int direction2 = rand() % 4;
        if (direction2 == 0 && board[gy2 - 1][gx2] != '#') {
            if (abs(gx2 - px) + abs(gy2 - 1 - py) < distance2) {
                board[gy2][gx2] = '.';
                gy2--;
            }
        } else if (direction2 == 1 && board[gy2 + 1][gx2] != '#') {
            if (abs(gx2 - px) + abs(gy2 + 1 - py) < distance2) {
                board[gy2][gx2] = '.';
                gy2++;
            }
        } else if (direction2 == 2 && board[gy2][gx2 - 1] != '#') {
            if (abs(gx2 - 1 - px) + abs(gy2 - py) < distance2) {
                board[gy2][gx2] = '.';
                gx2--;
            }
        } else if (direction2 == 3 && board[gy2][gx2 + 1] != '#') {
            if (abs(gx2 + 1 - px) + abs(gy2 - py) < distance2) {
                board[gy2][gx2] = '.';
                gx2++;
            }
        }
        board[gy2][gx2] = 'G';

        int distance3 = abs(gx3 - px) + abs(gy3 - py);
        int direction3 = rand() % 4;
        if (direction3 == 0 && board[gy3 - 1][gx3] != '#') {
            if (abs(gx3 - px) + abs(gy3 - 1 - py) < distance3) {
                board[gy3][gx3] = '.';
                gy3--;
            }
        } else if (direction3 == 1 && board[gy3 + 1][gx3] != '#') {
            if (abs(gx3 - px) + abs(gy3 + 1 - py) < distance3) {
                board[gy3][gx3] = '.';
                gy3++;
            }
        } else if (direction3 == 2 && board[gy3][gx3 - 1] != '#') {
            if (abs(gx3 - 1 - px) + abs(gy3 - py) < distance3) {
                board[gy3][gx3] = '.';
                gx3--;
            }
        } else if (direction3 == 3 && board[gy3][gx3 + 1] != '#') {
            if (abs(gx3 + 1 - px) + abs(gy3 - py) < distance3) {
                board[gy3][gx3] = '.';
                gx3++;
            }
        }
        board[gy3][gx3] = 'G';
    }

    // Game over
    draw(board, score);
    printf("\n\nGame over!\n\nFinal score: %d\n", score);

    return 0;
}