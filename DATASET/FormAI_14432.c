//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define UP 'w'
#define DOWN 's'
#define BALL_SPEED 300

void printPaddle(int x, int y) {
    int i, j;
    for(i = y-2; i <= y+2; i++) {
        printf("\033[%d;%dH", i, x-1);
        for(j = x-1; j <= x+1; j++) {
            printf("\033[46m \033[0m");
        }
    }
}

void printBall(int x, int y) {
    printf("\033[%d;%dH", y, x);
    printf("\033[43m \033[0m");
}

int main() {
    char input;
    int y = HEIGHT/2, x = WIDTH/2;
    int dir_x = (rand()%2 == 0) ? 1 : -1;
    int dir_y = (rand()%2 == 0) ? 1 : -1;
    int paddle_y = HEIGHT/2;
    int ai_y = HEIGHT/2;
    int ai_score = 0;
    int player_score = 0;
    time_t start_t, end_t;
    long int diff_t;
    
    srand(time(NULL));
    system("clear");
    
    printPaddle(10, paddle_y);
    printPaddle(WIDTH-10, ai_y);
    
    printBall(x, y);
    
    while(1) {
        input = getchar();
        switch(input) {
            case UP:
                if(paddle_y > 3)
                    paddle_y--;
                break;
            case DOWN:
                if(paddle_y < HEIGHT-3)
                    paddle_y++;
                break;
            default:
                break;
        }
        printPaddle(10, paddle_y);
        
        time(&start_t);
        while(1) {
            time(&end_t);
            diff_t = (end_t - start_t) * 1000;
            if(diff_t > BALL_SPEED)
                break;
        }
        
        printf("\033[%d;%dH", y, x);
        printf(" ");
        x += dir_x;
        y += dir_y;
        if(y <= 0 || y >= HEIGHT) {
            dir_y = -dir_y;
        }
        if(x <= 11) {
            if(y >= paddle_y-2 && y <= paddle_y+2) {
                dir_x = -dir_x;
            } else {
                ai_score++;
                printf("\033[%d;%dH", HEIGHT/2, WIDTH/2-4);
                printf("\033[31mAI score!\033[0m");
                x = WIDTH/2;
                y = HEIGHT/2;
                paddle_y = HEIGHT/2;
                ai_y = HEIGHT/2;
                dir_x = (rand()%2 == 0) ? 1 : -1;
                dir_y = (rand()%2 == 0) ? 1 : -1;
                time(&start_t);
                while(1) {
                    time(&end_t);
                    diff_t = (end_t - start_t) * 1000;
                    if(diff_t > 1000)
                        break;
                }
                system("clear");
                printPaddle(10, paddle_y);
                printPaddle(WIDTH-10, ai_y);
                printBall(x, y);
                printf("\033[32mPlayer: %d\tAI: %d\033[0m", player_score, ai_score);
            }
        }
        if(x >= WIDTH-11) {
            if(y >= ai_y-2 && y <= ai_y+2) {
                dir_x = -dir_x;
            } else {
                player_score++;
                printf("\033[%d;%dH", HEIGHT/2, WIDTH/2-4);
                printf("\033[32mPlayer score!\033[0m");
                x = WIDTH/2;
                y = HEIGHT/2;
                paddle_y = HEIGHT/2;
                ai_y = HEIGHT/2;
                dir_x = (rand()%2 == 0) ? 1 : -1;
                dir_y = (rand()%2 == 0) ? 1 : -1;
                time(&start_t);
                while(1) {
                    time(&end_t);
                    diff_t = (end_t - start_t) * 1000;
                    if(diff_t > 1000)
                        break;
                }
                system("clear");
                printPaddle(10, paddle_y);
                printPaddle(WIDTH-10, ai_y);
                printBall(x, y);
                printf("\033[32mPlayer: %d\tAI: %d\033[0m", player_score, ai_score);
            }
        }
        if(y <= 2)
            ai_y--;
        else if(y >= HEIGHT-2)
            ai_y++;
        printPaddle(WIDTH-10, ai_y);
        printBall(x, y);
    }
    
    return 0;
}