//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

#define HEIGHT 23
#define WIDTH 79
#define PADDLE_SIZE 4
#define BALL 'O'
#define PADDLE '-'
#define BLANK ' '

int ball_x, ball_y, ball_vx, ball_vy;
int left_paddle_y, right_paddle_y;
int score_left, score_right, difficulty;
int ai_move = 1;

int kbhit() {
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
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

void move_ball() {
    ball_x += ball_vx;
    ball_y += ball_vy;

    if(ball_x <= 0 || ball_x >= WIDTH) {
        ball_vx = -ball_vx;
    }
    if(ball_y <= 0 || ball_y >= HEIGHT) {
        ball_vy = -ball_vy;
    }
}

void move_left_paddle() {
    char key = getchar();
    if(key == 'w' && left_paddle_y > 0) {
        left_paddle_y--;
    }
    else if(key == 's' && left_paddle_y < HEIGHT - PADDLE_SIZE) {
        left_paddle_y++;
    }
}

void move_right_paddle() {
    if(ai_move > 0) {
        if(right_paddle_y > ball_y) {
            right_paddle_y--;
        }
        else if(right_paddle_y < ball_y) {
            right_paddle_y++;
        }
    }
}

void check_for_collision() {
    if(ball_x == 2) {
        if(ball_y >= left_paddle_y && ball_y <= left_paddle_y + PADDLE_SIZE) {
            ball_vx = -ball_vx;
            score_left += 10;
            if(difficulty == 2) {
                ball_vy -= 2;
            }
        }
        else {
            score_right += 100;
            ball_x = WIDTH - 1;
            ball_vx = -ball_vx;
            ball_vy = rand() % 5 - 2;
            if(ball_vy == 0) {
                ball_vy = 1;
            }
        }
    }
    else if(ball_x == WIDTH - 3) {
        if(ball_y >= right_paddle_y && ball_y <= right_paddle_y + PADDLE_SIZE) {
            ball_vx = -ball_vx;
            score_right += 10;
            if(difficulty == 2) {
                ball_vy += 2;
            }
        }
        else {
            score_left += 100;
            ball_x = 1;
            ball_vx = -ball_vx;
            ball_vy = rand() % 5 - 2;
            if(ball_vy == 0) {
                ball_vy = 1;
            }
        }
    }
}

void print_score() {
    printf("\033[%d;%dH", 2, WIDTH/2 - 7);
    printf("SCORE\n");
    printf("\033[%d;%dH", 3, WIDTH/2 - 7);
    printf("%d : %d\n", score_left, score_right);
}

void print_ball() {
    printf("\033[%d;%dH%c", ball_y, ball_x, BALL);
}

void print_paddles() {
    for(int i=0; i<PADDLE_SIZE; i++) {
        printf("\033[%d;%dH%c", left_paddle_y+i, 1, PADDLE);
        printf("\033[%d;%dH%c", right_paddle_y+i, WIDTH-2, PADDLE);
    }
}

void print_border() {
    printf("\033[2J");
    for(int i=1; i < WIDTH; i++) {
        printf("\033[1;%dH_", i);
        printf("\033[%d;%dH_", HEIGHT, i);
    }
    for(int i=1; i <= HEIGHT; i++) {
        printf("\033[%d;1H|", i);
        printf("\033[%d;%dH|", i, WIDTH);
    }
}

void print_controls() {
    printf("\033[%d;%dH", HEIGHT+2, WIDTH/2 - 17);
    printf("Controls: w/s for left paddle");
}

void print_ai_difficulty() {
    printf("\033[%d;%dH", HEIGHT+4, WIDTH/2 - 18);
    printf("1-Easy, 2-Medium, 3-Hard: ");
    scanf("%d", &difficulty);
}

void sig_handler(int sig) {
    printf("\033[2J");
    printf("\033[%d;%dHGame Over", HEIGHT/2, WIDTH/2-5);
    printf("\033[%d;%dHFinal Score: %d", HEIGHT/2 + 2, WIDTH/2-8, score_left);
    exit(0);
}

void setup() {
    srand(time(NULL));
    ball_x = WIDTH/2;
    ball_y = HEIGHT/2;
    ball_vx = 1;
    ball_vy = rand() % 5 - 2;
    if(ball_vy == 0) {
        ball_vy = 1;
    }
    left_paddle_y = HEIGHT/2 - PADDLE_SIZE/2;
    right_paddle_y = HEIGHT/2 - PADDLE_SIZE/2;
    score_left = 0;
    score_right = 0;
    signal(SIGINT, sig_handler);
}

int main() {
    setup();
    print_controls();
    print_border();
    while(1) {
        if(kbhit()) {
            move_left_paddle();
        }
        move_right_paddle();
        move_ball();
        check_for_collision();
        print_border();
        print_paddles();
        print_ball();
        print_score();
        usleep(35000);
    }
    return 0;
}