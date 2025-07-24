//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 20
#define HEIGHT 20
#define MAX_COINS 100

int board[HEIGHT][WIDTH];
int coins[MAX_COINS][2]; // stores x,y coordinates of coins
int pac_x, pac_y;
int score = 0;

void setup() {
    srand(time(NULL));
    // initialize board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1) {
                board[i][j] = 1; // border
            } else {
                board[i][j] = 0; // empty space
            }
        }
    }
    // add coins
    for (int i = 0; i < MAX_COINS; i++) {
        int x = rand() % (WIDTH-2) + 1;
        int y = rand() % (HEIGHT-2) + 1;
        coins[i][0] = x;
        coins[i][1] = y;
        board[y][x] = 2; // coin
    }
    // add pacman
    pac_x = WIDTH / 2;
    pac_y = HEIGHT / 2;
    board[pac_y][pac_x] = 3; // pacman
}

void draw() {
    // clear screen
    system("clear");
    // draw board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            switch(board[i][j]) {
                case 0: // empty space
                    printf(". ");
                    break;
                case 1: // border
                    printf("# ");
                    break;
                case 2: // coin
                    printf("o ");
                    break;
                case 3: // pacman
                    printf("C ");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
    // print score
    printf("Score: %d\n", score);
}

void move_pacman(char direction) {
    int dx = 0, dy = 0;
    switch(direction) {
        case 'w':
            dy = -1; // move up
            break;
        case 's':
            dy = 1; // move down
            break;
        case 'a':
            dx = -1; // move left
            break;
        case 'd':
            dx = 1; // move right
            break;
        default:
            break;
    }
    // check if move is valid
    if (board[pac_y+dy][pac_x+dx] != 1) {
        // update board
        board[pac_y][pac_x] = 0;
        pac_x += dx;
        pac_y += dy;
        if (board[pac_y][pac_x] == 2) { // coin
            board[pac_y][pac_x] = 3; // pacman
            score += 10;
            for (int i = 0; i < MAX_COINS; i++) { // remove coin from coins array
                if (coins[i][0] == pac_x && coins[i][1] == pac_y) {
                    coins[i][0] = -1;
                    coins[i][1] = -1;
                    break;
                }
            }
        } else { // empty space
            board[pac_y][pac_x] = 3; // pacman
        }
    }
}

int main() {
    setup();
    draw();
    char input;
    while (score < MAX_COINS * 10) {
        printf("Enter direction (w,a,s,d): ");
        scanf(" %c", &input);
        move_pacman(input);
        draw();
    }
    // game over
    printf("Game over! Final score: %d\n", score);
    return 0;
}