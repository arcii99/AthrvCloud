//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

#define ROW 20 // row number of game area
#define COL 50 // column number of game area

int getch() { // function that gets character input without echoing to console
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

void clear() { // function that clears the console screen
    printf("\033[H\033[J");
}

void init_game(char game_area[ROW][COL]) { // initializing the game area
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            game_area[i][j] = ' ';
        }
    }
}

void draw_game_area(char game_area[ROW][COL]) { // drawing the game area
    clear();
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            printf("%c", game_area[i][j]);
        }
        printf("\n");
    }
}

void draw_paddle(char game_area[ROW][COL], int x_paddle) { // drawing the paddle in the game area
    for (int i=ROW-1; i>=ROW-2; i--) {
        for (int j=x_paddle-3; j<=x_paddle+3; j++) {
            game_area[i][j] = '=';
        }
    }
}

void draw_ball(char game_area[ROW][COL], int x_ball, int y_ball) { // drawing the ball in the game area
    game_area[y_ball][x_ball] = 'O';
}

void update_ball(char game_area[ROW][COL], int *x_ball, int *y_ball, int *vx, int *vy) { // updating the ball's position
    *x_ball += *vx;
    *y_ball += *vy;
    if (*x_ball == 0 || *x_ball == COL-1) {
        *vx *= -1;
    }
    if (*y_ball == 0) {
        *vy *= -1;
    }
    if (*y_ball == ROW-1) {
        clear();
        printf("Game Over!\n");
        exit(0);
    }
    if (game_area[*y_ball][*x_ball] == '=') {
        *vy *= -1;
    }
    game_area[*y_ball - *vy][*x_ball - *vx] = ' ';
}

int main() {
    int x_paddle = COL/2; // starting position of the paddle
    int x_ball = x_paddle; // starting position of the ball
    int y_ball = ROW-3; // starting position of the ball
    int vx = 1; // velocity of the ball in x direction
    int vy = -1; // velocity of the ball in y direction
    char game_area[ROW][COL]; // array that stores the game area
    init_game(game_area); // initializing the game area

    while (1) { // game loop
        if (getch() == 'a' && x_paddle > 5) {
            x_paddle--;
        }
        if (getch() == 'd' && x_paddle < COL-6) {
            x_paddle++;
        }
        update_ball(game_area, &x_ball, &y_ball, &vx, &vy); // update the position of the ball
        draw_game_area(game_area); // draw the game area
        draw_paddle(game_area, x_paddle); // draw the paddle
        draw_ball(game_area, x_ball, y_ball); // draw the ball
        usleep(50000); // delay for smoother animation
    }

    return 0;
}