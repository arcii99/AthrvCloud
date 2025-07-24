//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: complete
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <termios.h> 
#include <fcntl.h> 
#include <string.h> 

#define WIDTH 30 
#define HEIGHT 20 
#define PADDLE_WIDTH 5 
#define BALL_SLEEP 80000 
#define PADDLE_SLEEP 300000 

int ball_x = WIDTH/2; 
int ball_y = 5; 
int ball_x_change = 1; 
int ball_y_change = 1; 

int paddle_x = WIDTH/2 - PADDLE_WIDTH/2; 
int paddle_y = HEIGHT - 2; 

/* function to get keyboard input */ 
int kbhit(void) { 
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
    ball_x += ball_x_change; 
    ball_y += ball_y_change; 

    /* collision with walls */ 
    if(ball_x > WIDTH || ball_x < 1) { 
        ball_x_change = -ball_x_change; 
    } 
    if(ball_y < 1) { 
        ball_y_change = -ball_y_change; 
    } 
    if(ball_y > HEIGHT - 1) { 
        printf("GAME OVER\n"); 
        exit(0); 
    } 

    /* collision with paddle */ 
    if(ball_y >= paddle_y && 
       ball_x >= paddle_x && 
       ball_x <= paddle_x + PADDLE_WIDTH) { 
        ball_y_change = -ball_y_change; 
    } 
} 

void move_paddle(int direction) { 
    if(direction == -1 && paddle_x > 1) { 
        paddle_x--; 
    } 
    if(direction == 1 && paddle_x < WIDTH - PADDLE_WIDTH - 1) { 
        paddle_x++; 
    } 
} 

int main() { 
    /* hide cursor */ 
    printf("\033[?25l"); 

    /* set terminal to raw mode */ 
    struct termios old_term, new_term; 
    tcgetattr(STDIN_FILENO, &old_term); 
    new_term = old_term; 
    cfmakeraw(&new_term); 
    tcsetattr(STDIN_FILENO, TCSANOW, &new_term); 

    /* clear screen */ 
    system("clear"); 
    /* game loop */ 
    while(1) { 
        /* clear screen */ 
        printf("\033[0;0H"); 

        /* draw paddle */ 
        printf("|"); 
        for(int i = 1; i < paddle_x; i++) { 
            printf(" "); 
        } 
        for(int i = 0; i < PADDLE_WIDTH; i++) { 
            printf("="); 
        } 
        for(int i = paddle_x + PADDLE_WIDTH; i < WIDTH - 1; i++) { 
            printf(" "); 
        } 
        printf("|\n"); 

        /* draw ball */ 
        for(int i = 0; i < ball_y; i++) { 
            printf("\n"); 
        } 
        for(int i = 0; i < ball_x; i++) { 
            printf(" "); 
        } 
        printf("o"); 
        printf("\n"); 

        /* read keyboard input */ 
        if(kbhit()) { 
            char c = getchar(); 
            if(c == 'q') { 
                /* reset terminal */ 
                tcsetattr(STDIN_FILENO, TCSANOW, &old_term); 
                printf("\033[?25h"); 
                printf("\n"); 
                exit(0); 
            } 
            if(c == 'a') { 
                move_paddle(-1); 
            } 
            if(c == 'd') { 
                move_paddle(1); 
            } 
        } 

        /* move ball */ 
        move_ball(); 

        /* sleep */ 
        usleep(BALL_SLEEP); 
        usleep(PADDLE_SLEEP); 
    } 
    return 0; 
}