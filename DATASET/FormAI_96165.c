//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 50
#define HEIGHT 20
#define PADDLE_LEN 5
#define DELAY 100000

int kbhit(void){
   struct termios oldt, newt;
   int ch;
   int oldf;
   tcgetattr(STDIN_FILENO, &oldt);
   newt = oldt;
   newt.c_lflag &= ~(ICANON | ECHO);
   tcsetattr(STDIN_FILENO, TCSANOW, &newt);
   oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
   fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
   ch = getchar();
   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
   fcntl(STDIN_FILENO, F_SETFL, oldf);
   if(ch != EOF){
      ungetc(ch, stdin);
      return 1;
   }
   return 0;
}

int main()
{
    char level[HEIGHT][WIDTH], paddle[PADDLE_LEN] = "|||||";
    int ball_x, ball_y, ball_xd = 1, ball_yd = 1, score = 0, paddle_pos = WIDTH/2, row, col, i;
    srand(time(NULL));
    for (row = 0; row < HEIGHT; row++)
        for (col = 0; col < WIDTH; col++)
            level[row][col] = ' ';
    for (col = 0; col < WIDTH; col++) {
        level[0][col] = '-';
        level[HEIGHT-1][col] = '-';
    }
    for (row = 0; row < HEIGHT; row++) {
        level[row][0] = '|';
        level[row][WIDTH-1] = '|';
    }
    ball_x = rand() % (WIDTH-3) + 2;
    ball_y = rand() % (HEIGHT/2) + HEIGHT/2;
    while(1)
    {
        system("clear");
        level[ball_y][ball_x] = 'o';
        for (i = 0; i < PADDLE_LEN; i++)
            level[HEIGHT-2][paddle_pos+i] = paddle[i];
        for (row = 0; row < HEIGHT; row++) {
            for (col = 0; col < WIDTH; col++)
                printf("%c", level[row][col]);
            printf("\n");
        }
        printf("Score: %d\n", score);
        level[ball_y][ball_x] = ' ';
        for (i = 0; i < PADDLE_LEN; i++)
            level[HEIGHT-2][paddle_pos+i] = ' ';
        ball_x += ball_xd;
        ball_y += ball_yd;
        if (ball_x == 1 || ball_x == WIDTH-2)
            ball_xd = -ball_xd;
        if (ball_y == 1 || ball_y == HEIGHT-1) 
            ball_yd = -ball_yd;
        if (ball_y == HEIGHT-2 && ball_x >= paddle_pos && ball_x < paddle_pos+PADDLE_LEN) {
            ball_yd = -ball_yd;
            score++;
        }
        if (ball_y == HEIGHT-2 && (ball_x < paddle_pos || ball_x >= paddle_pos+PADDLE_LEN)) {
            printf("Game Over! Score: %d\n", score);
            return 0;
        }
        if (kbhit()) {
            switch(getchar()) {
                case 'a':
                    paddle_pos--;
                    if (paddle_pos < 1)
                        paddle_pos = 1;
                    break;
                case 'd':
                    paddle_pos++;
                    if (paddle_pos+PADDLE_LEN >= WIDTH-1)
                        paddle_pos = WIDTH-1-PADDLE_LEN;
                    break;
                case 'q':
                    return 0;
            }
        }
        usleep(DELAY);
    }
    return 0;
}