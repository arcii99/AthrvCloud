//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>

// Function to get user keyboard input without waiting for a newline character
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

int main() {
    // Initialize game variables
    int score = 0;
    int lives = 3;
    int paddle_pos = 25;
    int ball_x = 39;
    int ball_y = 22;
    int ball_x_direction = -1;
    int ball_y_direction = -1;
    int bricks_remaining = 60;
    int brick_pos[60][2];
    for(int i=0; i<5; i++) {
        for(int j=0; j<12; j++) {
            brick_pos[i*12+j][0] = j*5+1;
            brick_pos[i*12+j][1] = i*2+2;
        }
    }

    // Set up terminal display
    printf("\033[2J\033[?25l\033[0;0H");

    // Loop until all bricks are destroyed or player loses all lives
    while(bricks_remaining > 0 && lives > 0) {
        // Display game status
        printf("Score: %d   Lives: %d\n", score, lives);

        // Display bricks
        for(int i=0; i<60; i++) {
            if(brick_pos[i][1] > 0) {
                printf("\033[%d;%dH\033[48;5;%dm     \033[0m", brick_pos[i][1], brick_pos[i][0], (i%6)+1);
            }
        }

        // Display paddle
        printf("\033[%d;%dH\033[48;5;12m     \033[0m", 24, paddle_pos);

        // Move ball
        ball_x += ball_x_direction;
        ball_y += ball_y_direction;

        // Check for collisions with walls, paddle, and bricks
        if(ball_x == 0 || ball_x == 79) {
            ball_x_direction *= -1;
        }
        if(ball_y == 0) {
            ball_y_direction *= -1;
        }
        if(ball_y == 23 && ball_x >= paddle_pos && ball_x <= paddle_pos+4) {
            ball_y_direction *= -1;
        }
        if(ball_y == 23 && (ball_x < paddle_pos || ball_x > paddle_pos+4)) {
            lives--;
            ball_x = 39;
            ball_y = 22;
            ball_x_direction = -1;
            ball_y_direction = -1;
            usleep(500000);
            continue;
        }
        for(int i=0; i<60; i++) {
            if(brick_pos[i][1] > 0 && ball_y == brick_pos[i][1] && ball_x >= brick_pos[i][0] && ball_x <= brick_pos[i][0]+4) {
                brick_pos[i][1] = 0;
                ball_y_direction *= -1;
                bricks_remaining--;
                score += 10;
            }
        }

        // Display ball
        printf("\033[%d;%dH\033[48;5;15m \033[0m", ball_y, ball_x);

        // Check for user keyboard input
        if(kbhit()) {
            char input = getchar();
            if(input == 'a' && paddle_pos > 1) {
                paddle_pos--;
            }
            if(input == 'd' && paddle_pos < 75) {
                paddle_pos++;
            }
        }

        // Pause for a moment
        usleep(50000);
    }

    // Display game over message
    printf("\033[?25h\033[23;0H");
    if(bricks_remaining > 0) {
        printf("Game Over!\nYou ran out of lives.\nFinal Score: %d\n", score);
    }
    else {
        printf("Congratulations!\nYou destroyed all the bricks.\nFinal Score: %d\n", score);
    }

    return 0;
}