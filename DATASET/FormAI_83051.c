//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define BLOCK '%'
#define PADDLE '='
#define BALL 'O'

void display(char screen[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

int find_paddle(char screen[HEIGHT][WIDTH], int row) {
    for (int i = 0; i < WIDTH; i++) {
        if (screen[row][i] == PADDLE) {
            return i;
        }
    }
    return -1;
}

int hit_brick(char screen[HEIGHT][WIDTH], int row, int col) {
    if (row < 0 || row >= HEIGHT || col < 0 || col >= WIDTH) {
        return 0;
    }
    if (screen[row][col] == BLOCK) {
        screen[row][col] = ' ';
        return 1 + hit_brick(screen, row-1, col) + hit_brick(screen, row+1, col) +
                   hit_brick(screen, row, col-1) + hit_brick(screen, row, col+1);
    }
    return 0;
}

int move_ball(char screen[HEIGHT][WIDTH], int row, int col, int dx, int dy) {
    if (row == HEIGHT-1) {
        return 0;
    }
    if (row == 0 || screen[row+1][col] == BLOCK) {
        int bricks = hit_brick(screen, row+1, col);
        screen[row][col] = ' ';
        if (bricks > 0) {
            return move_ball(screen, row-dy, col+dx, dx, dy);
        }
        return 0;
    }
    screen[row][col] = ' ';
    screen[row+dy][col+dx] = BALL;
    if (screen[row+dy][col+dx] == PADDLE && dy == 1) {
        return -1;
    }
    return move_ball(screen, row+dy, col+dx, dx, dy);
}

int main() {
    char screen[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
    for (int i = 0; i < WIDTH; i++) {
        screen[0][i] = BLOCK;
    }
    screen[HEIGHT-1][WIDTH/2] = PADDLE;
    screen[HEIGHT-2][WIDTH/2] = BALL;
    srand(time(NULL));
    int dx = rand()%2==0 ? -1 : 1;
    int dy = -1;
    int score = 0;
    while (1) {
        display(screen);
        int dir;
        scanf("%d", &dir);
        int paddle = find_paddle(screen, HEIGHT-1);
        screen[HEIGHT-1][paddle] = ' ';
        if (dir == -1 && paddle > 0) {
            paddle--;
        }
        else if (dir == 1 && paddle < WIDTH-1) {
            paddle++;
        }
        screen[HEIGHT-1][paddle] = PADDLE;
        int result = move_ball(screen, HEIGHT-2, WIDTH/2, dx, dy);
        if (result == -1) {
            dy = -dy;
        }
        else if (result > 0) {
            score += result;
        }
        if (score == WIDTH*(HEIGHT-2)) {
            printf("You win!\n");
            break;
        }
        dx = rand()%2==0 ? -1 : 1;
    }
    return 0;
}