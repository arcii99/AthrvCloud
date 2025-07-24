//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int bricks[ROWS][COLS];
int x_pos, y_pos, xdir, ydir;

void init_bricks() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            bricks[i][j] = rand()%2; // randomly decide if brick is present or not
        }
    }
}

void init_ball() {
    x_pos = ROWS/2;
    y_pos = COLS/2;
    xdir = 1;
    ydir = 1;
}

void draw_bricks() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(bricks[i][j]) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void draw_ball() {
    printf("@");
    for(int i=0; i<y_pos; i++) printf(" ");
    printf("#\n");
}

int main() {
    init_bricks();
    init_ball();

    while(1) {
        system("clear");
        draw_bricks();
        draw_ball();

        // move ball
        x_pos += xdir;
        y_pos += ydir;
        if(x_pos==0 || x_pos==ROWS-1) xdir *= -1;
        if(y_pos==0 || y_pos==COLS-1) ydir *= -1;

        // check for collision with bricks
        if(bricks[x_pos][y_pos]) {
            bricks[x_pos][y_pos] = 0;
            ydir *= -1;
        }

        // check for game over
        if(x_pos == ROWS-1) {
            printf("Game Over\n");
            break;
        }

        // delay
        usleep(100000);
    }

    return 0;
}