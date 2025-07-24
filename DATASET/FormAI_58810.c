//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 20
#define BRICK_ROW 3
#define BRICK_COL 12

int map[ROW][COL];
typedef struct {
    int x,y;
} coordinate;

void initMap(coordinate *ball, coordinate *paddle);
void displayMap(coordinate ball, coordinate paddle);
void updateBall(coordinate *ball, coordinate *paddle);
int reverse(int num);
int isOverlap(int a1, int b1, int a2, int b2);
int isGameEnd(coordinate ball);

int main(void) {
    coordinate ball,paddle;
    initMap(&ball,&paddle);
    while(1) {
        displayMap(ball,paddle);
        updateBall(&ball,&paddle);
        if(isGameEnd(ball)) {
            printf("Game Over!\n");
            break;
        }
    }
    return 0;
}

void initMap(coordinate *ball, coordinate *paddle) {
    int i,j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            if(i==0 || j==0 || i==ROW-1 || j==COL-1) {
                map[i][j] = -1;
            } else {
                map[i][j] = 0;
            }
        }
    }
    for(i=0; i<BRICK_ROW; i++) {
        for(j=0; j<BRICK_COL; j++) {
            map[i+2][j+4] = (i+1)*10+j+1;
        }
    }
    ball->x = ROW-2;
    ball->y = COL/2;
    paddle->x = ROW-1;
    paddle->y = COL/2;
}

void displayMap(coordinate ball, coordinate paddle) {
    system("clear");
    int i,j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            if(i==ball.x && j==ball.y) {
                printf("o");
            } else if(i==paddle.x && j>=paddle.y-2 && j<=paddle.y+2) {
                printf("=");
            } else if(map[i][j]==-1) {
                printf("#");
            } else if(map[i][j]>0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void updateBall(coordinate *ball, coordinate *paddle) {
    // Move the ball
    ball->x--;
    ball->y += rand()%3-1;
    // Process the ball position and trajectory
    if(ball->y<1 || ball->y>COL-2) {
        ball->y = reverse(ball->y);
    }
    if(ball->x==paddle->x && isOverlap(ball->y,ball->y,paddle->y-2,paddle->y+2)) {
        ball->x = reverse(ball->x);
        ball->y = rand()%3-1;
    }
    if(map[ball->x][ball->y]==-1) {
        ball->x = reverse(ball->x);
    } else if(map[ball->x][ball->y]>0) {
        map[ball->x][ball->y] = 0;
        ball->x = reverse(ball->x);
    }
    // Move the paddle
    int dir = rand()%3-1;
    if(dir==0) {
        return;
    } else if(dir<0 && paddle->y>3) {
        paddle->y--;
    } else if(paddle->y<COL-4) {
        paddle->y++;
    }
}

int reverse(int num) {
    return 2*ROW-1-num;
}

int isOverlap(int a1, int b1, int a2, int b2) {
    int i;
    for(i=b1; i<=b2; i++) {
        if(i>=a1 && i<=a2) {
            return 1;
        }
    }
    return 0;
}

int isGameEnd(coordinate ball) {
    return ball.x==ROW-1;
}